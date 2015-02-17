#ifndef RECTANGLE_HH__
#define RECTANGLE_HH__

#include "shape.hh"
#include "point.hh"


class Rectangle: public Shape {
	Point ul_;
	Point br_;
public:
	Rectangle(const Point& orig, double width, double height)
	: ul_(orig),
	  br_(orig.get_x()+width, orig.get_y()+height)
	{}
	
	void print() const;	


};


#endif

