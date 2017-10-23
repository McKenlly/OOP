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


	Square& operator=(const Square& obj);
	Square& operator++();
	Square& operator++(int);
    bool operator==(const Square& lhs) const;
	friend std::istream& operator>>(std::istream& is, Square& square);
	friend std::ostream& operator<<(std::ostream& os, const Square& square);
    ~Square();
private:
	size_t side;
};

#endif
