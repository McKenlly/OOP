#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include "Figure.h"

class Square : public Figure
{
public:
	Square();
	Square(size_t a);
	Square(std::istream& is);
	Square(const Square& object1);

	void Print() const override;
	double Area() const override;
	~Square();
private:
	size_t side;
};

#endif
