#include <iostream>
#include <exception>
using namespace std;

template<typename T>
class List {

	struct Node {
		T data_;
		Node* next_;
		Node* prev_;
		
		Node()
		: next_(0),
		  prev_(0)
		{}
		
		Node(T val)
		: data_(val),
		  next_(0),
		  prev_(0)
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
	
	~List() {
		while(!empty()) {
			pop_front();
		}
		delete head_;
	}
	
	
	bool empty() const {
		// return head_->next_ == head_;
		// return head_->prev_ == head_;
		return head_->next_ == head_ -> prev_;
	}

	void push_front(T val) {
		Node* ptr = new Node(val);
		Node* front = head_->next_;
		
		head_->next_ = ptr;
		ptr->prev_ = head_;
		
		ptr->next_=front;
		front->prev_=ptr;	
	}

	void push_back(T val) {
		Node* ptr = new Node(val);
		Node* back = head_->prev_;
		
		back->next_ = ptr;
		ptr->prev_ = back;
		
		ptr->next_ = head_;
		head_->prev_ = ptr;
	}


	const T& front() const {
		if(empty()) {
			throw exception();
		}
		Node* front = head_ -> next_;
		return front->data_;
	}

	const T& back() const {
		if(empty()) {
			throw exception();
		}
		Node* back = head_ -> prev_;
		return back -> data_;
		
		// return head_->prev_->data_;
	}


	void pop_front() {
		if(empty()) {
			throw exception();
		}
		
		Node* front = head_->next_;
		Node* new_front = front->next_;
		
		head_->next_ = new_front;
		new_front->prev_=head_;
		
		delete front;
	}

	void pop_back() {
		if(empty()) {
			throw exception();
		}
		
		Node* back = head_->prev_;
		Node* new_back = back->prev_;
		
		new_back->next_= head_;
		head_->prev_ = new_back;
		
		delete back;
		
	}

};


int main() {
	List<int> li;
	
	cout << li.empty() << endl;
	li.push_front(-1);
	li.push_front(1);
	li.push_front(2);
	li.push_front(3);
	
	cout << li.empty() << endl;

	cout << li.front() << endl;
	cout << li.back() << endl;

	li.pop_front();
	cout << li.front() << endl;
	li.pop_back();
	cout << li.back() << endl;

	li.push_back(44);
	cout << li.back() << endl;

	
	return 0;
}

