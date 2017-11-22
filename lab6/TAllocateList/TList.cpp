#include "TList.h"

template <class T>
TList<T>::TList() {
    _head = nullptr;
    _tail = nullptr;
    _size = 0;
}
template <class T>
TList<T>::~TList() {
    TListItem<T> *tmp = _head, *tmp2;
    while (tmp != nullptr) {
        tmp2 = &tmp->GetNext();
        delete tmp;
        tmp = tmp2;
    }
}

template <class T>
bool TList<T>::IsEmpty() {
    return _size == 0;
}
template <class T>
size_t TList<T>::size() const{
    return _size;
}
template <class T>
void TList<T>::PushBack(T& value){
    if (_head == nullptr) {
        _head = new TListItem<T>(&value);
        _tail = _head;
    } else {
        TListItem<T> *newNode = new TListItem<T>(&value);
        _tail->SetNext(newNode);
        _tail = newNode;
    }
    _size++;
}
template <class T>
T& TList<T>::Front() {
    return _head->GetValue();
}
template<typename T>
T& TList<T>::Back() {
    return _tail->GetValue();
}
template<typename T>
void TList<T>::PopFront() {
    if (!this->IsEmpty()) {
        TListItem<T> *tmp = _head;
        _head = &_head->GetNext();
        delete tmp;
        if (_size == 1) {
            delete _tail;
        }
        _size--;
    }
}
//void TList<T>::PopBack() {
//    if (this->IsEmpty() != 0) {
//        _head = _head->next;
//        _size--;
//    }
//}