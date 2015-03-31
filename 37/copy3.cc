#include <iostream>
using namespace std;



template<class T>
void copy3(T dst[], T src[], int size) {

	for(int i=0; i<size; ++i) {
		dst[i] = src[i];
	}
	
}


int main() {
	int a[10], b[10];
	double c[10], d[10];
	
	for(int i=0;i<10;++i) {
		a[i] = 2*i;
	}
	
	copy3<int>(b, a, 10);
	
	
	copy3<int>(b, c, 10);
	copy3<double>(d, a, 10);

	return 0;
}

