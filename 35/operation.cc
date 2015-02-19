#include "operation.hh"

Operation::Operation(const std::string& type,
					 const std::string& token)
: type_(type),
  token_(token)
{}

const std::string&
Operation::get_type() const {
	return type_;
}


const std::string&
Operation::get_token() const {
	return token_;
}
