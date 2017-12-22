#ifndef LAB6_TVECTORITEM_CPP
#define LAB6_TVECTORITEM_CPP
#include "./TVectorItem.h"
#include "../Figure/Figure.h"

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
    this->_value = new T(item);
    std::cout << "TVectorItem: created" << std::endl;
}

template <class T>
TAllocationBlock	//происходит только один раз, так как это единое статическое поле для всех объектов класса
TVectorItem<T>::Memory(sizeof(TVectorItem<T>), MAX_TREE_CAPACITY);

template <class A>
std::ostream &operator << (std::ostream &os, const TVectorItem <A> &obj) {
    obj._value->Print();
    return os;
}

template <class T>
void *TVectorItem <T>::operator new (size_t size) {
    return Memory.Allocate();
}


template <class T>
void TVectorItem <T>::operator delete (void *p) {
    Memory.Deallocate(p);
}

template <class T>
TVectorItem <T>::~TVectorItem () {
    if (_value)
        delete _value;
    std::cout << "TVectorItem deleted" << std::endl;
}

#endif