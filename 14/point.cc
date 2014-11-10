#include <iostream>
using namespace std;

class Point {
	double x_, y_;
	
	static long count_;
	const static int size_=0;
	
public:
	Point(double x=0, double y=0)
	: x_(x), y_(y)
	{
		count_++;
	}
	
	static long count() {
		return count_;
	}
	
	double get_x() const {
		// cout << this->x_ << " " << x_ << endl;
		// cout << (*this).x_ << endl;
		return x_;
	}

	double get_y() const {
		// this;
		return y_;
	}
	
	Point& set_x(double x) {
		x_=x;
		return *this;
	}
	
	Point& set_y(double y) {
		y_=y;
		return *this;
	}
};

long Point::count_=0;

int main() {
	Point p1(1,1), p2(2,2);
	
	cout << p1.get_x() << endl;
	cout << p2.get_x() << endl;

	p1.set_x(1.1).set_y(1.1);
	
	(cout << p1.get_x()) << ',' << p1.get_y() << endl;

	cout << "count=" << Point::count() << endl;
	Point p3, p4;
	cout << "count=" << Point::count() << endl;
//	cout << "count=" << p3.count() << endl;
//	p4.count();
	
	return 0;
}



