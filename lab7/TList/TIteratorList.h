#ifndef LAB6_TITERATOR_LIST
#define LAB6_TITERATOR_LIST

template<class T>
class TIterator {
public:
    TIterator(T *value);
    T &operator*();
    T &operator->();
    void operator++();
    //void operator--();
    TIterator<T>& operator++(int);
    //TIterator<T>& operator--(int);
    bool operator==(const TIterator &i) const;
    bool operator!=(const TIterator &i) const;
private:
    T *_value;
};
#include "TIteratorList.cpp"
#endif