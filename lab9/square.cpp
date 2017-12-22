#include "square.h"
#include <cmath>
#include <cstring>


Square::Square() : Square(0) {}

Square::Square(size_t s): side(s)
{
}

Square::Square(std::istream& is)
{
    std::cout << "Enter side: ";
    is >> side;
    if(side < 0) {
        std::cerr << "Error: sides should be > 0." << std::endl;
    }
}

Square::Square(const Square& orig)
{
    side = orig.side;
}


void Square::Print()
{
    std::cout << "Figure type: Square" << std::endl;
    std::cout << "Side size:\t" << side << std::endl;
    std::cout << "SQUARE:\t" << GetSquare() << std::endl;
}

bool Square::operator ==(const Square &obj) const
{
    return side == obj.side;
}


Square Square::operator =(const Square &obj)
{
    if (&obj == this) {
        return *this;
    }

    side = obj.side;

    return *this;
}

std::ostream& operator <<(std::ostream &os, const Square &obj)
{
    os << "Figure type: Square" << std::endl;
    os << "Side A size:\t" << obj.side << std::endl;
    return os;
}

std::istream& operator >>(std::istream &is, Square &obj)
{
    std::cout << "Enter side: ";
    is >> obj.side;
    return is;
}


double Square::GetSquare()
{
    return (double)(side * side);
}