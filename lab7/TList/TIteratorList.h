#ifndef LAB6_TITERATOR_LIST
#define LAB6_TITERATOR_LIST

#include <memory>

template<class node, class T>
class TIteratorList {
public:
    TIteratorList(std::shared_ptr<node> value);
    std::shared_ptr<T> operator*();
    std::shared_ptr<T> operator->();
    void operator++();
    //void operator--();
    TIteratorList<node, T> operator++(int);
    //TIteratorList<T>& operator--(int);
    bool operator==(const TIteratorList &i) const;
    bool operator!=(const TIteratorList &i) const;
    ~TIteratorList() {
    }
private:
    std::shared_ptr<node> _value;
};
#include "TIteratorList.cpp"
#endif