#include <iostream>
using namespace std;

#include "rectangle.hh"

Rectangle::Rectangle(const Point& orig, double width, double height)
: ul_(orig),
  br_(orig.get_x() + width, orig.get_y() + height)
{}

void
Rectangle::print() const {
	cout << "Rect{" << endl
		<< '\t' << ul_ << endl
		<< '\t' << br_ << endl
		<< '}' << endl;
}
