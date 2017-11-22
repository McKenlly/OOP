#ifndef LAB6_TITERATOR_H
#define LAB6_TITERATOR_H
#include <iostream>
#include <cstdlib>

/*template <class T>
class TIterator {
public:
    TIterator(int n, T *arr);
    T &operator*();
    T &operator->();
    void operator++();
    TIterator operator++(int);
    bool operator==(TIterator const &i);
    bool operator!=(TIterator const &i);
    ~TIterator() {};
private:
    size_t _n;
    T *_arr;
};*/
template <class T>
class TIterator {
public:
    TIterator(int n, T *arr) {
        _n = n;
        _arr = arr;
    }
    T &operator*() {
        return _arr[_n];
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

#endif //LAB6_TITERATOR_H
