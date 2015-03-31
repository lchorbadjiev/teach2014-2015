#include <iostream>
#include <stdlib.h>
using namespace std;


void copy2(void* dst, void* src, int size) {

	for(int i=0; i<size; ++i) {
		static_cast<char*>(dst)[i] = 
			static_cast<char*>(src)[i];
	}

}


int main() {
	int a[10], b[10];
	double c[10], d[10];
		
	for(int i=0; i<10; ++i) {
		a[i] = 2*i;
		c[i] = 1.1*i;
	}
	
	copy2(b, a, sizeof(a));
	
	for(int i=0; i<10; ++i) {
		cout << b[i] << ' ';
	}
	cout << endl;
	
	copy2(d, c, sizeof(c));
	
	for(int i=0; i<10; ++i) {
		cout << d[i] << ' ';
	}
	cout << endl;


	copy2(d, a, sizeof(a));

	for(int i=0; i<10; ++i) {
		cout << d[i] << ' ';
	}
	cout << endl;

	copy2(b, c, sizeof(c));
	for(int i=0; i<10; ++i) {
		cout << b[i] << ' ';
	}
	cout << endl;

	return 0;
}

