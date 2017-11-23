#ifndef LAB6_TITERATOR_H
#define LAB6_TITERATOR_H
#include <iostream>
#include <cstdlib>

template <class T>
class TIterator {
public:
    TIterator(int position, T *value);
    T &operator*();
    T &operator->();
    void operator++();
    void operator--();
    TIterator<T>& operator++(int);
    TIterator<T>& operator--(int);
    bool operator==(const TIterator &i) const;
    bool operator!=(const TIterator &i) const;
private:
    size_t _index;
    T *_value;
};
#include "TIterator.cpp"
#endif //LAB6_TITERATOR_H
