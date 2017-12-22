#ifndef Square_H
#define Square_H
#include "figure.h"

class Square: public Figure
{
public:
    Square();
    Square(std::istream &is);
    Square(size_t side);
    Square(const Square &orig);
    void Print() override;
    double getSquare() override;
    void setParams(std::istream &is);
    bool operator ==(const Square &obj) const;
    Square operator =(const Square &obj);
    friend std::ostream& operator <<(std::ostream &os, const Square &obj);
    friend std::istream& operator >>(std::istream &is, Square &obj);
    virtual ~Square() {};
    int type() {return 3;}
private:
    size_t side;
};

#endif