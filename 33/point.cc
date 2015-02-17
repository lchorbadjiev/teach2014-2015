#include <iostream>
using namespace std;

#include "point.hh"


void 
Point::print() const {
	cout << "P(" << x_ << ", " << y_ << ")";
}


std::ostream& operator<<(std::ostream& out, const Point& p) {
	out << "P(" << p.get_x() << "," << p.get_y() << ")";
	return out;
}
