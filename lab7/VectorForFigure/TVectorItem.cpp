#ifndef LAB6_TVECTORITEM_CPP
#define LAB6_TVECTORITEM_CPP
#include "./TVectorItem.h"


template <class T>
const size_t TVectorItem <T>::SIZE_ARRAY_FOR_ALLOCATOR = 10;

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
TAllocationBlock TVectorItem <T>::Memory (16, 10);

template <class A>
std::ostream &operator << (std::ostream &os, const TVectorItem <A> &obj) {
    obj._value->Print();
    return os;
}

template <class T>
void *TVectorItem <T>::operator new (size_t size) {
    return Memory.allocate();
}

template <class T>
T& TVectorItem<T>::operator * () {
    return *_value;
}

template <class T>
T& TVectorItem<T>::GetFigure() {
    return *_value;
}

template <class T>
void TVectorItem<T>::operator delete (void *p) {
    std::cout << "Operator delete:\n";
    if (Memory.Find(p))
        Memory.deallocate(p);
}

template <class T>
TVectorItem <T>::~TVectorItem () {
    delete _value;
    std::cout << "TVectorItem deleted" << std::endl;
}

#endif