#include <iostream>
using namespace std;

void copy1(int dst[], int src[], int size) {

	for(int i=0;i<size; ++i) {
		dst[i] = src[i];
	}

}

void copy1(double dst[], double src[], int size) {

	for(int i=0;i<size; ++i) {
		dst[i] = src[i];
	}

}




int main() {
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int b[10];
	
	copy1(b,a,10);

	for(int i=0;i<10;++i) {
		cout << b[i] << ' ';
	}
	cout << endl;

	double c[10], d[10];
	for(int i=0;i<10;++i) {
		c[i] = i*3.14;
	}

	copy1(d, c, 10);

	for(int i=0;i<10;++i) {
		cout << d[i] << ' ';
	}
	cout << endl;


	return 0;
}

