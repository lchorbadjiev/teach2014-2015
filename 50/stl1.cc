#include <iostream>

#include <algorithm>

using namespace std;

class Foo {

public:

	void operator()(int val) {
		cout << "Foo(" << val << ")" << endl;
	}

};


class SumAccum {

	int acc_;
	
public:
	SumAccum()
	: acc_(0)
	{}
	
	int get_acc() const {
		return acc_;
	}
	
	void operator()(int val) {
		acc_ += val;
	}

};


int main() {

	

	Foo bar;
	bar(1);
	bar(2);
	bar(3);

	cout << "-----------------------------" << endl;
	
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int N = sizeof(a)/sizeof(a[0]);
	
	cout << "size of array: " << N << endl;

	for_each(a, a+N, bar);
	
	SumAccum sum;
	
	SumAccum res=for_each(a, a+N, sum);
	cout << "sum: orig=" << sum.get_acc() << endl;
	cout << "sum: res =" << res.get_acc() << endl;
	
	
	return 0;
}
