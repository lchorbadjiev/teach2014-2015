#include <iostream>
using namespace std;

class ArrayError {};

class Array {
	int size_;
	int* data_;
public:
	Array(int size)
	: size_(size),
	  data_(new int[size_])
	{
		cout << "Array() called..." << endl;
	}

	~Array() {
		cout << "~Array() called..." << endl;
		delete [] data_;
	}
	
	int& operator[](int index) {
		if(index<0 || index>= size_) {
			throw ArrayError();
		}
		return data_[index];
	}
};


int main() {
	Array a(10);
	a[1]=1;
	for(int i=0;i<10;++i) {
		a[i]=i*10;
	}

	for(int i=0;i<10;++i) {
		cout << "a[" << i << "]=" << a[i] << endl;
	}

	

	// a[11]=1; // throws exception

	return 0;
}

