#ifndef OPERATION_HH__
#define OPERATION_HH__

#include <string>

class Context;

class Operation {
	std::string type_;
	std::string token_;
	
public:
	Operation(const std::string& type,
			  const std::string& token);

	const std::string& get_type() const;
	const std::string& get_token() const;
	
	virtual void eval(Context& context) const = 0;

};

#endif
