#ifndef POSTFIX_HH__
#define POSTFIX_HH__

#include <iostream>


class Context;


class Postfix {
	Context& context_;
	std::istream& in_;
public:
	Postfix(Context& context, std::istream& in);

	void run();

};



#endif
