
#ifndef LAB6_TLIST_H
#define LAB6_TLIST_H
#include "TListItem.h"
#include "TIteratorList.h"

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
    TIteratorList<TListItem<T> > begin();
    TIteratorList<TListItem<T> > end();
    size_t size() const;
    T& Front();
    T& Back();

};

#include "TList.cpp"
#endif //LAB6_TLIST_H
