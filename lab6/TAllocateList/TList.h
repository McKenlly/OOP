
#ifndef LAB6_TLIST_H
#define LAB6_TLIST_H
#include "TListItem.h"

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
#include "TList.cpp"
#endif //LAB6_TLIST_H
