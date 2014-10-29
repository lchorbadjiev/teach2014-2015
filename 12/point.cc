#include <iostream>
using namespace std;


class Point {
	double x_;
	double y_;
public:

	Point()
	: x_(0.0), y_(0.0) 
	{
		cout << "Point() called..." << endl;
	//	x_ = 0.0;
	//	y_ = 0.0;
	}


	Point(double x, double y)
	: x_(x), y_(y)
	{
		cout << "Point(double, double) called..." <<endl;
//		x_ = x;
//		y_ = y;
	}
};


class Rectangle {
	Point dl_;
	Point ur_;
public:
	Rectangle(double x1, double y1,
				double x2, double y2) 
	: dl_(x1, y1),
	  ur_(x2, y2)
	{
		// dl_ = Point(x1, y1);
		// ur_ = Point(x2, y2);			
	}

};


void bar() {
	cout << "bar() called..." << endl;
}

void bar(int a) {
	cout << "bar(int) called..." << endl;
}

void bar(double d) {
	cout << "bar(double) called..." << endl;
}

void foo(int a, int b=0, int c=42) {
	cout << "foo(" << a << ',' << b << ',' 
		<< c << ')' << endl;
}


int main() {
/*
	Point p1;
	Point p2(1, 2);
*/

	Rectangle r(1,1,2,2);
	
	bar();
	bar(1);
	bar(static_cast<double>(1));
	
	foo(1,2,3);
	foo(1,2);
	foo(1);
	
	return 0;
}

