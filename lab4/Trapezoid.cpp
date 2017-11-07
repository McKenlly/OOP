#include "Trapezoid.h"

Trapezoid::Trapezoid():Trapezoid(0, 0, 0) {}
Trapezoid::Trapezoid(size_t a, size_t b, size_t h): sideA(a), sideB(b), height(h){
	std::cout << "Trapezoid created:\n" << "side A = " << sideA << "\nside B = " << sideB
			  << "\nHeight = " << height << std::endl;
}
Trapezoid::Trapezoid(const Trapezoid& object1) {
	std::cout << "Trapezoid copy created\n";
	sideA = object1.sideA;
	sideB = object1.sideB;
	height = object1.height;
}
Trapezoid::Trapezoid(std::istream& is)
{
	std::cout << "Enter side A: ";
	is >> sideA;
	std::cout << "Enter side B: ";
	is >> sideB;
	std::cout << "Enter height: ";
	is >> height;
}
std::istream& operator>>(std::istream& is, Trapezoid& trap) {
	std::cout << "Enter side A: ";
	is >> trap.sideA;
	std::cout << "Enter side B: ";
	is >> trap.sideB;
	std::cout << "Enter height: ";
	is >> trap.height;
	return  is;
}
std::ostream& operator<<(std::ostream& os, Trapezoid& trap) {
	std::cout << "Figure type: Trapezoid" << std::endl;;
	os << "Enter side A:\t" << trap.sideA << std::endl;
	os << "Enter side B:\t" << trap.sideB << std::endl;
	os << "Enter side heigth:\t" << trap.height << std::endl;
	os << "SQUARE:\t" << trap.Area() << std::endl;
	return  os;
}

void Trapezoid::Print() const
{
	std::cout << "Figure type: trapezoid" << std::endl;
	std::cout << "Side A size:\t" << sideA << std::endl;
	std::cout << "Side B size:\t" << sideB << std::endl;
	std::cout << "Height:\t" << height << std::endl;
	std::cout << "SQUARE:\t" << Area() << std::endl;
}

double Trapezoid::Area() const
{
	return height * (sideA + sideB) / 2.0;
}

  
