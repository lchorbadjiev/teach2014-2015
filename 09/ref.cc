#include <iostream>
using namespace std;

void foo1(int val) {
	val = 42;
}

void foo2(int* pval) {
	*pval = 42;
}

void foo3(int& rval) {
	rval=43;
}

int main() {
	int a=1;
	foo1(a);
	cout << "a=" << a << endl;
	
	foo2(&a);
	cout << "a=" << a << endl;
	
	foo3(a);
	cout << "a=" << a << endl;
	
	int b=33;
	int& ra=a;
	cout << "ra=" << ra << endl;
	ra=44;
	cout << "a=" << a << endl;
	
	ra=b;
	cout << "a=" << a << endl;
	
	return 0;
}


