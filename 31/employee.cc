#include <iostream>
#include <string>
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
			 << ", id: " <<  get_id() 
			 << endl;
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
		cout << "name: " << get_name()
			 << ", id: " <<  get_id() 
			 << ", level: " << get_level() << endl;
	}
};

int main() {
	Employee e1("pesho",1);


	Manager m1("gosho", 2, 33);
	cout << m1.get_name() << ", " << m1.get_id() 
		 << ", " << m1.get_level() << endl;

	e1.print();
	m1.print();

	Employee e2=m1;
	e2.print();
	
	Employee* pe1=&e1;
	Employee* pe2=&m1;

	pe1->print();
	pe2->print();
	
	return 0;
}

