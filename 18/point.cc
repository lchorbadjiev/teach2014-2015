#include <iostream>
using namespace std;


class Point {
	double x_, y_;
public:
	Point(double x=0.0, double y=0.0)
	:x_(x), y_(y)
	{}
	
	double get_x() const {
		return x_;
	}
	double get_y() const {
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
	
	Point& add(const Point& p) {
		x_+=p.x_;
		y_+=p.y_;
		return *this;
	}
	Point& sub(const Point& p) {
		x_-=p.x_;
		y_-=p.y_;
		return *this;
	}
	
	Point& mul(double a) {
		x_*=a;
		y_*=a;
		return *this;
	}
	
	void print() {
		cout << "(" << x_ << "," << y_ << ")" << endl;
	}
	
	Point& operator+=(const Point& p) {
		add(p);
		return *this;
	}
	
	Point& operator-=(const Point& p) {
		sub(p);
		return *this;
	}
	
	Point& operator*=(double a) {
		mul(a);
		return *this;
	}
};

Point operator+(const Point& p1, const Point& p2) {
	Point res=p1;
	res+=p2;
	return res;
}

Point operator-(const Point& p1, const Point& p2) {
	Point res=p1;
	res-=p2;
	return res;
}

Point operator*(double a, const Point& p) {
	Point res=p;
	res*=a;
	return res;
}

// p*a -> a*p
Point operator*(const Point& p, double a) {
	return a*p;
}

// -p
Point operator-(const Point& p) {
	return -1*p;
}

ostream& operator<<(ostream& out, const Point& p) {
	out << '(' 
		<< p.get_x() << ','
		<< p.get_y() << ')';
	return out;
}

int main() {
	Point p1(1,1), p2(2,2), p3;
	p3.add(p1).sub(p2);
	p3.print();
	p3.mul(10);
	p3.print();
	
	int a=1;
	int b=2;
	a+=b;

	p1+=p2;
	p1.print();
	p1-=p2;
	p1.print();
	p1*=20;
	p1.print();
	
	p3=p1+2*p2-4*p1;
	p3.print();
	
	p3=2*p1+p2*3;
	
	cout << p1 << p2 << p3 << endl;
	//((cout << a) << b) << endl;
	//b=a<<2;
	
	cout << (-p3) << endl;
	return 0;
}
// operator++


/* HW:
Rational
add
sub
mul
div

+=, -=, *=, /=
+, -, *, /

cout << r << endl;

*/









