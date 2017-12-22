#include "Square.h"

Square::Square() : Square(0) {
}
Square::Square(size_t sideA) : side(sideA) {
    //std::cout << "Square created with side " << side << std::endl;
}
Square::Square(const Square& object1) {
    //std::cout << "Square copy created\n";
    side = object1.side;
}
Square::Square(std::istream& is)
{
//    std::cout << "Enter side: ";
    is >> side;
}

void Square::Print() const
{
    std::cout << "Figure type: Square" << std::endl;
    std::cout << "Side size:\t" << side << std::endl;
    std::cout << "SQUARE:\t" << Area() << std::endl;
}

double Square::Area() const
{
    return side * side;
}
Square::~Square() {
    //std::cout << "Square deleted" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Square& square){
//    os << "Side A = " << square.side;
    return os;
}

std::istream& operator>>(std::istream& is, Square& square) {
    is >> square.side;
    return is;
}
Square& Square::operator=(const Square& obj) {
    //std::cout << "Using operator is = ";
    if (this == &obj)
        return *this;
    side = obj.side;
    return *this;
}


bool Square::operator==(const Square &lhs) const{
    return this->side == lhs.side;
}
