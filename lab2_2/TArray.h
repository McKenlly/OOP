#ifndef PROG_TArray_H
#define PROG_TArray_H

#include "Square.h"
#include "iostream"

class TArray {
public:
    TArray();

    explicit TArray(const size_t &);

    TArray(TArray&);

    explicit TArray(TArray*);

    void Push_back(const Square &);

    bool Delete(const Square &);

    bool Replace(const Square &, const Square &);

    size_t Size() const;

    size_t Capacity() const;

    Square& operator[](size_t);

    Square& operator[](size_t) const;

    friend std::istream &operator>>(std::istream &, TArray&);

    friend std::ostream &operator<<(std::ostream &, const TArray &);

    ~TArray();

private:
    Square *_data;

    size_t _capacity;

    size_t _size;
};

#endif  // PROG_TArray_H
