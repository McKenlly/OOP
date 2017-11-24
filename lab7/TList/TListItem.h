
#ifndef LAB6_TLISTITEM_H
#define LAB6_TLISTITEM_H
#include <iostream>
#include <memory>

template <class T>
class TListItem {
    //friend class TList<T>;
public:
    explicit TListItem();
    explicit TListItem(T *);
    std::shared_ptr<TListItem<T>> GetNext();
    std::shared_ptr<T> GetValue();
    void Destroy();
    void SetNext(std::shared_ptr<TListItem<T>> item);
//    void SetPrev(std::shared_ptr<TListItem<T>> item);
    virtual ~TListItem() {
    }
private:
//    std::shared_ptr<T> item;
    std::shared_ptr<T> item;
    std::shared_ptr<TListItem<T>> next;
//    std::shared_ptr<TListItem<T>> prev;
};

#include "TListItem.cpp"
#endif //LAB6_TLISTITEM_H
