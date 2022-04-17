#ifndef DATA_STRUCTURE_CPP_SEQLIST_H
#define DATA_STRUCTURE_CPP_SEQLIST_H

#include "linear_list.h"
#include <cassert>
#include <cstdlib>
#include <initializer_list>

namespace container {
    template<typename elem_type>
    class seqlist : public linear_list<elem_type> {
    private:
        elem_type *_data;
        std::size_t _length, _size;
        const static std::size_t INIT_SIZE{128}, INCREMENT_SIZE{16};
    public:
        seqlist();
        seqlist(std::initializer_list<elem_type> init);
        virtual ~seqlist();
        virtual void push_front(elem_type e) override;
        virtual void push_back(elem_type e) override;
        virtual void insert(size_t pos, elem_type e) override;
        virtual elem_type erase_front() override;
        virtual elem_type erase_back() override;
        virtual elem_type erase(size_t pos) override;
        virtual const elem_type &operator[](size_t index) const override;
        virtual elem_type &operator[](size_t index) override;
        virtual std::size_t length() const override;
        virtual std::size_t capacity() const override;
    };

    template<typename elem_type>
    inline seqlist<elem_type>::seqlist():_size{INIT_SIZE}, _length{0UL}, _data{new elem_type[INIT_SIZE]} {}

    template<typename elem_type>
    seqlist<elem_type>::seqlist(std::initializer_list<elem_type> init):seqlist{} {
        for (elem_type e: init) {
            push_back(e);
        }
    }

    template<typename elem_type>
    inline seqlist<elem_type>::~seqlist() {
        delete[] _data;
    }

    template<typename elem_type>
    void seqlist<elem_type>::push_front(elem_type e) {
        insert(0, e);
    }

    template<typename elem_type>
    void seqlist<elem_type>::push_back(elem_type e) {
        insert(_length, e);
    }

    template<typename elem_type>
    void seqlist<elem_type>::insert(size_t pos, elem_type e) {
        assert(pos <= _length);
        if (_length >= _size) {
            elem_type *new_data = realloc(_data, (_size + INCREMENT_SIZE) * sizeof(elem_type));
            assert(new_data);
            _data = new_data;
            _size += INCREMENT_SIZE;
        }
        for (std::size_t i = _length; i > pos; --i) {
            _data[i] = _data[i - 1];
        }
        _data[pos] = e;
        _length += 1;
    }

    template<typename elem_type>
    elem_type seqlist<elem_type>::erase_front() {
        return erase(0);
    }

    template<typename elem_type>
    elem_type seqlist<elem_type>::erase_back() {
        return erase(_length - 1);
    }

    template<typename elem_type>
    elem_type seqlist<elem_type>::erase(size_t pos) {
        assert(pos < _length);
        elem_type deleted = _data[pos];
        for (std::size_t i = pos; i < _length; ++i) {
            _data[i] = _data[i + 1];
        }
        _length -= 1;
        return deleted;
    }

    template<typename elem_type>
    const elem_type &seqlist<elem_type>::operator[](size_t index) const {
        assert(index < _length);
        return _data[index];
    }

    template<typename elem_type>
    elem_type &seqlist<elem_type>::operator[](size_t index) {
        return const_cast<elem_type &>(static_cast<const seqlist<elem_type> *>(this)->operator[](index));
    }

    template<typename elem_type>
    std::size_t seqlist<elem_type>::length() const {
        return _length;
    }

    template<typename elem_type>
    std::size_t seqlist<elem_type>::capacity() const {
        return _size;
    }
}

#endif //DATA_STRUCTURE_CPP_SEQLIST_H
