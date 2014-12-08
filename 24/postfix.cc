/*
HW: negate 
	1 negate -> -1
	*
	/
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class PostfixError{};

class PostfixContext {
	vector<double> stack_;
	
	double pop() {
		if(stack_.empty()) {
			throw PostfixError();
		}
		double val = stack_.back();
		stack_.pop_back();
		return val;
	}
	
public:
	void push(double val) {
		stack_.push_back(val);
	}
	
	bool has(const string& token) {
		if(token=="+" || token=="-") {
			return true;
		}
		return false;
	}	

	void execute(const string& op) {
		if(op=="+") {
			double res=pop() + pop();
			stack_.push_back(res);
			cout << "res: " << res << endl;
			
		} else if(op=="-") {
			double a1=pop();
			double a2=pop();
			
			double res=a2-a1;
			stack_.push_back(res);
			cout << "res: " << res << endl;
		}
	}
};


class Postfix {
	istream& in_;
	PostfixContext& context_;
public:

	Postfix(istream& in, PostfixContext& context)
	: in_(in),
	  context_(context)
	{}

	void run() {
		while(true) {
			string token;
			in_ >> token;
			
			if(!in_) {
				break;
			}
		
			cout << "token: <" << token << ">" << endl;
			
			if(context_.has(token)) {
				context_.execute(token);				
			} else {
				istringstream instr(token);
				double val=0.0;
				
				instr >> val;
				if(!instr) {
					cerr << "unexpected operation: " << token << endl;
					break;
				}
				cout << "val=" << val << endl;
				context_.push(val);
				
			}
		}
	}


};




int main() {
	PostfixContext context;

	Postfix calc(cin, context);
	try {
		calc.run();
	} catch(PostfixError& to_catch) {
		cout << "wrong number of arguments to operation" << endl;
	}
	
	return 0;
}



