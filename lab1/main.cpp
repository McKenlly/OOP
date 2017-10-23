#include "Square.h"
#include "Rectangle.h"
#include "Trapezoid.h"

void TestFigure(Figure* figure);

int main()
{
	TestFigure(new Square(std::cin));
	//TestFigure(new Rectangle(std::cin));
	//TestFigure(new Trapezoid(std::cin));
	return 0;
}

void TestFigure(Figure* figure)
{
	figure->Print();

	std::cout << "Area: " << figure->Area() << std::endl;

	delete figure;
}