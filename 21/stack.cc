#include <iostream>
using namespace std;

class StackError {};

class Stack {
	static const int CHUNK_SIZE = 3;
	
	int top_;
	int capacity_;
	int *data_;
	
	void resize() {
		cout << "resize() called..." << endl;
		
		int* old_data = data_;
		
		capacity_+=CHUNK_SIZE;
		data_ = new int[capacity_];
		
		for(int i=0;i<top_;++i) {
			data_[i]=old_data[i];
		}
		
		delete [] old_data;
	}
	
public:

	Stack() 
	: top_(0),
	  capacity_(CHUNK_SIZE),
	  data_(new int[capacity_])
	{
		cout << "Stack() called" << endl;
	}
	
	Stack(const Stack& st)
	: top_(st.top_),
	  capacity_(st.capacity_),
	  data_(new int[capacity_])
	{
		for(int i=0;i<top_;++i) {
			data_[i]=st.data_[i];
		}
	}
	
	Stack& operator=(const Stack& st) {
		delete [] data_;
		
		top_=st.top_;
		capacity_=st.capacity_;
		data_ = new int[capacity_];
		
		for(int i=0;i<top_;++i) {
			data_[i] = st.data_[i];
		}
	}
	
	
	~Stack() {
		cout << "~Stack() called" << endl;
		delete [] data_;
	}
	
	bool empty() const {
		return top_==0;
	}
	
	void push(int val) {
		if(top_>= capacity_) {
			resize();
		}
		data_[top_++]=val;
	}
	
	int pop() {
		if(empty()) {
			throw StackError();
		}
		return data_[--top_];
	}
};

int main() {
	{
		Stack st;
	}


	Stack st;
	cout << "st.empty()=" << st.empty() << endl;
	st.push(1);
	st.push(2);
	cout << "st.empty()=" << st.empty() << endl;
	while(!st.empty()) {
		cout << st.pop() << endl;
	}
	
	for(int i=0;i<10;i++) {
		st.push(i*42);
	}
	
	Stack st3=st;
	
	while(!st.empty()) {
		cout << st.pop() << endl;
	}
	
	while(!st3.empty()) {
		cout << st3.pop() << endl;
	}
	

	Stack st1=st;
	Stack st2(st);
	
	st2=st;
	st1=st;
	
	return 0;
}




