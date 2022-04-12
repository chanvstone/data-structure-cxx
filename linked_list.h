#ifndef DATA_STRUCTURE_CXX_LINKED_LIST_H
#define DATA_STRUCTURE_CXX_LINKED_LIST_H

#include <memory>
#include <cassert>
#include <stdexcept>
#include <initializer_list>


namespace container {
    template<typename elem_type>
    class node {
    public:
        elem_type data;
        std::shared_ptr<node> next, prev;
        node(elem_type e = nullptr, std::shared_ptr<node> prev = nullptr, std::shared_ptr<node> next = nullptr);
    };

    template<typename elem_type>
    node<elem_type>::node(elem_type e, std::shared_ptr<node> prev, std::shared_ptr<node> next)
            :data{e}, prev{prev}, next{next} {}

    template<typename elem_type>
    class linked_list {
    private:
        std::shared_ptr<node<elem_type>> first, last;
        std::size_t length;
    public:
        linked_list();
        linked_list(std::initializer_list<elem_type> init);
        void push_front(elem_type e);
        void push_back(elem_type e);
        void insert(std::size_t pos, elem_type e);
        elem_type erase_front();
        elem_type erase_back();
        elem_type erase(std::size_t pos);
        const elem_type &operator[](std::size_t index) const;
        elem_type &operator[](std::size_t index);
        const elem_type &operator[](const elem_type &e) const;
        elem_type &operator[](const elem_type &e);
    };

    template<typename elem_type>
    linked_list<elem_type>::linked_list():first{nullptr}, last{nullptr}, length{0} {}
    template<typename elem_type>
    linked_list<elem_type>::linked_list(std::initializer_list<elem_type> init):linked_list{} {
        for (elem_type e: init) {
            push_back(e);
        }
    }
    template<typename elem_type>
    void linked_list<elem_type>::push_front(elem_type e) {
        std::shared_ptr<node<elem_type>> new_node = std::make_shared<node<elem_type>>(e, nullptr, first);
        if (length == 0) {
            first = last = new_node;
        } else {
            first->prev = new_node;
            first = new_node;
        }
        length += 1UL;
    }
    template<typename elem_type>
    void linked_list<elem_type>::push_back(elem_type e) {
        std::shared_ptr<node<elem_type>> new_node = std::make_shared<node<elem_type>>(e, last, nullptr);
        if (length == 0) {
            first = last = new_node;
        } else {
            last->next = new_node;
            last = new_node;
        }
        length += 1UL;
    }
    template<typename elem_type>
    void linked_list<elem_type>::insert(std::size_t pos, elem_type e) {
        assert(pos <= length);
        if (pos == 0) {
            push_front(e);
        } else if (pos == length) {
            push_back(e);
        } else {
            std::shared_ptr<node<elem_type>> be_inserted_node = (*this)[pos];
            std::shared_ptr<node<elem_type>> new_node = std::make_shared<node>({e, be_inserted_node->prev, be_inserted_node});
            new_node->prev->next = new_node;
            new_node->next->prev = new_node;
            length += 1UL;
        }
    }
    template<typename elem_type>
    elem_type linked_list<elem_type>::erase_front() {
        std::shared_ptr<node<elem_type>> erased = first;
        first = first->next;
        first->prev = nullptr;
        return erased->data;
    }
    template<typename elem_type>
    elem_type linked_list<elem_type>::erase_back() {
        std::shared_ptr<node<elem_type>> erased = last;
        last = last->prev;
        last->next = nullptr;
        return erased->data;
    }
    template<typename elem_type>
    elem_type linked_list<elem_type>::erase(std::size_t pos) {
        assert(pos < length);
        if (pos == 0) {
            return erase_front();
        } else if (pos == length - 1) {
            return erase_back();
        }
        std::shared_ptr<node<elem_type>> will_be_erased = (*this)[pos];
        will_be_erased->prev->next = will_be_erased->next;
        will_be_erased->next->prev = will_be_erased->prev;
        return will_be_erased->data;
    }
    template<typename elem_type>
    const elem_type &linked_list<elem_type>::operator[](std::size_t index) const {
        assert(index < length);
        std::shared_ptr<node<elem_type>> seek_for;
        if (index < (length / 2)) {
            seek_for = first;
            for (std::size_t i = 0; i < index; ++i) {
                seek_for = seek_for->next;
            }
        } else {
            seek_for = last;
            for (std::size_t i = length - 1UL; i > index; --i) {
                seek_for = seek_for->prev;
            }
        }
        return seek_for->data;
    }
    template<typename elem_type>
    elem_type &linked_list<elem_type>::operator[](std::size_t index) {
        return const_cast<elem_type &>(static_cast<const linked_list>(*this)[index]);
    }
    template<typename elem_type>
    const elem_type &linked_list<elem_type>::operator[](const elem_type &e) const {
        assert(length > 0UL);
        std::shared_ptr<node<elem_type>> seek_for = first;
        for (std::size_t i = 0UL; i < length; ++i) {
            if (seek_for->data == e) {
                return seek_for->data;
            }
            seek_for = seek_for->next;
        }
        assert(false);
    }
    template<typename elem_type>
    elem_type &linked_list<elem_type>::operator[](const elem_type &e) {
        return const_cast<elem_type &>(static_cast<const linked_list>(*this)[e]);
    }
}

#endif //DATA_STRUCTURE_CXX_LINKED_LIST_H
