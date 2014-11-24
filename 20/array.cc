#include <iostream>
using namespace std;

class ArrayError{};

class Array {
	int size_;
	int* data_;
public:
	Array(int size)
	:size_(size),
	 data_(new int[size_])
	{}
	
	int size() const {
		return size_;
	}
	
	int& operator[](int index) {
		if(index<0 || index>=size_) {
			throw ArrayError();
		}
		return data_[index];
	}

};

int main() {

	Array a(10);
	cout << a.size() << endl;

	a[1]=1;
	
	for(int i=0;i<a.size(); ++i) {
		a[i]=i*10;
		cout << a[i] << endl;
	}
	

	// a[11]=11;// throw exception


	return 0;
}
