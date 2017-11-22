
#ifndef LAB6_TLISTITEM_H
#define LAB6_TLISTITEM_H
#include <iostream>
template <class T>
class TListItem {
public:
    explicit TListItem();
    explicit TListItem(T *obj);
   // T GetFigure() const;
    TListItem<T>& GetNext();
    T& GetValue();
    void SetNext(TListItem<T>* item);
    virtual ~TListItem() {
        delete item;
    }
private:
    //friend class TList<T>;
    T *item;
    TListItem<T> *next;
};

#include "TListItem.cpp"
#endif //LAB6_TLISTITEM_H
