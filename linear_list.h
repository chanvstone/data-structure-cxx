//
// Created by sio2 on 4/13/22.
//

#ifndef DATA_STRUCTURE_CXX_LINEAR_LIST_H
#define DATA_STRUCTURE_CXX_LINEAR_LIST_H

namespace container {
    using size_t = unsigned long;

    template<typename elem_type>
    class linear_list {
    public:
        virtual void push_front(elem_type e) = 0;
        virtual void push_back(elem_type e) = 0;
        virtual void insert(size_t pos, elem_type e) = 0;
        virtual elem_type erase_front() = 0;
        virtual elem_type erase_back() = 0;
        virtual elem_type erase(size_t pos) = 0;
        virtual const elem_type &operator[](size_t index) const = 0;
        virtual elem_type &operator[](size_t index) = 0;
        virtual size_t length() const = 0;
        virtual size_t capacity() const = 0;
    };
}


#endif //DATA_STRUCTURE_CXX_LINEAR_LIST_H
