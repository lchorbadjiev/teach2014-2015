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
	
	~List() {
		while(!empty()) {
			pop_front();
		}
		
		delete head_;
	}

	List(const List& other) 
	: head_(new Node)
	{
		Node* ptr = other.head_->next_;
		while( ptr!= other.head_) {
			push_back(ptr->data_);
			ptr=ptr->next_;
		}
	}

	List& operator=(const List& other) {
		// Homework???
		
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
		if(empty()) {
			throw exception();
		}
		
		Node* front = head_ -> next_;
		Node* new_front = front->next_;
		
		head_->next_ = new_front;
		new_front->prev_ = head_;
		
		delete front;
	}

	void push_back(T val) {
		Node* ptr = new Node(val);
		Node* back = head_ -> prev_;
		
		back->next_ = ptr;
		ptr->prev_ = back;
		
		ptr->next_ =head_;
		head_->prev_ = ptr;
	}
	
	void pop_back() {
		if(empty()) {
			throw exception();
		}
		
		Node* back = head_->prev_;
		Node* new_back = back->prev_;
		
		new_back -> next_ = head_;
		head_->prev_= new_back;
		
		delete back;
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
	
	class iterator {
		Node* curr_;
		
		iterator(Node* ptr)
		: curr_(ptr)
		{}
		
		
		friend class List;
	public:
		bool operator==(const iterator& other) {
			return curr_ == other.curr_;
		}
		
		bool operator!=(const iterator& other) {
			return ! operator==(other);
		}
	
		iterator& operator++() {
			curr_ = curr_ -> next_;
			return *this;
		}
		
		iterator operator++(int) {
			iterator res = *this;
			operator++();
			return res;
		}
	
		T& operator*() {
			return curr_ -> data_;
		}
	
	};
	
	iterator begin() {
		return iterator(head_->next_);
	}	
	
	iterator end() {
		return iterator(head_);
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
	// cout << li.back() << endl;
	
	li.pop_front();
	cout << li.front() << endl;
	
	
	li.push_back(-1);
	li.push_back(-2);
	
	cout << li.back() << endl;
	li.pop_back();
	
	cout << li.back() << endl;



	for(List<int>::iterator it=li.begin();
		it!=li.end(); ++it) {
		
		cout << *it << ' ';
	}
	cout << endl;
/*
	List<int>::iterator it=li.begin();
	List<int>::iterator it_end=li.end();
*/
	
	
	
	return 0;
}

