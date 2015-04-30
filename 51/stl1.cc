#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Foo {

public:
	
	void operator()(int val) {
		cout << "Foo(" << val << ")" << endl;
	}

};

class SumAcc {
	int acc_;
public:
	SumAcc()
	: acc_(0)
	{}
	
	void operator()(int val) {
		acc_ += val;
	}
	
	int get_acc() const {
		return acc_;
	}
};


int main() {
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int N = sizeof(a)/sizeof(a[0]);
	
	cout << "N=" << N << endl;
	
	Foo bar;
	bar(1);
	bar(55);
	bar(42);
	
	cout << "------------------------" << endl;
	for_each(a, a+N, bar);
	
	cout << "------------------------" << endl;
	SumAcc sum;
	SumAcc res = for_each(a, a+N, sum);
	cout << "sum: orig=" << sum.get_acc() << endl;
	cout << "sum: res =" << res.get_acc() << endl;



	return 0;
}


