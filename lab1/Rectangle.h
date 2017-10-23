#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Figure.h"

class Rectangle : public Figure
{
public:
	Rectangle();
	Rectangle(std::istream& is);
    Rectangle(size_t a, size_t b);
    Rectangle(const Rectangle& object1); // Copy orig for new object

    void Print() const override;
	double Area() const override;
    ~Rectangle();

private:
	size_t sideA;
	size_t sideB;
};

#endif