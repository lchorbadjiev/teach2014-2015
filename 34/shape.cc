#include <iostream>
using namespace std;

class Shape {

public:
	virtual void print() const = 0;

};

class Circle: public Shape {

public:
	void print() const {
		cout << "Circle" << endl;
	}

};

class Rectangle: public Shape {

public:
	void print() const {
		cout << "Rectangle" << endl;
	}

};



int main() {
	Shape* psh;
	// Shape& rsh;

	Circle c1;
	Rectangle r1;

	Shape& rsh1 = c1;
	Shape& rsh2 = r1;

	rsh1.print();
	rsh2.print();
	
	
	return 0;
}

