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
	
	List(const List& other)
	: head_(new Node())
	{
		head_->prev_=head_;
		head_->next_=head_;

		Node* ptr=other.head_->next_;
		while(ptr!=other.head_) {
			push_back(ptr->data_);
			ptr = ptr->next_;
		}
	}
	
	List& operator=(const List& other) {
	
		if(this!=&other) {
			while(!empty()) {
				pop_front();
			}
		
			Node* ptr=other.head_->next_;
			while(ptr!=other.head_) {
				push_back(ptr->data_);
				ptr = ptr->next_;
			}
			
		}
		
		return *this;
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
	class const_iterator{
	
	};
	
	class iterator {
		Node* element_;
		
		iterator(Node* ptr)
		: element_(ptr)
		{}
		
		friend class List;
	public:
		bool operator==(const iterator& other) const {
			return element_ == other.element_;
		}
		bool operator!=(const iterator& other) const {
			return ! operator==(other);
		}
		
		iterator& operator++() {
			element_=element_->next_;
			return *this;
		}
		
		iterator operator++(int) {
			iterator res=*this;
			operator++();
			return res;
		}
		
		T& operator*() {
			return element_-> data_;
		}
		
	};

	iterator begin() {
		return iterator(head_->next_);
	}

	iterator end() {
		return iterator(head_);
	}

	const_iterator begin() const {
	
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

	
	List<int> lo(li);
	
	
	while(!lo.empty()) {
		lo.pop_front();
	}
	
	cout << lo.empty() << endl;
	cout << li.empty() << endl;
	
	lo = li;
	cout << lo.empty() << endl;
	while(!lo.empty()) {
		cout << lo.front() << ' ';
		lo.pop_front();
	}
	
	cout << endl;
	
	
	
	for(List<int>::iterator it=li.begin();
		it!=li.end(); ++it) {
		
		cout << *it << ' ';	
	}
	cout << endl;
		
	return 0;
}

