#include "TArray.h"

TArray::TArray() {
    _data = new Square[1];
    _capacity = 1;
    _size = 0;
}

TArray::TArray(const size_t &sizeArr) {
    this->_data = new Square[sizeArr];
    this->_capacity = sizeArr;
    this->_size = 0;
}

TArray::TArray(TArray& orig) {
    this->_data = new Square[orig._capacity];
    this->_size = orig._size;
    this->_capacity = orig._capacity;
    for (size_t index = 0; index < _size; index++) {
        this->_data[index] = orig._data[index];
    }
}
TArray::TArray(TArray* orig) {
    this->_data = new Square[orig->_capacity];
    this->_size = orig->_size;
    this->_capacity = orig->_capacity;
    for (size_t index = 0; index < _size; index++) {
        this->_data[index] = orig->_data[index];
    }

}

std::ostream &operator<<(std::ostream &os, const TArray &objArr) {
    for (size_t index = 0; index < objArr._size; ++index) {
        os << objArr[index] << std::endl;
    }
    return os;
}

std::istream &operator>>(std::istream &is, TArray &objArr) {
    Square temp;
    while (is >> temp) {
        objArr.Push_back(temp);
    }
    return is;
}
void TArray::Push_back(const Square &temp) {
    TArray arr = 5;
    if (_size == _capacity) {
        _capacity *= 2;
        Square *copyArr = new Square[_capacity];
        for (size_t index = 0; index < _size; ++index) {
            copyArr[index] = this->_data[index];
        }
        delete [] _data;
        _data = copyArr;
    }
    this->_data[_size++] = temp;
}

bool TArray::Delete(const Square &temp) {
    for (int index = 0; index < _size; ++index) {
        if (this->_data[index] == temp) {
            for (int shift = index; shift < _size - 1; shift++)
                this->_data[shift] = this->_data[shift+1];
            this->_data[_size - 1] = Square(0);
            _size--;
            return true;
        }
    }
    return false;
}

Square& TArray::operator[](size_t index) const{
    if (index < _size)
        return _data[index];
    return _data[0];
}
Square& TArray::operator[](size_t index) {
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

bool TArray::Replace(const Square &oldT, const Square &newT) {
    for (size_t index = 0; index < _size; index++)
        if (this->_data[index] == oldT) {
            this->_data[index] = newT;
            return true;
        }
    return false;
}



TArray::~TArray() {
    delete[] _data;
}
