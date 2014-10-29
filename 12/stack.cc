#include <iostream>
using namespace std;

#define STACK_SIZE 10

class StackError {};
class Stack {
	int top_;
	int data_[STACK_SIZE];
public:
	Stack()
	: top_(0)
	{}
	
	bool empty() const {
		return top_==0;
	}
	
	bool full() const {
		return top_==STACK_SIZE;
	}
	
	void push(int val) {
		if(full()) {
			throw StackError();
		}
		data_[top_++] = val;
	}
	
	int pop() {
		if(empty()) {
			throw StackError();
		}
		return data_[--top_];
	}
};

int main() {
	Stack st;
	for(int i=0;i<10;++i) {
		st.push(i*42);
	}
	while(!st.empty()) {
		cout << st.pop() << endl;
	}
	
	return 0;
}
