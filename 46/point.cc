#include <iostream>
using namespace std;


class Point {
	double x_, y_;

	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream&, Point&);
	
public:
	Point(double x=0.0, double y=0.0)
	: x_(x), y_(y)
	{}

	Point operator+(const Point& p) {
		cout << "operator + called..." << endl;
		return Point(x_+p.x_, y_+p.y_);
	}

/*	
	ostream& operator<<(ostream& out) {
		out << '(' << x_ << ',' << y_ << ')';
		return out;
	}
*/
	
};

ostream& operator<<(ostream& out, const Point& p) {
	out << '(' << p.x_ << ',' << p.y_ << ')';
	return out;
}

istream& operator>>(istream& in, Point& p) {
	// (x,y)
	double x=0.0, y=0.0;
	char ch;
	in >> ch;
	if(ch!='(') {
		in.clear(ios_base::badbit);
		return in;
	}
	
	in >> x >> ch;
	if(ch!=',') {
		in.clear(ios_base::badbit);
		return in;	
	}
	in >> y >> ch;
	if(ch!=')') {
		in.clear(ios_base::badbit);
		return in;	
	}
	
	if(in.good()) {
		p.x_=x;
		p.y_=y;
	}
	
	return in;
}


int main() {
	Point p1(1,2), p2(10,20);
	
	cout << p1 << p2 << endl;
	Point p;
	p=p1+p2;
	// p=p1.operator+(p2);

	// p1 << cout;
	cout << p << endl;
	
	while(cin) {
		cin >> p;
		cout << "out>" << p << endl;
	}
	
	return 0;
}

