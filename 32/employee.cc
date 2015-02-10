#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee {
// protected:
	string name_;
	long id_;
public:
	Employee(string name, long id)
	: name_(name),
	  id_(id)
	{}
	
	string get_name() const {
		return name_;
	}

	long get_id() const {
		return id_;
	}
	
	virtual void print() const {
		cout << "name: " << get_name() 
			 << ", id: " << get_id() << endl;
	}
};

class Manager: public Employee {

	int level_;
public:
	Manager(string name, long id, int level)
	: Employee(name, id),
	  level_(level)
	{}

	int get_level() const {
		return level_;
	}
	
	void print() const {
		Employee::print();
		cout << "\tlevel: " << get_level() << endl;
//		cout << "name: " << get_name() 
//			 << ", id: " << get_id() 
//			 << ", level: " << get_level() << endl;
	}
};

void print_all(vector<Employee*> all_employee) {
	for(vector<Employee*>::iterator it=all_employee.begin();
		it!=all_employee.end(); ++it) {
		
		(*it) -> print();	
	}
}



int main() {
	vector<Employee*> all;

	Employee e1("pesho", 1);
	// e1.name_;
//	e1.print();
	
//	cout << e1.get_name() << ", " << e1.get_id() << endl;

	Manager m1("gosho", 2, 33);
//	cout << m1.get_name() << ", " << m1.get_id()
//	     << ", " << m1.get_level() << endl;
//	m1.print();
	
//	Employee e2=m1;
//	e2.print();
	
	
	Employee* pe1=&e1;
	Employee* pe2=&m1;
	Employee& re2=m1;
	
	pe1->print();
	pe2->print();
	
	all.push_back(&e1);
	all.push_back(&m1);
	
	Manager m2("kyncho", 3, 42);
	all.push_back(&m2);
	Employee e2("mara", 4);
	all.push_back(&e2);
	
	print_all(all);
	
	
	return 0;
}

