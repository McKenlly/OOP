#include "TArray.h"


template <class T>
TVector<T>::TVector() {
    _data = new std::shared_ptr<T>[DEFAULT_CAPACITY];
    _capacity = DEFAULT_CAPACITY;
    _size = 0;
}
template <class T>
TVector<T>::TVector(const size_t &sizeArr) {
    _data = new std::shared_ptr<T>[sizeArr];
    for (int i = 0; i < sizeArr; i++) {
        _data[i] = nullptr;
    }
    _capacity = sizeArr;
    _size = 0;
}
/*template <class T>*/
/*void *TVector<T>::operator new(size_t size)
{
    return allocSimple.allocate();
}
template <class T>
void TVector<T>::operator delete(void *ptr)
{
    allocSimple.deallocate(ptr);
}*/

template <class T>
TVector<T>::TVector(TVector<T>& orig) {
    _data = new std::shared_ptr<T>[orig._capacity];
    this->_size = orig._size;
    this->_capacity = orig._capacity;
    for (size_t index = 0; index < _size; index++) {
        _data[index] = orig._data[index];
    }
}
template <class T>
bool TVector<T>::Empty() {
    return _size == 0;
}
template <class T>
std::ostream &operator<<(std::ostream &os, const TVector<T> &objArr) {
    for (size_t index = 0; index < objArr._size; ++index) {
        if (&objArr[index] != nullptr) {
            os << index << "\t";
            objArr[index]->Print();
        }
    }
    return os;
}

template <class T>
void TVector<T>::Push_back(std::shared_ptr<T> &temp) {
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
bool TVector<T>::Delete(const size_t index) {
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
std::shared_ptr<T>& TVector<T>::operator[](size_t index) const{
    //if (index < _size && index > 0)
    return _data[index];
}
template <class T>
std::shared_ptr<T>& TVector<T>::operator[](size_t index) {
    // if (index < _size && index > 0)
    return _data[index];
}
template <class T>
size_t TVector<T>::Size() const{
    return this->_size;
}

template <class T>
size_t TVector<T>::Capacity() const {
    return this->_capacity;
}

template <class T>
TVector<T>::~TVector() {
    delete[] _data;
}

template <class T>
TIterator<std::shared_ptr<T>> TVector<T>::begin() {
    return TIterator<std::shared_ptr<T>>(0, _data);
}

template <class T>
TIterator<std::shared_ptr<T>> TVector<T>::end() {
    return TIterator<std::shared_ptr<T>>(_size, _data);
}


#include "/home/bokoch/CLionProjects/OOP/lab6/Figure/Figure.h"
template class TVector<Figure>;
template
std::ostream& operator << (std::ostream &os, const TVector<Figure> &objArr);
