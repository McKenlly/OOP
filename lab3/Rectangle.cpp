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
std::istream& operator>>(std::istream& is, Rectangle& rectangle) {
	std::cout << "Enter side A: ";
	is >> rectangle.sideA;
	std::cout << "Enter side B: ";
	is >> rectangle.sideB;
    return is;
}
std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle){
	std::cout << "Figure type: Rectangle" << std::endl;
	os << "Side A =\t" << rectangle.sideA << std::endl;
	os << "Side B =\t" << rectangle.sideA << std::endl;
	return os;
}
void Rectangle::Print() const
{
	std::cout << "Figure type: Rectangle" << std::endl;
	std::cout << "Side A size:\t" << sideA << std::endl;
	std::cout << "Side B size:\t" << sideB << std::endl;
	std::cout << "SQUARE:\t" << Area() << std::endl;
}

double Rectangle::Area() const {
	return sideA * sideB;
}

Rectangle::~Rectangle() {
    std::cout << "Rectangle deleted" << std::endl;
}