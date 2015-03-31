#include <iostream>
#include <exception>
using namespace std;


template<class T>
class Stack {
	const static int SIZE_ = 128;
	int top_;
	T data_[SIZE_];
	
public:
	Stack()
	: top_(0)
	{}
	
	bool empty() const {
		return top_==0;
	}
	
	bool full() const {
		return top_==SIZE_;
	}

	void push(T val) {
		if(full()) {
			throw exception();
		}
		data_[top_++] = val;
	}

	T pop() {
		if(empty()) {
			throw exception();
		}
		return data_[--top_];
	}

};


int main() {
	Stack<int> s1;
	
	cout << s1.empty() << ' ' << s1.full() << endl;
	s1.push(1);
	cout << s1.empty() << ' ' << s1.full() << endl;
	s1.push(2);	


	while(!s1.empty()) {
		cout << s1.pop() << endl;
	}
	
	Stack<double> s2;
	for(int i=0;i<10; ++i) {
		s2.push(i*1.1);
	}
	while(!s2.empty()) {
		cout << s2.pop() << endl;
	}
	
	return 0;
}


