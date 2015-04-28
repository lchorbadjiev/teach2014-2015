#include <iostream>
using namespace std;

class Foo {
	int bar_;

public:
	Foo(int val)
	// explicit Foo(int val)
	: bar_(val)
	{}
	
	int get_bar() const {
		return bar_;
	}
};


int main() {

	Foo f1(1);
	cout << "Foo: f1.get_bar()=" << f1.get_bar() << endl;

	f1=3;
	cout << "Foo: f1.get_bar()=" << f1.get_bar() << endl;

	double v=3;
	
	return 0;
}



















