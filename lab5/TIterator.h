#ifndef LAB6_TITERATOR_H
#define LAB6_TITERATOR_H
#include "TArray.h"

template <class T>
class TIterator {
public:
    TIterator(int n, T *arr);
    T &operator*();
    T &operator->();
    void operator++();
    TIterator operator++(int);
    bool operator==(TIterator const &i);
    bool operator!=(TIterator const &i);
    ~TIterator() = default{};
private:
    size_t _n;
    T *_arr;
};


#endif //LAB6_TITERATOR_H
