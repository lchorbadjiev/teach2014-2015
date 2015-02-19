#include "binary_operation.hh"
#include "context.hh"

BinaryOperation::BinaryOperation(const std::string& token)
: Operation("binary", token)
{}

void
BinaryOperation::eval(Context& context) const {
	if(context.data_size()<2) {
		// throw error!!!!
	}
	
	double a2=context.data_top();
	context.data_pop();
	
	double a1=context.data_top();
	context.data_pop();
	
	double res= op(a1, a2);
	
	context.data_push(res);
	
}



PlusOperation::PlusOperation()
: BinaryOperation("+")
{}

double 
PlusOperation::op(double a1, double a2) const {
	return a1+a2;
}








