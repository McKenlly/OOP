#ifndef LAB6_TVECTORITEM_CPP
#define LAB6_TVECTORITEM_CPP
#include "./TVectorItem.h"
template <class T>
TVectorItem <T>::TVectorItem () {
    this->_value = nullptr;
}

template <class T>
TVectorItem <T>::TVectorItem (T &item) {
    this->_value = &item;
    std::cout << "TVectorItem: created" << std::endl;
}

template <class T>
TVectorItem <T>::TVectorItem (T *item) {
    this->_value = item;
    std::cout << "TVectorItem: created" << std::endl;
}

template <class T>
TAllocationBlock TVectorItem <T>::Memory (16, 1000);

template <class A>
std::ostream &operator << (std::ostream &os, const TVectorItem <A> &obj) {
    obj._value->Print();
    return os;
}

template <class T>
void *TVectorItem <T>::operator new (size_t size) {
    return Memory.allocate();
}

/*template <class T>
void *TVectorItem <T>::operator new [](size_t count) {
    return memory.allocateSome(count);
}*/

template <class T>
void TVectorItem <T>::operator delete (void *p) {
    if (Memory.Find(p))
        Memory.deallocate(p);
}
/*
template <class T>
void TVectorItem <T>::operator delete[] (void *p, size_t count) {
    memory.deallocateSome(p,count);
}*/

template <class T>
TVectorItem <T>::~TVectorItem () {
    delete _value;
    std::cout << "TVectorItem deleted" << std::endl;
}

#endif