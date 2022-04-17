#ifndef DATA_STRUCTURE_CPP_LINKED_LIST_H
#define DATA_STRUCTURE_CPP_LINKED_LIST_H

#include "linear_list.h"
#include <memory>
#include <cassert>
#include <stdexcept>
#include <initializer_list>

namespace container {
    template<typename elem_type>
    class node {
    public:
        elem_type data;
        node *next, *prev;

        node(elem_type e, node<elem_type> *prev = nullptr, node<elem_type> *next = nullptr) : data{e}, prev{prev},
                                                                                              next{next} {};
    };

    template<typename elem_type>
    class linked_list : public linear_list<elem_type> {
    private:
        node<elem_type> *first, *last;
        std::size_t _length;
    public:
        linked_list();
        linked_list(std::initializer_list<elem_type> init);
        ~linked_list();
        virtual void push_front(elem_type e) override;
        virtual void push_back(elem_type e) override;
        virtual void insert(std::size_t pos, elem_type e) override;
        virtual elem_type erase_front() override;
        virtual elem_type erase_back() override;
        virtual elem_type erase(std::size_t pos) override;
        virtual const elem_type &operator[](std::size_t index) const override;
        virtual elem_type &operator[](std::size_t index) override;
        virtual size_t length() const override;
        size_t capacity() const override;
    private:
        const node<elem_type> *find_node(std::size_t pos) const;
        node<elem_type> *find_node(std::size_t pos);
    };

    template<typename elem_type>
    linked_list<elem_type>::linked_list():first{nullptr}, last{nullptr}, _length{0UL} {}

    template<typename elem_type>
    linked_list<elem_type>::linked_list(std::initializer_list<elem_type> init):linked_list{} {
        for (elem_type e: init) {
            push_back(e);
        }
    }

    template<typename elem_type>
    linked_list<elem_type>::~linked_list() {
        node<elem_type> *temp;
        while (first != nullptr && first != last) {
            temp = first;
            first = first->next;
            delete temp;
        }
    }

    template<typename elem_type>
    void linked_list<elem_type>::push_front(elem_type e) {
        node<elem_type> *new_node = new node<elem_type>{e, nullptr, first};
        if (_length == 0) {
            first = last = new_node;
        } else {
            first->prev = new_node;
            first = new_node;
        }
        _length += 1UL;
    }

    template<typename elem_type>
    void linked_list<elem_type>::push_back(elem_type e) {
        node<elem_type> *new_node = new node<elem_type>{e, last, nullptr};
        if (_length == 0) {
            first = last = new_node;
        } else {
            last->next = new_node;
            last = new_node;
        }
        _length += 1UL;
    }

    template<typename elem_type>
    void linked_list<elem_type>::insert(std::size_t pos, elem_type e) {
        assert(pos <= _length);
        if (pos == 0) {
            push_front(e);
        } else if (pos == _length) {
            push_back(e);
        } else {
            node<elem_type> *be_inserted_node = find_node(pos);
            node<elem_type> *new_node = new node<elem_type>{e, be_inserted_node->prev, be_inserted_node};
            new_node->prev->next = new_node;
            new_node->next->prev = new_node;
            _length += 1UL;
        }
    }

    template<typename elem_type>
    elem_type linked_list<elem_type>::erase_front() {
        node<elem_type> *erased = first;
        first = first->next;
        first->prev = nullptr;
        return erased->data;
    }

    template<typename elem_type>
    elem_type linked_list<elem_type>::erase_back() {
        node<elem_type> *erased = last;
        last = last->prev;
        last->next = nullptr;
        return erased->data;
    }

    template<typename elem_type>
    elem_type linked_list<elem_type>::erase(std::size_t pos) {
        assert(pos < _length);
        if (pos == 0) {
            return erase_front();
        } else if (pos == _length - 1) {
            return erase_back();
        }
        node<elem_type> *will_be_erased = find_node(pos);
        will_be_erased->prev->next = will_be_erased->next;
        will_be_erased->next->prev = will_be_erased->prev;
        return will_be_erased->data;
    }

    template<typename elem_type>
    const elem_type &linked_list<elem_type>::operator[](std::size_t index) const {
        assert(index < _length);
        return find_node(index)->data;
    }

    template<typename elem_type>
    elem_type &linked_list<elem_type>::operator[](std::size_t index) {
        assert(index < _length);
        return const_cast<elem_type &>(static_cast<const linked_list<elem_type> *>(this)->operator[](index));
    }

    template<typename elem_type>
    size_t linked_list<elem_type>::length() const {
        return _length;
    }

    template<typename elem_type>
    size_t linked_list<elem_type>::capacity() const {
        return 0UL;
    }

    template<typename elem_type>
    const node<elem_type> *linked_list<elem_type>::find_node(std::size_t pos) const {
        node<elem_type> *seek_for;
        if (pos < (_length / 2)) {
            seek_for = first;
            for (std::size_t i = 0; i < pos; ++i) {
                seek_for = seek_for->next;
            }
        } else {
            seek_for = last;
            for (std::size_t i = _length - 1UL; i > pos; --i) {
                seek_for = seek_for->prev;
            }
        }
        return seek_for;
    }

    template<typename elem_type>
    node<elem_type> *linked_list<elem_type>::find_node(std::size_t pos) {
        return const_cast<node<elem_type> *>(static_cast<const linked_list<elem_type> *>(this)->find_node(pos));
    }
}

#endif //DATA_STRUCTURE_CPP_LINKED_LIST_H
