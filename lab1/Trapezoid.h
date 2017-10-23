#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <iostream>
#include "Figure.h"

class Trapezoid : public Figure
{
public:
	Trapezoid();
	Trapezoid(size_t a, size_t b, size_t h);
	Trapezoid(const Trapezoid& object1);
	Trapezoid(std::istream& is);

	void Print() const override;
	double Area() const override;

private:
	size_t sideA;
	size_t sideB;
	size_t height;
};

#endif