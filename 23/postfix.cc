#include <iostream>
#include <string>
#include <sstream>
#include <list>
using namespace std;

class PostfixError{};

class PostfixContext {
	list<double> stack_;
	
	double pop() {
		if(stack_.empty()) {
			throw PostfixError();
		}
		double res=stack_.back();
		stack_.pop_back();
		return res;
	}
public:

	void push(double val) {
		stack_.push_back(val);
	}
	
	bool has(const string& op) {
		if(op=="+" || op=="-") {
			return true;
		}
		if(op=="neg") {
			return true;
		}
		return false;
	}
	
	void execute(const string& op) {
		if(op=="+") {
			double res = pop()+pop();
			cout << "res: " << res << endl;
			stack_.push_back(res);
		} else if(op=="-") {
			double a1=pop();
			double a2=pop();
			double res = a2-a1;
			cout << "res: " << res << endl;
			stack_.push_back(res);
		} else if(op=="neg") {
			double res=-pop();
			cout << "res: " << res << endl;
			stack_.push_back(res);
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
			cin >> token;
			if(!cin) {
				break;
			}
			if(context_.has(token)) {
				context_.execute(token);
			} else {
				istringstream instr(token);
				double val = 0.0;
				instr >> val;
				if(!instr) {
					cerr << "Unexpected token: <" << token
						 << ">" << endl;
					break;
				} else {
					context_.push(val);
				}
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
		cerr << "not enough arguments to operation..." << endl;
	}
	
	return 0;
}

