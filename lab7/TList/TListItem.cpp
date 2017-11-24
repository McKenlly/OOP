#ifndef LAB6_TLISTITEM_CPP
#define LAB6_TLISTITEM_CPP

#include "TListItem.h"

template <class T>
TListItem<T>::TListItem() {
    item = nullptr;
    next = nullptr;
}

template <class T>
TListItem<T>::TListItem(T& obj) {
    this->item =  std::move(&obj);
//    this->item = std::make_shared<T>(obj);
    this->next = nullptr;
}
template <class T>
T& TListItem<T>::GetValue() {
    return *item;
}
template <class T>
TListItem<T>* TListItem<T>::GetNext() {
    return this->next;
}

template <class T>
void TListItem<T>::SetNext(TListItem<T>* item) {
    this->next = item;
}
template <class T>
void TListItem<T>::Destroy() {
    delete item;
    item = nullptr;
    if (next) {
        next->Destroy();
        next = nullptr;
    }
    delete(this);
}
#endif