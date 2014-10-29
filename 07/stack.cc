#include <iostream>
using namespace std;
#define STACK_SIZE 10

class StackError{};


template<typename T>
class Stack {
	T data_[STACK_SIZE];
	int top_;
public:
	Stack() {
		top_=0;
	}

	bool empty() {
		return top_==0;
	}
	bool full() {
		return top_==STACK_SIZE;
	}
	
	void push(T val) {
		if(full()) {
			throw StackError();
		}
		data_[top_++]=val;
	}
	
	T pop() {
		if(empty()) {
			throw StackError();
		}
		return data_[--top_];
	}
};

int main() {
	Stack<int> istack;
	Stack<double> dstack;
	cout << "istack.empty()=" << istack.empty() << endl;
	cout << "dstack.emtpy()=" << dstack.empty() << endl;
	for(int i=0;i<10; ++i) {
		istack.push(i*42);
		dstack.push(3.14*i);
	}
	while(!istack.empty()) {
		cout << istack.pop() << endl;
	}
	while(!dstack.empty()) {
		cout << dstack.pop() << endl;
	}
	return 0;
}

