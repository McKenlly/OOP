#ifndef PROG_TArray_H
#define PROG_TArray_H

#include "Square.h"
#include "Rectangle.h"
#include "Trapezoid.h"
#include "iostream"
#include "memory"
#include "TIterator.h"
const size_t DEFAULT_CAPACITY = 10;


template <class T>
class TArray {
public:
    TArray();

    explicit TArray(const size_t &);

    TArray(TArray&);

    void Push_back(std::shared_ptr<T> &);

    bool Delete(const size_t);

    bool Empty();

    size_t Size() const;

    size_t Capacity() const;

    std::shared_ptr<T>& operator[](size_t);

    std::shared_ptr<T>& operator[](size_t) const;
    //Дружественный метод ТОЛЬКО для класса Figure.
    template <class A> friend std::ostream &operator<<(std::ostream &, const TArray<A> &);

    TIterator <std::shared_ptr<T>> begin ();
    TIterator <std::shared_ptr<T>> end ();

    ~TArray();

private:
    std::shared_ptr<T> *_data;

    size_t _capacity;

    size_t _size;
};
#include "TArray.hpp"
#endif  // PROG_TArray_H
