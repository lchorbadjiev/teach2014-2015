#include <iostream>


#include "point.hh"

std::ostream&
operator<<(std::ostream& out, const Point& p) {
	out << "P(" << p.get_x() << ',' << p.get_y() << ')';
	return out;
}

void
Point::print() const {
	std::cout << *this << std::endl;
}
