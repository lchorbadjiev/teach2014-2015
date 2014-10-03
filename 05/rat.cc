#include <iostream>
using namespace std;

long gcd(long a, long b) {
	while(b!=0) {
		long temp = a;
		a = b;
		b = temp % b;
	}
	return a;
}


class Rational {
	long numer_;
	long denom_;

	void standart() {
		if(denom_<0) {
			denom_=-denom_;
			numer_=-numer_;
		}
		long d = gcd(numer_, denom_);
		if(d>1) {
			numer_/=d;
			denom_/=d;
		}
	}
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
		standart();
	}

	void print() {
		cout << '(' << numer_ << '/' << denom_ << ')' << endl;
	}

	void plus(Rational r) {
		numer_=numer_ * r.denom_ + r.numer_ * denom_;
		denom_=denom_ * r.denom_;
		standart();
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

	cout << "gcd(4,2)=" << gcd(4,2) << endl;
	cout << "gcd(5, 15)=" << gcd(5, 15) << endl;
	cout << "gcd(9, 3)=" << gcd(9, 3) << endl;

	Rational r4(-1, 2), r5(1, -2);
	r4.print();
	r5.print();

	Rational r6(1, 0);
	r6.print();

	return 0;
}

