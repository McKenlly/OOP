#ifndef Trapezoid_H
#define Trapezoid_H
#include <iostream>
#include <cstdint>
#include "figure.h"

class Trapezoid: public Figure
{
public:
    Trapezoid();
    Trapezoid(const Trapezoid &orig);
    Trapezoid(size_t sideB, size_t sideA, size_t height);
    Trapezoid(std::istream &is);

    friend std::ostream& operator <<(std::ostream &os, const Trapezoid &obj);
    friend std::istream& operator >>(std::istream &is, Trapezoid &obj);

    bool operator ==(const Trapezoid &obj) const;
    Trapezoid operator =(const Trapezoid &obj);

    double getSquare() override;
    void Print() override;
    void setParams(std::istream &is);
    virtual ~Trapezoid() {};
    int type() {return 1;}
private:
    size_t sideB;
    size_t sideA;
    size_t height;
};

#endif