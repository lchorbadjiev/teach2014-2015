#include <iostream>
using namespace std;

class Shape {

public:
	virtual void print() const = 0;

};

class Rectangle: public Shape {

public:
	void print() const {
		cout << "Rectangle" << endl;	
	}

};

class Circle: public Shape {

public:
	void print() const {
		cout << "Circle" << endl;
	}
	
};




int main() {
	// Shape sh;
	Rectangle r;
	Circle c;
	
	return 0;
}

