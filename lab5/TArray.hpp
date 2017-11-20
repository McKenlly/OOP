#include <memory>
#include "TArray.h"

template <class T>
TArray<T>::TArray() {
    _data = new std::shared_ptr<T>[DEFAULT_CAPACITY];
    _capacity = DEFAULT_CAPACITY;
    _size = 0;
}
template <class T>
TArray<T>::TArray(const size_t &sizeArr) {
    _data = new std::shared_ptr<T>[sizeArr];
    for (int i = 0; i < sizeArr; i++) {
        _data[i] = nullptr;
    }
    _capacity = sizeArr;
    _size = 0;
}
template <class T>
TArray<T>::TArray(TArray<T>& orig) {
    _data = new std::shared_ptr<T>[orig._capacity];
    this->_size = orig._size;
    this->_capacity = orig._capacity;
    for (size_t index = 0; index < _size; index++) {
        _data[index] = orig._data[index];
    }
}
template <class T>
bool TArray<T>::Empty() {
    return _size == 0;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const TArray<T> &objArr) {
    for (size_t index = 0; index < objArr._size; ++index) {
        if (&objArr[index] != nullptr) {
            os << index << "\t";
            objArr[index]->Print();
        }
    }
    return os;
}

template <class T>
void TArray<T>::Push_back(std::shared_ptr<T> &temp) {
    if (_size == _capacity) {
        _capacity *= 2;
        std::shared_ptr<T> *copyArr = new std::shared_ptr<T>[_capacity];
        for (size_t index = 0; index < _size; ++index) {
            copyArr[index] = this->_data[index];
        }
        delete [] _data;
        _data = copyArr;
    }
    this->_data[_size++] = temp;
}
template <class T>
bool TArray<T>::Delete(const size_t index) {
    std::shared_ptr<T> *tCopy = new std::shared_ptr<T>[_capacity];
    int j = 0;
    bool flag = false;
    for (int i = 0; i < _size; i++) {
        if (i!=index) {
            tCopy[j++] = _data[i];
        }
        else {
            flag = true;
        }
    }
    _size--;
    delete [] _data;
    _data = tCopy;
    return flag;
}
template <class T>
std::shared_ptr<T>& TArray<T>::operator[](size_t index) const{
    //if (index < _size && index > 0)
    return _data[index];
}
template <class T>
std::shared_ptr<T>& TArray<T>::operator[](size_t index) {
    // if (index < _size && index > 0)
    return _data[index];
}
template <class T>
size_t TArray<T>::Size() const{
    return this->_size;
}

template <class T>
size_t TArray<T>::Capacity() const {
    return this->_capacity;
}

template <class T>
TArray<T>::~TArray() {
    delete[] _data;
}

template <class T>
TIterator<std::shared_ptr<T>> TArray<T>::begin() {
    return TIterator<std::shared_ptr<T>>(0, _data);
}

template <class T>
TIterator<std::shared_ptr<T>> TArray<T>::end() {
    return TIterator<std::shared_ptr<T>>(_size, _data);
}


#include "Figure.h"
template class TArray<Figure>;
template
std::ostream& operator << (std::ostream &os, const TArray<Figure> &objArr);
