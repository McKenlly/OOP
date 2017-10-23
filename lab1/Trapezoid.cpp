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

void Trapezoid::Print() const
{
	std::cout << "Figure type: trapezoid" << std::endl;
	std::cout << "Side A size: " << sideA << std::endl;
	std::cout << "Side B size: " << sideB << std::endl;
	std::cout << "Height: " << height << std::endl;
}

double Trapezoid::Area() const
{
	return height * (sideA + sideB) / 2.0;
}

  
