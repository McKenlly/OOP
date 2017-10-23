#ifndef PROG_TArray_H
#define PROG_TArray_H

#include "Figure.h"
#include "Square.h"
#include "Rectangle.h"
#include "Trapezoid.h"
#include "iostream"
#include "memory"
const size_t DEFAULT_CAPACITY = 10;
class TArray {
public:
    TArray();

    explicit TArray(const size_t &);

    TArray(TArray&);

    void Push_back(std::shared_ptr<Figure> &);

    bool Delete(const size_t);

    bool Empty();

    size_t Size() const;

    size_t Capacity() const;

    std::shared_ptr<Figure>& operator[](size_t);

    std::shared_ptr<Figure>& operator[](size_t) const;

    friend std::ostream &operator<<(std::ostream &, const TArray &);

    ~TArray();

private:
    std::shared_ptr<Figure> *_data;

    size_t _capacity;

    size_t _size;
};

#endif  // PROG_TArray_H
