#ifndef LAB6_TITERATOR_LIST_CPP
#define LAB6_TITERATOR_LIST_CPP
#include "TIteratorList.h"

template <class T>
TIterator<T>::TIterator(T *value) {
    _value = value;
}

template <class T>
T & TIterator<T>::operator*() {
    return *_value;
}

template <class T>
T & TIterator<T>::operator->() {
    return *_value;
}

template <class T>
void TIterator<T>::operator++() {
    _value = _value->GetNext();
}
    
/*template <class T>
void TIterator<T>::operator--() {
    _value->GetPrev;
}*/
template <class T>
TIterator<T>& TIterator<T>::operator++(int) {
    TIterator<T> *tmp = this;
    this->_value = this->_value->GetNext();
    return *tmp;
}
/*
template <class T>
TIterator<T>& TIterator<T>::operator--(int) {
    TIterator<T> *tmp = this;
    --(*this);
    return *tmp;
}*/

template <class T>
bool TIterator<T>::operator==(const TIterator &i) const{
    return this->_value == i._value;
}

template <class T>
bool TIterator<T>::operator!=(const TIterator &i) const{
    return !(this->_value == i._value);
}
#endif