#include <iostream>
using namespace std;


class Point {
	double x_;
	double y_;
public:
	Point(double x=0.0, double y=0.0)
	: x_(x), y_(y)
	{}
	
	double get_x() const {
		// x_=1.2;
		return x_;
	}
	double get_y() const {
		return y_;
	}
	
	void set_x(double x) {
		x_=x;
	}	
	void set_y(double y) {
		y_=y;
	}
};

class Foo {
	const double bar_;//=42;
public:
	Foo()
	: bar_(42)
	{
	
	}
	Foo(int a)
	: bar_(43)
	{}
};



int main() {
	Point p1(1.1,2.2);
	Point p2(3.3);
	Point p0;
	
	const double x0 = 0.0;
	double x = x0;
	// x0=1.1;
	
	const Point orig;
	// orig.set_x(1.1);
	x = orig.get_x();
	
	return 0;
}

