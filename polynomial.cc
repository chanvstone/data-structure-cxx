#include "polynomial.h"
#include <vector>

namespace polynomial {

// 检查指数是否相等，不相等则抛出异常
#define CHECK_EXPONENT(EXP1, EXP2) \
    if (EXP1 != EXP2)              \
    throw std::invalid_argument("have different exponent")

    term term::operator+(const term &t) const {
        CHECK_EXPONENT(exponent, t.exponent);
        return {factor + t.factor, exponent};
    }
    term &term::operator+=(const term &t) {
        CHECK_EXPONENT(exponent, t.exponent);
        factor += t.factor;
        return *this;
    }

    term term::operator-(const term &t) const {
        CHECK_EXPONENT(exponent, t.exponent);
        return {factor - t.factor, exponent};
    }
    term &term::operator-=(const term &t) {
        CHECK_EXPONENT(exponent, t.exponent);
        factor -= t.factor;
        return *this;
    }

    term term::operator*(const double d) const {
        return {factor * d, exponent};
    }
    term &term::operator*=(const double d) {
        factor *= d;
        return *this;
    }
    term operator*(double d, const term &t) {
        return {d * t.factor, t.exponent};
    }
    term term::operator*(const term &t) const {
        return {factor * t.factor, exponent + t.exponent};
    }
    term &term::operator*=(const term &t) {
        factor *= t.factor;
        exponent += t.exponent;
        return *this;
    }

    term term::operator/(const double d) const {
        return {factor / d, exponent};
    }
    term &term::operator/=(const double d) {
        factor /= d;
        return *this;
    }
    term operator/(double d, const term &t) {
        return {d / t.factor, -1.0 * t.exponent};
    }
    term term::operator/(const term &t) const {
        return {factor / t.factor, exponent - t.exponent};
    }
    term &term::operator/=(const term &t) {
        factor /= t.factor;
        exponent -= t.exponent;
        return *this;
    }

    polynomial::polynomial(std::initializer_list<term> init) : polynomial{} {
        for (auto i: init) {
            (*this) += i;
        }
    }
    polynomial::polynomial(const polynomial &p) {
        for (auto item: p.terms) {
            terms.insert(item);
        }
    }
    polynomial::polynomial(polynomial &&p) : polynomial{p} {
        p.terms.clear();
    }
    bool polynomial::traverse(std::function<bool(const term &)> visit) const {
        for (auto item: terms) {
            if (!visit(item.second)) {
                return false;
            }
        }
        return true;
    }
    bool polynomial::traverse(std::function<bool(term &)> visit) {
        for (auto &item: terms) {
            if (!visit(item.second)) {
                return false;
            }
        }
        return true;
    }

    polynomial polynomial::operator+(const term &t) const {
        polynomial new_polynomial(*this);
        new_polynomial += t;
        return new_polynomial;
    }
    polynomial &polynomial::operator+=(const term &t) {
        if (terms.contains(t.exponent)) {
            terms[t.exponent] += t;
        } else if (t.factor != 0.0) {
            terms.insert({t.exponent, t});
        }
        return *this;
    }
    polynomial polynomial::operator+(const polynomial &p) const {
        polynomial new_polynomial{*this};
        new_polynomial += p;
        return new_polynomial;
    }
    polynomial &polynomial::operator+=(const polynomial &p) {
        for (auto item: p.terms) {
            (*this) += item.second;
        }
        return *this;
    }

    polynomial polynomial::operator*(const term &t) const {
        polynomial new_polynomial{*this};
        new_polynomial *= t;
        return new_polynomial;
    }
    polynomial &polynomial::operator*=(const term &t) {
        std::map<double, term> new_terms;
        for (auto &item: terms) {
            term new_term = item.second * t;
            new_terms.insert({new_term.exponent, new_term});
        }
        terms = new_terms;
        return *this;
    }
    polynomial polynomial::operator*(const polynomial &p) const {
        polynomial new_polynomial{*this};
        new_polynomial *= p;
        return new_polynomial;
    }
    polynomial &polynomial::operator*=(const polynomial &p) {
        std::vector<polynomial> results;
        for (auto item: p.terms) {
            results.push_back((*this) * item.second);
        }
        terms.clear();
        for (auto item: results) {
            (*this) += item;
        }
        return *this;
    }

} // namespace polynomial