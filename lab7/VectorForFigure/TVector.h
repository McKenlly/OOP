#ifndef PROG_TVECTOR_H
#define PROG_TVECTOR_H
#include <iostream>
#include <memory>
#include "/home/bokoch/CLionProjects/OOP/lab7/Figure/Square.h"
#include "/home/bokoch/CLionProjects/OOP/lab7/Figure/Rectangle.h"
#include "/home/bokoch/CLionProjects/OOP/lab7/Figure/Trapezoid.h"
#include "./TIterator.h"
#include "./TVectorItem.h"
const size_t DEFAULT_CAPACITY = 1;
template <class T>
class TVector {
public:
    TVector();
    explicit TVector(const size_t &);
    TVector(TVector&);
    void Push_back(T &);
    bool Delete(const size_t);
    bool Empty();
    size_t Size() const;
    size_t Capacity() const;
    T& operator[](size_t);
    T& operator[](size_t) const;
    //Дружественный метод ТОЛЬКО для класса Figure.
    template <class A> friend std::ostream &operator<<(std::ostream &, const TVector<A> &);
    TIterator <TVectorItem<T>*> begin ();
    TIterator <TVectorItem<T>*> end ();
    //void * operator new(size_t size);
    //void operator delete(void *ptr);
    ~TVector();
private:
    TVectorItem<T> **_data;
    size_t _capacity;
    size_t _size;
};
#endif  // PROG_TVector_H
