
#include "TIterator.h"
template <class T>
TIterator:: TIterator(int n, T *arr) {
    _n = n;
    _arr = arr;
}
template <class T>
T & TIterator::operator*() {
    return _arr[_n];
}
template <class T>
T & TIterator::operator->() {
    return _arr[_n];
}
template <class T>
void TIterator::operator++() {
    _n++;
}
template <class T>
TIterator TIterator::operator++(int) {
    ++(*this);
    return *this;
}
template <class T>
bool TIterator::operator==(TIterator const &i) {
    return _n == i._n &&
           _arr == i._arr;
}
template <class T>
bool TIterator::operator!=(TIterator const &i) {
    return !(*this == i);
}