#ifndef RECTANGLE_HH__
#define RECTANGLE_HH__

#include "point.hh"

class Rectangle {
	static double min(double x, double y) {
		return x<y?x:y;
	}
	static double max(double x, double y) {
		return x>y?x:y;
	}

	Point bl_;
	Point ur_;
public:

	Rectangle(const Point& p1, const Point& p2);
	double get_width() const;
	double get_height() const;
	double get_x() const;
	double get_y() const;
	
	void print() const;
};

#endif
