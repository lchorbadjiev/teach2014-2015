#include <iostream>
using namespace std;

#include "point.hh"
#include "rectangle.hh"
#include "drawing.hh"

int main() {
	Point p1(0,0), p2(30, 20);
	cout << p1 << p2 << endl;

	Rectangle r1(p1, 100, 20);
	r1.print();

	Rectangle r2(p2, 100, 20);
	r2.print();

	Drawing d1;
	d1.add_shape(&r1);
	d1.print();	
	
	
	Drawing d2;
	d2.add_shape(&r2);
	d2.add_shape(&d1);
	
	d2.print();
	
	
	return 0;
}

