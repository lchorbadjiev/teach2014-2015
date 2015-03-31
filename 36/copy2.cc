#include <iostream>
using namespace std;


void copy_array(void* dst, void* src, int size) {
	for(int i=0; i<size; ++i) {
		static_cast<char*>(dst)[i] =
			static_cast<char*>(src)[i];
	}
}


int main() {
	int a[10], b[10];
	double c[10], d[10];
	
	for(int i=0; i<10; ++i) {
		a[i]=i;
		c[i]=1.1*i;
	}

	copy_array(b, a, sizeof(a));
	copy_array(d, c, sizeof(c));
	
	for(int i=0; i< 10; ++i) {
		cout << b[i] << ' ';
	}
	cout << endl;
	
	for(int i=0; i< 10; ++i) {
		cout << d[i] << ' ';
	}
	cout << endl;
	
	copy_array(d, a, sizeof(a));
	for(int i=0; i< 10; ++i) {
		cout << d[i] << ' ';
	}
	cout << endl;

	copy_array(b, c, sizeof(c));
	for(int i=0; i< 10; ++i) {
		cout << b[i] << ' ';
	}
	cout << endl;
	


	return 0;
}

