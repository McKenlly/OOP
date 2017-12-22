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
    Rectangle(std::istream &is);
    Rectangle(size_t sideA, size_t sideB);
    void setParams(std::istream &is);
    double getSquare() override;
    void Print() override;
    bool operator ==(const Rectangle &obj) const;
    Rectangle operator =(const Rectangle &obj);

    friend std::ostream& operator <<(std::ostream &os, const Rectangle &obj);
    friend std::istream& operator >>(std::istream &is, Rectangle &obj);

    ~Rectangle() {};
    int type() {return 2;}
private:
    size_t sideA;
    size_t sideB;
};

#endif