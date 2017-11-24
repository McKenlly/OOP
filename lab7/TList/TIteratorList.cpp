#ifndef LAB6_TITERATOR_LIST_CPP
#define LAB6_TITERATOR_LIST_CPP
#include "TIteratorList.h"

template <class node, class T>
std::shared_ptr<T> TIteratorList<node, T>::operator*() {
    return _value->GetValue();
}

template <class node, class T>
TIteratorList<node, T>::TIteratorList(std::shared_ptr<node> value) {
    _value = value;
}

template <class node, class T>
std::shared_ptr<T> TIteratorList<node, T>::operator->() {
    return _value->GetValue();
}

template <class node, class T>
void TIteratorList<node, T>::operator++() {
    _value = _value->GetNext();
}

/*template <class node, class T>
void TIteratorList<T>::operator--() {
    _value->GetPrev;
}*/
template <class node, class T>
TIteratorList<node, T> TIteratorList<node, T>::operator++(int) {
    TIteratorList<node, T> tmp(*this);
    this->_value = this->_value->GetNext();
    return *tmp;
}
/*
template <class node, class T>
TIteratorList<T>& TIteratorList<T>::operator--(int) {
    TIteratorList<T> *tmp = this;
    --(*this);
    return *tmp;
}*/

template <class node, class T>
bool TIteratorList<node, T>::operator==(const TIteratorList &i) const{
    return this->_value == i._value;
}

template <class node, class T>
bool TIteratorList<node, T>::operator!=(const TIteratorList &i) const{
    return !(this->_value == i._value);
}
#endif