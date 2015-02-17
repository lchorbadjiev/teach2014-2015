#ifndef RECTANGLE_HH__
#define RECTANGLE_HH__

#include "shape.hh"
#include "point.hh"

class Rectangle: public Shape {
	Point ul_;
	Point br_;
public:
	Rectangle(const Point& orig, double width, double height);
	
	void print() const;
};



#endif
