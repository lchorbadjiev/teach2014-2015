#include <cstdlib>
#include <iostream>
using namespace std;

class Foo {
	int bar_;
public:
	Foo(int bar=0)
	: bar_(bar)
	{
		cout << "Foo() called..." << endl;
	}
	
	int get_bar() const {
		return bar_;
	}
	
	void set_bar(int bar) {
		bar_=bar;
	}

};

int main() {
	Foo* foo =new Foo;
	
	cout << foo->get_bar() << endl;
	foo->set_bar(42);
	cout << foo->get_bar() << endl;
	
	delete foo;

	foo = new Foo(42);
	cout << foo->get_bar() << endl;
	delete foo;

	foo = new Foo[10];
	for(int i=0;i<10;i++) {
		foo[i].set_bar(i*42);
		cout << foo[i].get_bar() << endl;
	}
	delete [] foo;

	return 0;
}


/*
int main() {
	Foo* foo = (Foo*) malloc(sizeof(Foo));
	
	foo->set_bar(42);
	cout << foo->get_bar() << endl;

	free(foo);


	foo = (Foo*) malloc(10*sizeof(Foo));
	
	for(int i=0;i<10;i++) {
		foo[i].set_bar(42*i);
		cout << foo[i].get_bar() << endl;
	}
	
	free(foo);
	
	return 0;
}
*/
