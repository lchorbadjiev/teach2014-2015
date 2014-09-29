#include <iostream>
using namespace std;

class Rational {
	long numer_;
	long denom_;
public:
	Rational() {
		numer_=0;
		denom_=1;
	}
/*
	Rational() {
		// ala bala
	}
*/
	Rational(long numer, long denom) {
		numer_=numer;
		denom_=denom;
	}

	void print() {
		cout << '(' << numer_ << '/' << denom_ << ')' << endl;
	}

	void plus(Rational r) {
		numer_=numer_ * r.denom_ + r.numer_ * denom_;
		denom_=denom_ * r.denom_;
	}

};


int main() {
	Rational r1;
	r1.print();
	Rational r2(1,2);
	Rational r3(1,3);

	r2.print();
	r3.print();

	r2.plus(r3);
	r2.print();

	r3.plus(r3);
	r3.print();

	return 0;
}

