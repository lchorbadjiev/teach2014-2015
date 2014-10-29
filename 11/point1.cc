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

int main() {
	Point p;
/*
	const double orig = 0.0;
	// orig = 1.2;
	double a = orig;
*/
	const Point orig;
	
	// orig.set_x(1.2);
	
	double x = orig.get_x();
	double y = orig.get_y();
	
	
	// orig.set_x(1.2);
		
	return 0;
}

