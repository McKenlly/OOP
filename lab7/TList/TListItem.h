
#ifndef LAB6_TLISTITEM_H
#define LAB6_TLISTITEM_H
#include <iostream>
#include <memory>
template <class T>
class TListItem {
public:
    explicit TListItem();
    explicit TListItem(T *obj);
    TListItem<T>* GetNext();
    T& GetValue();
    void SetNext(TListItem<T>* item);
    virtual ~TListItem() {
    }
private:
    std::shared_ptr<T> item;
    TListItem<T> *next;
};

#include "TListItem.cpp"
#endif //LAB6_TLISTITEM_H
