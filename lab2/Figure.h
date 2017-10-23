#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
public:
	virtual ~Figure() {}
	virtual void Print() const = 0;
	virtual double Area() const = 0;
};

#endif

