#include "Rectangle.h"

Rectangle::Rectangle() : Rectangle(0, 0) {}

Rectangle::Rectangle(size_t a, size_t b) : sideA(a), sideB(b){
    std::cout << "Rectangle created with sides " << a << " and " << b << std::endl;
}
Rectangle::Rectangle(std::istream& is)
{
	std::cout << "Enter side A: ";
	is >> sideA;
	std::cout << "Enter side B: ";
	is >> sideB;
}

void Rectangle::Print() const
{
	std::cout << "Figure type: rectangle" << std::endl;
	std::cout << "Side A size: " << sideA << std::endl;
	std::cout << "Side B size: " << sideB << std::endl;
}

double Rectangle::Area() const {
	return sideA * sideB;
}

Rectangle::~Rectangle() {
    std::cout << "Rectangle deleted" << std::endl;
}