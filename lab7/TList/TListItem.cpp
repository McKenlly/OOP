#ifndef LAB6_TLISTITEM_CPP
#define LAB6_TLISTITEM_CPP

#include "TListItem.h"

template <class T>
TListItem<T>::TListItem() {
    item = nullptr;
    next = nullptr;
}

template <class T>
TListItem<T>::TListItem(T* obj) {
    this->item = std::shared_ptr<T>(obj);
    this->next = nullptr;
}
template <class T>
std::shared_ptr<T> TListItem<T>::GetValue() {
    return item;
}
template <class T>
std::shared_ptr<TListItem<T>> TListItem<T>::GetNext() {
    return this->next;
}

template <class T>
void TListItem<T>::SetNext(std::shared_ptr<TListItem<T>> item) {
    this->next = item;
    //std::shared_ptr<TListItem<T>> p = this->;
    //item->SetPrev(p);
}

//template <class T>
//void TListItem<T>::SetPrev(std::shared_ptr<TListItem<T>> item) {
//    this->prev = item;
//}

template <class T>
void TListItem<T>::Destroy() {
    //delete item;
}
#endif