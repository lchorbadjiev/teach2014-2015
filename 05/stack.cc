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
			cout << "Ooops! stack full" << endl;
			return -1;
		}
		data_[top_++] = val;
		return 0;
	}


	int pop(int *val) {
		if(empty()) {
			cout << "Ooops! stack empty" << endl;
			return -1;
		}
		*val = data_[--top_];
		return 0;
	}	
};


int main() {
	Stack st;
/*
	while(st.push(42)!=-1) {

	}
	cout << "st.full()=" << st.full() << endl;
	int val=0;
	while(st.pop(&val)!=-1) {
		cout << "pop val: " << val << endl;
	}
	cout << "st.empty()=" << st.empty() << endl;
*/
	while(!st.full()) {
		if(st.push(42)==-1) {
			// handle err???
		}
	}


	return 0;
}

