//
// Created by bokoch on 21.11.17.
//

#include "./TVectorItem.h"
template <class T>
TVectorItem <T>::TVectorItem () {
    this->_item = nullptr;
}

template <class T>
TVectorItem <T>::TVectorItem (T &item) {
    this->_item = &item;
    std::cout << "TVectorItem: created" << std::endl;
}

template <class T>
TVectorItem <T>::TVectorItem (T *item) {
    this->_item = item;
    std::cout << "TVectorItem: created" << std::endl;
}

template <class T>
TAllocationBlock TVectorItem <T>::memory (sizeof(T), 1000);

template <class A>
std::ostream &operator << (std::ostream &os, const TVectorItem <A> &obj) {
    obj._item->Print();
    return os;
}

template <class T>
void *TVectorItem <T>::operator new (size_t size) {
    return memory.allocate();
}

template <class T>
void *TVectorItem <T>::operator new [](size_t count) {
    return memory.allocateSome(count);
}

template <class T>
void TVectorItem <T>::operator delete (void *p) {
    memory.deallocate(p);
}

template <class T>
void TVectorItem <T>::operator delete[] (void *p, size_t count) {
    memory.deallocateSome(p,count);
}

template <class T>
TVectorItem <T>::~TVectorItem () {
    //std::cout << "TVectorItem deleted" << std::endl;
}