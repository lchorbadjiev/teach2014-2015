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

	Rational(long numer, long denom) {
		numer_=numer;
		denom_=denom;
	}

	long get_numer() {
		return numer_;
	}

	long get_denom() {
		return denom_;
	}

	void print() {
		cout << "(" << numer_ << "/"
			<< denom_ << ")" << endl;
	}

	void plus(Rational other) {
		numer_ = numer_ * other.denom_ + other.numer_ * denom_;
		denom_ = denom_ * other.denom_;
	}	
};


int main() {
	Rational r1, r2;
	r1.print();
	r2.print();
	Rational r3(1,2), r4(1,3);
	r3.print();
	r4.print();

	r3.plus(r4);
	r3.print();

	r4.plus(r4);
	r4.print();

	return 0;
}

