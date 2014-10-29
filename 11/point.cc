#include <iostream>
using namespace std;

class Point {
	friend void print(Point p);

	double x_;
	double y_;
public:
	Point(double x, double y)
	: x_(x), y_(y)
	{
		cout << "Point(x, y) called..." << endl;
	
		// x_=x;
		// y_=y;
	}

	Point()
	: x_(0.0), y_(0.0) {
		cout << "Point() called..." << endl;
	}

/*	
	Point(int x, int y) {
	
	}
*/

};

void print(Point p) {
	cout << '(' << p.x_ << ',' << p.y_ << ')' << endl;
}


class Rectangle {
	Point dl_;
	Point ur_;
public:

	Rectangle(double x1, double y1,
			 double x2, double y2)
	: dl_(x1,y1),
	  ur_(x2,y2)
    {
			 
		// dl_=Point(x1, y1);
		// ur_=Point(x2, y2);
	}

};


void bar() {
	cout << "bar() called..." << endl;
}

void bar(int a) {
	cout << "bar(int) called..." << endl;
}

void bar(int a, int b) {
	cout << "bar(int, int) called..." << endl;
}

void bar(double d) {
	cout << "bar(double) called... " << endl;
}

int main() {
	Rectangle r(0,0,1,1);
	Point p(0,0);
	Point p1;
	bar(1);
	bar(3.14);
	bar();
	bar(1,2);
	
	print(p);
	
	return 0;
}




