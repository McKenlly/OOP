#ifndef LAB6_TITERATOR_LIST_CPP
#define LAB6_TITERATOR_LIST_CPP
#include "TIteratorList.h"

template <class T>
TIteratorList<T>::TIteratorList(T *value) {
    _value = value;
}

template <class T>
T & TIteratorList<T>::operator*() {
    return *_value;
}

template <class T>
T & TIteratorList<T>::operator->() {
    return *_value;
}

template <class T>
void TIteratorList<T>::operator++() {
    _value = _value->GetNext();
}

/*template <class T>
void TIteratorList<T>::operator--() {
    _value->GetPrev;
}*/
template <class T>
TIteratorList<T>& TIteratorList<T>::operator++(int) {
    TIteratorList<T> *tmp = this;
    this->_value = this->_value->GetNext();
    return *tmp;
}
/*
template <class T>
TIteratorList<T>& TIteratorList<T>::operator--(int) {
    TIteratorList<T> *tmp = this;
    --(*this);
    return *tmp;
}*/

template <class T>
bool TIteratorList<T>::operator==(const TIteratorList &i) const{
    return this->_value == i._value;
}

template <class T>
bool TIteratorList<T>::operator!=(const TIteratorList &i) const{
    return !(this->_value == i._value);
}
#endif