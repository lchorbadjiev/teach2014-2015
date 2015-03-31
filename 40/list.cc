#include <iostream>
#include <exception>
using namespace std;


template<typename T> 
class List {
	struct Node {
		T data_;
		Node* prev_;
		Node* next_;
		
		Node()
		: prev_(0),
		  next_(0)
		{}
		
		Node(T val)
		: data_(val),
		  prev_(0),
		  next_(0)
		{}
	};

	Node* head_;
public:
	List()
	: head_(new Node)
	{
		head_->prev_=head_;
		head_->next_=head_;
	}
	
	bool empty() const {
		return head_->next_ == head_->prev_;
	}

	void push_front(T val) {
		Node* front = head_->next_;
		Node* ptr = new Node(val);
		
		head_->next_ = ptr;
		ptr->prev_ = head_;
		
		ptr->next_ = front;
		front->prev_=ptr;
	}

	void pop_front() {
	
	}

	const T& front() const {
		if(empty()) {
			// ???
			throw exception();
		}
		Node* front = head_ ->next_;
		return front->data_;
	}
	
	const T& back() const {
		if(empty()) {
			throw exception();
		}
		
		Node* back = head_ -> prev_;
		return back->data_;

	}
	
};

int main() {
	List<int> li;
	cout << li.empty() << endl;

	li.push_front(1);
	li.push_front(2);
	li.push_front(3);
	
	cout << li.empty() << endl;
	cout << li.front() << endl;
	cout << li.back() << endl;
	

	return 0;
}

