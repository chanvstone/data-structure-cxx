#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_ 1

#include <functional>
#include <initializer_list>
#include <map>
#include <memory>
#include <stdexcept>

namespace polynomial
{
    //单个项
    class term
    {
    public:
        double factor;   //系数
        double exponent; //指数

    public:
        term(double factor = 0.0, double exponent = 0.0)
            : factor{factor}, exponent{exponent} {}

        term operator+(const term &t) const;
        term &operator+=(const term &t);

        term operator-(const term &t) const;
        term &operator-=(const term &t);

        term operator*(const double d) const;
        term &operator*=(const double d);
        friend term operator*(double d, const term &t);
        term operator*(const term &t) const;
        term &operator*=(const term &t);

        term operator/(const double d) const;
        term &operator/=(const double d);
        friend term operator/(double d, const term &t);
        term operator/(const term &t) const;
        term &operator/=(const term &t);
    };

    //多项式
    class polynomial
    {
    private:
        std::map<double, term> terms;

    public:
        polynomial() {}
        polynomial(std::initializer_list<term> init);
        polynomial(const polynomial &p);
        polynomial(polynomial &&p);

        bool traverse(std::function<bool(const term &)> visit) const;
        bool traverse(std::function<bool(term &)> visit);

        polynomial operator+(const term &t) const;
        polynomial &operator+=(const term &t);
        polynomial operator+(const polynomial &p) const;
        polynomial &operator+=(const polynomial &p);

        // polynomial operator-(const term &t) const;
        // polynomial &operator-=(const term &t);
        // polynomial operator-(const polynomial &p) const;
        // polynomial &operator-=(const polynomial &p);

        polynomial operator*(const term &t) const;
        polynomial &operator*=(const term &t);
        polynomial operator*(const polynomial &p) const;
        polynomial &operator*=(const polynomial &p);

        // polynomial operator/(const term &t) const;
        // polynomial &operator/=(const term &t);
        // polynomial operator/(const polynomial &p) const;
        // polynomial &operator/=(const polynomial &p);

        //返回指数与exponent相等的项的系数
        double factor_of(const double exponent) const;
    };
} // namespace polynomial

#endif // _POLYNOMIAL_H_