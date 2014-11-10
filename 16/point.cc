#include <iostream>
using namespace std;

#include "point.hh"

void Point::print() const {
	cout << "P(" << x_ << "," << y_ << ")" << endl;
}
