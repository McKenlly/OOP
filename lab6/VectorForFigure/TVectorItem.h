#ifndef LAB6_TVECTORITEM_H
#define LAB6_TVECTORITEM_H

#include <memory>
#include <iostream>
#include "/home/bokoch/CLionProjects/OOP/lab6/TAllocateList/TAllocationBlock.h"

template <class T>
class TVectorItem {
public:
    TVectorItem ();

    TVectorItem (T &);

    TVectorItem (T *);

    template <class A>
    friend std::ostream &operator << (std::ostream &, const TVectorItem <A> &);

    void *operator new (size_t);

    //void *operator new[] (size_t);
    //void operator delete[] (void *, size_t);
    T& operator * () {
        return *_value;
    }
    void operator delete (void *);

    virtual ~TVectorItem ();

private:

    static TAllocationBlock memory;

    T* _value;
};


#endif //LAB6_TVECTORITEM_H
