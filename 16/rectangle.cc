#include <iostream>
using namespace std;

#include "rectangle.hh"

Rectangle::Rectangle(const Point& p1, const Point& p2)
: bl_(min(p1.get_x(), p2.get_x()),
	  min(p1.get_y(), p2.get_y())),
  ur_(max(p1.get_x(), p2.get_x()),
  	  max(p1.get_y() ,p2.get_y()))
{}


double Rectangle::get_width() const {
	return ur_.get_x() - bl_.get_x();
}

double Rectangle::get_height() const {
	return ur_.get_y() - bl_.get_y();
}

double Rectangle::get_x() const {
	return bl_.get_x();
}

double Rectangle::get_y() const {
	return bl_.get_y();
}

void Rectangle::print() const {
	cout << "R{ bl_("
		 << bl_.get_x() << "," << bl_.get_y()
		 << "), ur_("
		 << ur_.get_x() << "," << ur_.get_y()
		 << ") }" << endl;
}



