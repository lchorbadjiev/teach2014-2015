#include <iostream>
using namespace std;

#define STACK_SIZE 10

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
			// error handling???
			throw StackError(1);
			//cout << "ooopsssssss" << endl;
		}
		data_[top_++]=val;		
	}

	int pop() {
		if(empty()) {
			throw StackError(2);
		}
		return data_[--top_];
	}
};

int main() {
	Stack st;
	try {
		for(int i=0;i<10; ++i) {
			st.push(i);
		}
		cout << "st.full()=" 
			<< st.full() << endl;
		st.push(10);
		cout << "ooops..." << endl;
	} 
	catch(StackError ex) {
		cout << "stack error catched..." 
			<< " error code: " 
			<< ex.error_code() << endl;
	}


	return 0;
}

