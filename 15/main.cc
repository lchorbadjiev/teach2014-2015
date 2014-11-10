#include <iostream>
using namespace std;

#include "point.hh"
#include "rectangle.hh"

int main() {
	Point p1(1,1), p2(2,2);
	p1.print();
	p2.print();

	Rectangle r(p1, p2);
	r.print();

	Rectangle r1(p2, p1);
	r1.print();
	
	return 0;
}
