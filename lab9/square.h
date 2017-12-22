#ifndef Square_H
#define Square_H

#include <iostream>
#include "figure.h"

class Square: public Figure
{
public:
    Square();
    Square(std::istream &is);
    Square(size_t side);
    Square(const Square &orig);
    void Print() override;
    double GetSquare() override;
    bool operator ==(const Square &obj) const;
    Square operator =(const Square &obj);
    friend std::ostream& operator <<(std::ostream &os, const Square &obj);
    friend std::istream& operator >>(std::istream &is, Square &obj);
    virtual ~Square() {};
private:
    size_t side;
};

#endif