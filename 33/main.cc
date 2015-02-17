#include <iostream>
using namespace std;

#include "point.hh"
#include "rectangle.hh"

int main() {
	Point p1(0,0), p2(10,20);
	p1.print(); p2.print();
	cout << endl;

	Rectangle r(p1, 20, 10);
	r.print();


	return 0;
}

