#include <memory>
#include "TArray.h"

TArray::TArray() {
    _data = new std::shared_ptr<Figure>[DEFAULT_CAPACITY];
    _capacity = DEFAULT_CAPACITY;
    _size = 0;
}

TArray::TArray(const size_t &sizeArr) {
    _data = new std::shared_ptr<Figure>[sizeArr];
    for (int i = 0; i < sizeArr; i++) {
        _data[i] = nullptr;
    }
    _capacity = sizeArr;
    _size = 0;
}

TArray::TArray(TArray& orig) {
    _data = new std::shared_ptr<Figure>[orig._capacity];
    this->_size = orig._size;
    this->_capacity = orig._capacity;
    for (size_t index = 0; index < _size; index++) {
        _data[index] = orig._data[index];
    }
}
bool TArray::Empty() {
    return _size == 0;
}

std::ostream &operator<<(std::ostream &os, const TArray &objArr) {
    for (size_t index = 0; index < objArr._size; ++index) {
        if (&objArr[index] != nullptr)
            os << index << "\t";
        objArr[index]->Print();
    }
    return os;
}


void TArray::Push_back(std::shared_ptr<Figure> &temp) {
    if (_size == _capacity) {
        _capacity *= 2;
        std::shared_ptr<Figure> *copyArr = new std::shared_ptr<Figure>[_capacity];
        for (size_t index = 0; index < _size; ++index) {
            copyArr[index] = this->_data[index];
        }
        delete [] _data;
        _data = copyArr;
    }
    this->_data[_size++] = temp;
}

bool TArray::Delete(const size_t index) {
    std::shared_ptr<Figure> *tCopy = new std::shared_ptr<Figure>[_capacity];
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

std::shared_ptr<Figure>& TArray::operator[](size_t index) const{
    if (index < _size)
        return _data[index];
    return _data[0];
}
std::shared_ptr<Figure>& TArray::operator[](size_t index) {
    if (index < _size)
        return _data[index];
    return _data[0];
}
size_t TArray::Size() const{
    return this->_size;
}

size_t TArray::Capacity() const {
    return this->_capacity;
}

/*bool TArray::Replace(const Figure &oldT, const Figure &newT) {
    for (size_t index = 0; index < _size; index++)
        if (this->_data[index] == oldT) {
            this->_data[index] = newT;
            return true;
        }
    return false;
}*/



TArray::~TArray() {
    delete[] _data;
}
