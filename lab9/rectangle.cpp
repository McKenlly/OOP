#include "rectangle.h"

Rectangle::Rectangle() : Rectangle(0, 0) {}

Rectangle::Rectangle(const Rectangle& orig)
{
    sideA = orig.sideB;
    sideB = orig.sideB;
}

Rectangle::Rectangle(size_t s, size_t ang): sideA(s), sideB(ang)
{}


void Rectangle::Print()
{
    std::cout << "Figure type: Rectangle" << std::endl;
    std::cout << "Side A size:\t" << sideA << std::endl;
    std::cout << "Side B size:\t" << sideB << std::endl;
    std::cout << "SQUARE:\t" << GetSquare() << std::endl;
}

Rectangle::Rectangle(std::istream &is)
{
    std::cout << "Enter sideA: ";
    is >> sideA;
    std::cout << "Enter sideB: ";
    is >> sideB;
    if(sideA * sideB < 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
}

std::ostream& operator <<(std::ostream &os, const Rectangle &obj)
{
    os << "Figure type: Rectangle" << std::endl;
    os << "Side A size:\t" << obj.sideA << std::endl;
    os << "Side B size:\t" << obj.sideB << std::endl;
    return os;
}

double Rectangle::GetSquare() {
    return sideA*sideB;
}

std::istream& operator >>(std::istream &is, Rectangle &obj)
{
    std::cout << "Enter sideA: ";
    is >> obj.sideA;
    std::cout << "Enter sideB ";
    is >> obj.sideB;
    return is;
}

bool Rectangle::operator ==(const Rectangle &obj) const
{
    return sideB == obj.sideB && sideA == obj.sideA;
}


Rectangle Rectangle::operator =(const Rectangle &obj)
{
    if (&obj == this) {
        return *this;
    }
    sideB = obj.sideB;
    sideA = obj.sideA;
    return *this;
}