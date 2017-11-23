#ifndef LAB6_TITERATOR_LIST
#define LAB6_TITERATOR_LIST

template<class T>
class TIteratorList {
public:
    TIteratorList(T *value);
    T &operator*();
    T &operator->();
    void operator++();
    //void operator--();
    TIteratorList<T>& operator++(int);
    //TIteratorList<T>& operator--(int);
    bool operator==(const TIteratorList &i) const;
    bool operator!=(const TIteratorList &i) const;
private:
    T *_value;
};
#include "TIteratorList.cpp"
#endif