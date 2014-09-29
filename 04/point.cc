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
	double get_x() {
		return x;
	}
	void set_x(double val) {
		x=val;
	}
};


int main() {
/*
	struct Point p1;
	Point p2;

	p1.x=1;
	p1.y=2;
*/

	Point p1;
	Point p2;
	// p1.x=1;
	p1.set_x(10);
	p2.set_x(20);

	cout << "p1.get_x()=" << p1.get_x() << endl;
	cout << "p2.get_x()=" << p2.get_x() << endl;	




	return 0;
}
