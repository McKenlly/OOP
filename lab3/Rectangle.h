#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>
#include "Figure.h"

class Rectangle : public Figure
{
public:
	Rectangle();
	explicit Rectangle(std::istream& is);
    Rectangle(size_t a, size_t b);
    Rectangle(const Rectangle& object1); // Copy orig for new object
	friend std::istream& operator>>(std::istream& is, Rectangle&);
	friend std::ostream& operator<<(std::ostream& os, const Rectangle&);
    void Print() const override;
	double Area() const override;
    ~Rectangle();

private:
	size_t sideA;
	size_t sideB;
};

#endif