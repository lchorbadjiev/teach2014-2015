#include <iostream>
using namespace std;

/*
struct Point {
	double x;
	double y;
};
*/

class Point {
private:
	double x;
	double y;
public:
	void set_x(double val) {
		x=val;
	}

	double get_x() {
		return x;
	}

};


int main() {

	Point p1;
	Point p2;
//	p1.x = 1.0;
//	p1.y = 2.0;

	p1.set_x(10);
	p2.set_x(20);

	cout << "p1.get_x()=" << p1.get_x() << endl;
	cout << "p2.get_x()=" << p2.get_x() << endl;

	return 0;
}
