#include <iostream>
using namespace std;

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

	int push(int val) {
		if(full()) {
			cout << "Ooops! stack full" 
				<< endl;
			return -1;
		}
		data_[top_++] = val;
		return 0;
	}

	int pop(int *val) {
		if(empty()) {
			cout << "Ooooops! stack empty"
				<< endl;
			return -1;
		}

		*val = data_[--top_];
		return 0;
	}

};


int main() {
	Stack st;
	for(int i=0; i<10; ++i) {
		if(st.push(i)==-1) {
			// error handling????
			cout << "error handling"
				<< endl;
		}	
	}

	if(st.push(42)==-1) {
		// error handling ???
		cout << "haling the error 42"
			<< endl;
	}


	while(!st.empty()) {
		int val=0;
		if(st.pop(&val)==-1) {
			// error handling?????
			cout << "error hadling"
				<< endl;
		}
	}
	int val=0;
	if(st.pop(&val)==-1) {
		// error halding????
		cout << "error hadling empty stack"
			<< endl;
	}

	return 0;
}

