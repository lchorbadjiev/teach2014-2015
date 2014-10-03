#include <iostream>
using namespace std;


long gcd(long a, long b) {
	if (b==0) {
		return 0;
	}
	long r = a % b;
	while (r!=0) {
		a=b;
		b=r;
		r=a % b;
	}
	return b;
}

class Rational {
	long numer_;
	long denom_;

	void normalize() {
		if(denom_<0) {
			numer_=-numer_;
			denom_=-denom_;
		}
		
		long d = gcd(numer_, denom_);
		if ( d > 1) {
			numer_ /= d;
			denom_ /= d;
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
		if(denom==0) {
			cout << "Zero denom error..."
				<< endl;
			// ?????
		}
		numer_=numer;
		denom_=denom;
		normalize();
	}

	void print() {
		cout << '(' << numer_ << '/' << denom_ << ')' << endl;
	}

	void plus(Rational r) {
		numer_=numer_ * r.denom_ + r.numer_ * denom_;
		denom_=denom_ * r.denom_;
		normalize();
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

	cout << gcd(4, 32) << endl;
	cout << gcd(56, 77) << endl;

	Rational r4(56, 77);
	r4.print();	

	Rational r5(-1, 2), r6(1,-2);
	r5.print();
	r6.print();
	Rational r7(1,2), r8(-1,-2);
	r7.print();
	r8.print();
	
	Rational r9(1,0);
	r9.print();


	return 0;
}

