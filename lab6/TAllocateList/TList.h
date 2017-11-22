//
// Created by bokoch on 21.11.17.
//

#ifndef LAB6_TLIST_H
#define LAB6_TLIST_H

#include "TListItem.cpp"

template <class T>
class TList {
private:
    TListItem<T> *_head;
    TListItem<T> *_tail;
    size_t _size;
public:
    TList();
    virtual ~TList();
    void PushBack(T& item);
    bool IsEmpty();
    void PopFront();
    size_t size() const;
    T& Front();
    T& Back();

};

typedef unsigned char Byte;

template class
TListItem<void *>;
#endif //LAB6_TLIST_H
