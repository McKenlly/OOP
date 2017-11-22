#ifndef PROG_TVECTOR_H
#define PROG_TVECTOR_H
#include <iostream>
#include <memory>
#include "/home/bokoch/CLionProjects/OOP/lab6/Figure/Square.h"
#include "/home/bokoch/CLionProjects/OOP/lab6/Figure/Rectangle.h"
#include "/home/bokoch/CLionProjects/OOP/lab6/Figure/Trapezoid.h"
#include "./TIterator.h"
#include "./TVectorItem.h"
const size_t DEFAULT_CAPACITY = 10;
template <class T>
class TVector {
public:
    TVector();

    explicit TVector(const size_t &);

    TVector(TVector&);

    void Push_back(std::shared_ptr<T> &);

    bool Delete(const size_t);

    bool Empty();

    size_t Size() const;

    size_t Capacity() const;

    std::shared_ptr<T>& operator[](size_t);

    std::shared_ptr<T>& operator[](size_t) const;
    //Дружественный метод ТОЛЬКО для класса Figure.
    template <class A> friend std::ostream &operator<<(std::ostream &, const TVector<A> &);

    TIterator <std::shared_ptr<T>> begin ();
    TIterator <std::shared_ptr<T>> end ();
    //void * operator new(size_t size);
    //void operator delete(void *ptr);
    ~TVector();
private:
    std::shared_ptr<T> *_data;

    //static TAllocationBlock memory;
    size_t _capacity;

    size_t _size;

};
#endif  // PROG_TVector_H
