#include <iostream>
using namespace std;

#define STACK_SIZE 10

class Stack {
	int data_[STACK_SIZE];
	int top_;
public:

	Stack() {
		cout << "Stack constructor called..." << endl;
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
			cout << "Ooops! stack full..." << endl;
			return;
		}
		data_[top_++]=val;
		//top_++;
	}

	int pop() {
		if(empty()) {
			cout << "Ooops! stack empty..." << endl;
			return 42;
		}
		// top_--;
		return data_[--top_];
	}

};



int main() {

	Stack st;
	cout << "after..." << endl;
	Stack st2;
	cout << "st.empty()=" << boolalpha << st.empty() << endl;
	cout << "st.full()=" << st.full() << endl;

	st.push(1);
	st.push(2);
	cout << "st.empty()=" << st.empty() << endl;
	for(int i=0;i<10;++i) {
		st.push(i);
	}

	while(!st.empty()) {
		cout << "st.pop()=" << st.pop() << endl;
	}

	st.pop();

	return 0;
}

