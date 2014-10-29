#include <list>
#include <iostream>
using namespace std;

void print(list<int>& l) {
	for(list<int>::iterator it=l.begin();
		it!=l.end(); ++it) {
		cout << (*it) << ' ';	
	}
	cout << endl;
}

int main() {
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	list<int> l(a, a+10);
	
	print(l);
	
	l.push_back(10);
	l.push_front(-1);
	
	print(l);
	
	l.pop_back();
	l.pop_front();
	
	print(l);
	
	cout << l.front() << endl;
	cout << l.back() << endl;
	
	list<int>::iterator it=l.begin();
	it++;
	l.insert(it, 42);
	
	it=l.end();
	--it;
	l.insert(it, 42);
	print(l);
	
	it=l.begin();
	++it;
	l.erase(it);
	
	print(l);
	
	// l.erase(l.begin(), l.end());
	l.clear();
	
	cout << "l.empty()=" << l.empty() << endl;
	
	
	
	return 0;
}

