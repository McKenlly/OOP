
#ifndef LAB6_TLIST_H
#define LAB6_TLIST_H
#include "TListItem.h"
#include "TIteratorList.h"
#include "/home/bokoch/CLionProjects/OOP/lab7/Figure/Square.h"
#include "/home/bokoch/CLionProjects/OOP/lab7/Figure/Rectangle.h"
#include "/home/bokoch/CLionProjects/OOP/lab7/Figure/Trapezoid.h"
template <class T>
class TList {
private:
    TListItem<T> *_head;
    TListItem<T> *_tail;
    size_t _size;
public:
    TList();
    virtual ~TList();
    TList(TList<T> &);
    void PushBack(T&);
    bool IsEmpty();
    void PopFront();

    TList& operator=(const TList &);
    void Destroy();
    TIteratorList<TListItem<T> > begin();
    TIteratorList<TListItem<T> > end();
    size_t size() const;
    T& Front();
    T& Back();

};

#include "TList.cpp"
#endif //LAB6_TLIST_H
