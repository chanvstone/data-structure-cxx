#ifndef DATA_STRUCTURE_CPP_LINEAR_LIST_H
#define DATA_STRUCTURE_CPP_LINEAR_LIST_H

#include <cstddef>

namespace container {
    template<typename elem_type>
    class linear_list {
    public:
        virtual void push_front(elem_type e) = 0;
        virtual void push_back(elem_type e) = 0;
        virtual void insert(std::size_t pos, elem_type e) = 0;
        virtual elem_type erase_front() = 0;
        virtual elem_type erase_back() = 0;
        virtual elem_type erase(std::size_t pos) = 0;
        virtual const elem_type &operator[](std::size_t index) const = 0;
        virtual elem_type &operator[](std::size_t index) = 0;
        virtual std::size_t length() const = 0;
        virtual std::size_t capacity() const = 0;
    };
}

#endif //DATA_STRUCTURE_CPP_LINEAR_LIST_H
