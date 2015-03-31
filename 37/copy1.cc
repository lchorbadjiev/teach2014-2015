#include <iostream>
using namespace std;


void copy1(int dst[], int src[], int size) {

	for(int i=0; i<size; ++i) {
		dst[i] = src[i];
	}
	
}

void copy1(double dst[], double src[], int size) {

	for(int i=0; i<size; ++i) {
		dst[i] = src[i];
	}
	
}




int main() {
	int a[10], b[10];
	double c[10], d[10];
	
	for(int i=0; i<10; ++i) {
		a[i] = 2*i;
		c[i] = 1.1*i;
	}

	copy1(b, a, 10);
	
	for(int i=0; i<10; ++i) {
		cout << b[i] << ' ';
	}
	cout << endl;

	copy1(d, c, 10);

	for(int i=0; i<10; ++i) {
		cout << d[i] << ' ';
	}
	cout << endl;

	return 0;
}

