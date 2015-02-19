#include "context.hh"
#include "operation.hh"

#include <iostream>
using namespace std;

bool 
Context::data_empty() const {
	return data_stack_.empty();
}


unsigned
Context::data_size() const {
	return data_stack_.size();
}
	
void 
Context::data_push(double val) {
	data_stack_.push_back(val);
}

void 
Context::data_pop() {
	data_stack_.pop_back();
}

double 
Context::data_top() const {
	return data_stack_.back();
}


void
Context::data_dump() const {
	cout << "PD: ";
	for(std::vector<double>::const_iterator it=data_stack_.begin();
		it!=data_stack_.end(); ++it) {
		cout << *it << ' ';	
	}
	cout << endl;

}


void 
Context::op_add(Operation* op) {
	operations_.push_front(op);
}

Operation* 
Context::op_find(const std::string& token) const {
	for(std::deque<Operation*>::const_iterator it=operations_.begin();
		it!=operations_.end(); ++it) {
	
		if(token == (*it) -> get_token()) {
			return *it;
		}
		
	}
	
	return 0;
}









