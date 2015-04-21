#include <iostream>
using namespace std;

class Point {
	double x_;
	double y_;
	
	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream&, Point&);
	
public:
	Point(double x=0.0, double y=0.0)
	:x_(x), y_(y)
	{}
	
	// operator<<
	/*
	ostream& operator<<(ostream& out) {
		out << x_ << ',' << y_;
		return out;
	}
	*/



};

// operator<<
ostream& operator<<(ostream& out, const Point& p) {
	out << '(' << p.x_ << ',' << p.y_ << ')';
	return out;
}


istream& operator>>(istream& in, Point& p) {
	// (x,y)
	double x, y;
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

	// p1 << cout << endl;
	// p1.operator<<(cout);
		
	cout << p1 << p2 << endl;

	Point p;
	while(cin) {
		cin >> p;
		cout << "out>" << p << endl;
	}

	
	return 0;
}
