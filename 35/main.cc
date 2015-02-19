#include "postfix.hh"
#include "context.hh"
#include "binary_operation.hh"


#include <iostream>
using namespace std;


int main() {
	Context context;
	
	context.op_add(new PlusOperation());
	
	Postfix postfix(context, cin);

	postfix.run();

	return 0;
}
