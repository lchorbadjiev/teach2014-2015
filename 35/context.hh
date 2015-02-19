#ifndef CONTEXT_HH__
#define CONTEXT_HH__

#include <vector>
#include <deque>
#include <string>

class Operation;

class Context {
	std::vector<double> data_stack_;
	std::deque<Operation*> operations_;
		
public:
	bool data_empty() const;
	unsigned data_size() const;
	
	void data_push(double val);
	void data_pop();
	double data_top() const;
	
	void data_dump() const;
	
	void op_add(Operation* op);
	Operation* op_find(const std::string& token) const;
	
};


#endif
