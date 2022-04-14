#ifndef DATA_STRUCTURE_CXX_SEQLIST_H
#define DATA_STRUCTURE_CXX_SEQLIST_H

#include "linear_list.h"
#include <memory>
#include <initializer_list>

namespace container {
    template<typename elem_type>
    class seqlist : public linear_list<elem_type> {
    private:
        std::shared_ptr<elem_type[]> _data;
        size_t _length, _size;
        const size_t INIT_SIZE = 128, INCREMENT_SIZE = 16;
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
        virtual size_t length() const override;
        virtual size_t capacity() const override;
    };

    template<typename elem_type>
    seqlist<elem_type>::seqlist():_size{INIT_SIZE}, _length{0UL}, _data{std::make_shared<elem_type[]>(INIT_SIZE)} {}
    template<typename elem_type>
    seqlist<elem_type>::seqlist(std::initializer_list<elem_type> init):seqlist{} {
        for (elem_type e: init) {
            push_back(e);
        }
    }
    template<typename elem_type>
    seqlist<elem_type>::~seqlist() {

    }
    template<typename elem_type>
    void seqlist<elem_type>::push_front(elem_type e) {

    }
    template<typename elem_type>
    void seqlist<elem_type>::push_back(elem_type e) {

    }
    template<typename elem_type>
    void seqlist<elem_type>::insert(size_t pos, elem_type e) {
    }
    template<typename elem_type>
    elem_type seqlist<elem_type>::erase_front() {
        return nullptr;
    }
    template<typename elem_type>
    elem_type seqlist<elem_type>::erase_back() {
        return nullptr;
    }
    template<typename elem_type>
    elem_type seqlist<elem_type>::erase(size_t pos) {
        return nullptr;
    }
    template<typename elem_type>
    const elem_type &seqlist<elem_type>::operator[](size_t index) const {
        return;
    }
    template<typename elem_type>
    elem_type &seqlist<elem_type>::operator[](size_t index) {
        return;
    }
    template<typename elem_type>
    size_t seqlist<elem_type>::length() const {
        return 0;
    }
    template<typename elem_type>
    size_t seqlist<elem_type>::capacity() const {
        return 0;
    }
}

#endif //DATA_STRUCTURE_CXX_SEQLIST_H
