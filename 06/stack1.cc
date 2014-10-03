#include <iostream>
using namespace std;

class StackError {
	int error_code_;
public:
	StackError(int code) {
		error_code_=code;
	}
	int error_code() {
		return error_code_;
	}
};

#define STACK_SIZE 10

class Stack {
	int data_[STACK_SIZE];
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

	void push(int val) {
		if(full()) {
			cout << "Oooops: stack full" << endl;
			throw StackError(1);
			cout << "ala bala" << endl;
		}
		data_[top_++]=val;
	}
	
	int pop() {
		if(empty()) {
			cout << "Ooops: stack empty" << endl;
			throw StackError(2);
		}
		return data_[--top_];
	}

};



int main() {
	Stack st;
	try {
		for(int i=0;i<10;i++) {
			st.push(i);
		}
		st.push(42);
	}
	catch(StackError ex) {
		cout << "stack error catched: "
			<< ex.error_code() << endl;	
	}
	
	st.push(43);
		
	try {
		while(!st.empty()) {
			cout << st.pop() << endl;
		}
		st.pop();
	} catch(StackError ex) {
		cout << "stack error 2 catched: "
			<< ex.error_code() << endl;
	}
	
	return 0;
}

