#ifndef LAB6_TVECTORITEM_H
#define LAB6_TVECTORITEM_H

#include <memory>
#include <iostream>
#include "/home/bokoch/CLionProjects/OOP/lab6/TAllocateList/TAllocationBlock.h"
#define MAX_TREE_CAPACITY 100
template <class T>
class TVectorItem {
public:
    TVectorItem ();

    TVectorItem (T &);

    TVectorItem (T *);

    template <class A>
    friend std::ostream &operator << (std::ostream &, const TVectorItem <A> &);

    void *operator new (size_t);

    T& operator * () {
        return *_value;
    }
    T& GetFigure() {
        return *_value;
    }
    void operator delete (void *);

    virtual ~TVectorItem ();

private:

    static TAllocationBlock Memory;

    T* _value;
};

#include "TVectorItem.cpp"
#endif //LAB6_TVECTORITEM_H
