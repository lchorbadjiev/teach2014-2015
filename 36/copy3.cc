#include <iostream>
using namespace std;


template<class T>
void copy2(T dst[], T src[], int size) {

	for(int i=0; i<size; ++i) {
		dst[i] = src[i];
	}
}

template<class T>
void print(T src[], int size) {
	for(int i=0; i<10; ++i) {
		cout << src[i] << ' ';
	}
	cout << endl;
}


int main() {
	int a[10], b[10];
	double c[10], d[10];
	
	for(int i=0;i<10;++i) {
		a[i] = 2*i;
		c[i] = 1.1*i;
	}

	copy2<int>(b, a, 10);
	print<int>(b, 10);
		
	copy2<double>(d, c, 10);
	print<double>(d, 10);
	
	// copy2<int>(d, a, 10);
	// copy2<double>(d, a, 10);
	
	return 0;
}


