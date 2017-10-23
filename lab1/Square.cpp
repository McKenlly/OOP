#include "Square.h"

Square::Square() : Square(0) {
	std::cout << "Square created:\n Side  " << side << std::endl;
}
Square::Square(size_t sideA) : side(sideA){
	std::cout << "Square created with side " << side << std::endl;
}
Square::Square(const Square& object1) {
	std::cout << "Square copy created\n";
	side = object1.side;
}
Square::Square(std::istream& is)
{
	std::cout << "Enter side: ";
	is >> side;
}

void Square::Print() const
{
	std::cout << "Figure type: Square" << std::endl;
	std::cout << "Side size: " << side << std::endl;
}

double Square::Area() const
{
	return side * side;
}
Square::~Square() {
	std::cout << "Square deleted" << std::endl;
}