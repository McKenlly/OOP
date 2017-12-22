#include "trapeze.h"

Trapezoid::Trapezoid() : Trapezoid(0, 0, 0){}
Trapezoid::Trapezoid(const Trapezoid &orig)
{
    sideB = orig.sideB;
    sideA = orig.sideA;
    height = orig.height;
}

Trapezoid::Trapezoid(size_t sb, size_t bb, size_t ls): sideB(sb), sideA(bb), height(ls)
{
    if (sideB > sideA) {
        std::swap(sideB, sideA);
    }
}

Trapezoid::Trapezoid(std::istream &is)
{
    std::cout << "Enter SideA: ";
    is >> sideA;
    std::cout << "Enter SideB: ";
    is >> sideB;
    std::cout << "Enter height: ";
    is >> height;
    if(sideB < 0 || sideA < 0 || height < 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
}

double Trapezoid::getSquare()
{
    return ((double)(sideA+sideB)*height)/2.0;
}

void Trapezoid::setParams(std::istream &is)
{
    std::cout << "Enter SideA: ";
    is >> sideA;
    std::cout << "Enter SideB: ";
    is >> sideB;
    std::cout << "Enter height: ";
    is >> height;
    if(sideB < 0 || sideA < 0 || height < 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
}

void Trapezoid::Print()
{
    std::cout << "Figure type: Trapezoid" << std::endl;
    std::cout << "Side A size:\t" << sideA << std::endl;
    std::cout << "Side B size:\t" << sideB << std::endl;
    std::cout << "Side heigth:\t" << height << std::endl;
    std::cout << "SQUARE:\t" << getSquare() << std::endl;
}

std::ostream& operator <<(std::ostream &os, const Trapezoid &obj)
{
    os << "Figure type: Trapezoid" << std::endl;
    os << "Side A size:\t" << obj.sideA << std::endl;
    os << "Side B size:\t" << obj.sideB << std::endl;
    os << "Side height:\t" << obj.height << std::endl;

    return os;
}

std::istream& operator >>(std::istream &is, Trapezoid &obj)
{
    std::cout << "Enter SideA: ";
    is >> obj.sideA;
    std::cout << "Enter SideB: ";
    is >> obj.sideB;
    std::cout << "Enter height: ";
    is >> obj.height;
    if(obj.sideB < 0 || obj.sideA < 0 || obj.height < 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
    return is;
}

bool Trapezoid::operator ==(const Trapezoid &obj) const
{
    return sideB == obj.sideB && sideA == obj.sideA && height == obj.height;
}


Trapezoid Trapezoid::operator =(const Trapezoid &obj)
{
    if (&obj == this) {
        return *this;
    }

    sideB = obj.sideB;
    sideA = obj.sideA;
    height = obj.height;
    return *this;
}