#ifndef FIGURE_H
#define FIGURE_H

#include "iostream"
class Figure
{
public:
	virtual ~Figure() {}
	virtual void Print() const = 0;
	virtual double Area() const = 0;
    //virtual bool operator==(const Figure& lhs) const = 0;
    //virtual Figure& operator=(const Figure& obj) = 0;

};

#endif

