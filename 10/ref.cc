#include <iostream>
using namespace std;

void f(void) {
	// ala bala
}
void f() {

}

void foo(int v) {
	v = 42;
}

void foo1(int* pv) {
	*pv = 42;
}

void foo2(int& rv) {
	rv=43;
}

int main() {
	int a = 1;
	foo(a);
	
	cout << "a=" << a << endl;
	
	
	foo1(&a);
	cout << "a=" << a << endl;
	
	
	foo2(a);
	cout << "a=" << a << endl;
	
	int& ra = a;
	ra = 44;
	cout << "a=" << a << endl;

	int& rb= a;
	cout << "rb=" << rb << endl;
	rb++;
	cout << "ra=" << ra << endl;
	
	int ala=15;
	char bala = static_cast<char>(ala); //(char) ala;
	
	return 0;
}

