#include "postfix.hh"
#include "context.hh"
#include "operation.hh"

#include <string>
#include <sstream>


Postfix::Postfix(Context& context, std::istream& in)
: context_(context),
  in_(in)
{}


void 
Postfix::run() {
	std::string token;

	while(in_ >> token) {
		Operation* op=context_.op_find(token);
		if(op!=0) {
			op->eval(context_);
			context_.data_dump();
		} else {
			std::istringstream converter(token);
			double n=0.0;
			converter>>n;
			
			if(converter) {
				context_.data_push(n);
				context_.data_dump();
			} else {
				std::cerr << "can't interpret token: " 
						<< token << std::endl;
			}
		}
	}
}


