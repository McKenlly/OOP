#ifndef LAB6_TVECTORITEM_H
#define LAB6_TVECTORITEM_H

#include <memory>
#include <iostream>
#include "/home/bokoch/CLionProjects/OOP/lab7/TAllocateList/TAllocationBlock.h"

template <class T>
class TVectorItem {
public:
    TVectorItem ();

    explicit TVectorItem (T &);

    explicit TVectorItem (T *);
    template <class A>
    friend std::ostream &operator << 
                        (std::ostream &, const TVectorItem <A> &);
    void *operator new (size_t);
    void operator delete (void *);
    T& operator * ();
    T& GetFigure();
    virtual ~TVectorItem ();
private:
    static TAllocationBlock Memory;
    static const size_t SIZE_ARRAY_FOR_ALLOCATOR;
    T* _value;
};

#include "TVectorItem.cpp"
#endif //LAB6_TVECTORITEM_H
