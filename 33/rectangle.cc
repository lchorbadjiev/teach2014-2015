#include <iostream>
using namespace std;

#include "rectangle.hh"

void
Rectangle::print() const {
	cout << "Rect{" << endl
		 << "\t" << ul_ << endl
		 << "\t" << br_ << endl
		 << "}" << endl;
}
