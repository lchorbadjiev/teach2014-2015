#include <iostream>
using namespace std;

class Point {
	double x_, y_;
public:
	Point(double x=0.0, double y=0.0)
	: x_(x), y_(y)
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
	
	void print() const {
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

Point operator*(const Point& p, double a) {
	return a*p;
}

Point operator-(const Point& p) {
	return -1*p;
}

ostream& operator<<(ostream& out, const Point& p) {
	out << '(' << p.get_x() << ',' << p.get_y() 
		<< ')';
	return out;
}



int main() {
	Point p1(1,1), p2(2,2), p3;
	
	p1.print();
	p1.add(p2);
	p1.print();
	p1.sub(p2);
	p1.print();
	p1.mul(2);
	p1.print();
	p1.mul(0.5);
	p1.print();

	int a=0;
	int b=1;
	a+=b;
	a<<2;
	
	
	p1+=p2;
	p1.print();
	p1-=p2;
	p1.print();
	p1*=2;
	p1.print();
	p1*=0.5;
	p1.print();
	
	p3=p1+p2;
	p3.print();
	p3=p2-p1;
	p3.print();

	p3=10*p2;
	p3.print();
	
	p3=p1*20;
	p3.print();
	
	p3=-p1;
	p3.print();
	(-p1).print();
	
	(cout << p1) << p2 << p3 << endl;
	
	
	
	return 0;
}
/*
HW: Rational
add
sub
mul
div

+=, -=, *=, /=
+, -, *, /

cout << r;




*/
