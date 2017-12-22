#ifndef Rectangle_H
#define Rectangle_H
#include <iostream>
#include <cstdint>
#include "figure.h"

class Rectangle: public Figure
{
public:
    Rectangle();
    Rectangle(const Rectangle& orig);

    Rectangle(size_t sideA, size_t sideB);
    double GetSquare() override;
    Rectangle(std::istream &is);
    void Print() override;
    bool operator ==(const Rectangle &obj) const;
    Rectangle operator =(const Rectangle &obj);

    friend std::ostream& operator <<(std::ostream &os, const Rectangle &obj);
    friend std::istream& operator >>(std::istream &is, Rectangle &obj);

    ~Rectangle() {};
private:
    size_t sideA;
    size_t sideB;
};

#endif