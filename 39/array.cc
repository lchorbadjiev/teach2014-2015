#include <iostream>
#include <exception>
using namespace std;

template<class T>
class Array {
	unsigned size_;
	T* data_;

public:

	Array(unsigned size)
	: size_(size),
	  data_(new T[size_])
	{}
	
	~Array() {
		delete [] data_;
	}
	
	Array(const Array& other)
	: size_(other.size_),
	  data_(new T[size_])
	{
		for(int i=0; i<size_; ++i) {
			data_[i] = other.data_[i];
		}
	}

	// a=(b=c);
	// a=a;
	Array&
	operator=(const Array& other) {
		// a=a; this and other are the same object
		if( this != &other) {
			delete [] data_;
			size_ = other.size_;
			data_ = new T[size_];
		
			for(int i=0; i<size_; ++i) {
				data_[i] = other.data_[i];
			}
		}
		return *this;
	}


	unsigned size() const {
		return size_;
	}

	T& operator[](unsigned index) {
		if(index>=size_) {
			throw exception();
		}
		return data_[index];
	}


	const T& operator[](unsigned index) const {
		// cout << "operator[] const called..." << endl;
		if(index>=size_) {
			throw exception();
		}
		return data_[index];
	}


	void print_all() const {
		for(int i=0; i < size(); ++i) {
			cout << (*this)[i] << ' ';
		}
		cout << endl;
	}


};



int main() {
/*
	Array<int> a(10);
	a[9] = 15;
	cout << a[9] << endl;
	a[10] // throws exception
*/

	Array<int> a1(10);

	cout << a1.size() << endl;
	a1[9] = 15;
	cout << a1[9] << endl;
	
	// a1.print_all();

	const Array<int>& ar=a1;
	// ar[3]=7777;	
	
	ar.print_all();


	Array<int> b1(a1);
	
	b1[4] = 888;
	a1.print_all();
	

	Array<int> c1(1);
	c1 = a1;
	c1[5] = 999;
	a1.print_all();
		
}
