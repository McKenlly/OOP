#ifndef PROG_TArray_H
#define PROG_TArray_H

#include "Square.h"
#include "Rectangle.h"
#include "Trapezoid.h"
#include "iostream"
#include "memory"
const size_t DEFAULT_CAPACITY = 10;

template <class T>
class TIterator {
public:
    TIterator(int n, T *arr) {
        _n = n;
        _arr = arr;
    }
    T &operator*() {
        std::cout << 2 << std::endl;
       /* _arr[_n]->Print();
        if (_n > 0)
            std::cout << _arr[_n+1] << std::endl;
        if (_n > 1)
            std::cout << *_arr[_n+2] << std::endl;
        */return _arr[_n];
    }
    T &operator->() {
        return _arr[_n];
    }
    void operator++() {
        _n++;
    }
    TIterator operator++(int) {
        ++(*this);
        return *this;
    }

    bool operator==(TIterator const &i) {
        return _n == i._n &&
               _arr == i._arr;
    }

    bool operator!=(TIterator const &i) {
        return !(*this == i);
    }

private:
    size_t _n;
    T *_arr;
};



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
