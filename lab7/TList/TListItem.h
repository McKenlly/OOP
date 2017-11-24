
#ifndef LAB6_TLISTITEM_H
#define LAB6_TLISTITEM_H
#include <iostream>
#include <memory>

template <class T>
class TListItem {
    //friend class TList<T>;
public:
    explicit TListItem();
    explicit TListItem(T&);
    TListItem<T>* GetNext();
    T& GetValue();
    void Destroy();
    void SetNext(TListItem<T>* item);
    virtual ~TListItem() {
        /*std::cout << "Destroy TList Item\n";
        Destroy();*/
    }
private:
//    std::shared_ptr<T> item;
    T* item;
    TListItem<T> *next;
};

#include "TListItem.cpp"
#endif //LAB6_TLISTITEM_H
