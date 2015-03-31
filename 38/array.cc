#include <iostream>
#include <exception>

using namespace std;

template<class T>
class Array {

	unsigned size_;
	T* data_;
	
public:
	unsigned size() const {
		return size_;
	}

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
		for(int i=0;i<size_;++i) {
			data_[i] = other.data_[i];
		}
	}
	
	Array&
	operator=(const Array& other) {
		// a = a; // (*this), other are the same object
		if(this != &other) {
			delete [] data_;
			size_ = other.size_;
			data_ = new T[size_];
		
			for(int i=0; i<size_; ++i) {
				data_[i] = other.data_[i];
			}
		}
		return *this;
	}


	T& operator[](unsigned index) {
		if(!(index<size_)) {
			throw exception();
		}
		return data_[index];
	}

	const T& operator[](unsigned index) const {
		if(!(index<size_)) {
			throw exception();
		}
		return data_[index];
	}


	void print_all() const {
		/*
		T& a = (*this)[0];
		a=(T) 42;
		*/
		
		for(int i=0;i<size_; ++i) {
			cout << (*this)[i] << ' ';
		}
		cout << endl;
	}


};

int main() {

/*
	Array<int> a1(10);
	a[1] = 1;
	a[11] = 2; // throws exception
*/

	Array<int> a1(10);
	cout << a1[0] << endl;	
	a1[0] = 15;
	cout << a1[0] << endl;
	a1.print_all();

	Array<int> b1 = a1;
	b1[5]=777;
	a1.print_all();

	Array<int> c1(10);
	c1=a1;
	c1[6]=888;
	a1.print_all();
	
	c1=c1;

	return 0;
}

