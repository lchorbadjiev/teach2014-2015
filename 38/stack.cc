#include <iostream>
#include <exception>
using namespace std;

/*

HW:
 
1) copy constructor
2) operator=

3) implement vector
http://lubo.elsys-bg.org/wp-content/uploads/2009/05/oop02-vector.pdf
 due after holidays
 
*/


template<typename T>
class Stack {
	const static int CHUNK_SIZE_ = 10;


	int top_;
	int capacity_;
	T* data_;
	
	void ensure_capacity() {
		// ????
		T* tmp= data_;
		capacity_ += CHUNK_SIZE_;
		data_ = new T[capacity_];
		for(int i=0; i< top_; ++i) {
			data_[i] = tmp[i];
		}
		delete [] tmp;
	}
	
public:

	Stack()
	: top_(0),
	  capacity_(CHUNK_SIZE_),
	  data_(new T[capacity_])
	{}
	
	~Stack() {
		delete [] data_;
	}
	
	bool empty() const {
		return top_==0;
	}
	
	void push(T val) {
		if(top_>= capacity_) {
			ensure_capacity();
		}
		
		data_[top_++] = val;
	}

	T pop(void) {
		if(empty()) {
			throw exception();
		}
		return data_[--top_];
	}
	
};


int main() {
	Stack<int> st;
	cout << st.empty() << endl;
	
	st.push(777);
	cout << st.empty() << endl;
	cout << st.pop() << endl;
	cout << st.empty() << endl;	

	for(int i=0;i<47;++i) {
		st.push(i*3);
	}
	
	while(!st.empty()) {
		cout << st.pop() << ' ';
	}
	cout << endl;

		
	return 0;
}

