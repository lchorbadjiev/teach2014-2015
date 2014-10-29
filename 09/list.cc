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
	list<int> l(a,a+10);
	
	cout << "l.size()=" << l.size() << endl;
	cout << "l.empty()=" << l.empty() << endl;
	print(l);
		
	l.push_back(10);
	l.push_front(-1);
	print(l);

	list<int>::iterator it=l.begin();
	l.insert(it,-2);
	it=l.end();
	l.insert(it, 11);
	
	print(l);

	cout << "l.front()=" << l.front() << endl;
	cout << "l.back()=" << l.back() << endl;
	print(l);
	

	l.pop_front();
	l.pop_back();
	print(l);


	it=l.begin();
	++it;
	l.erase(it);
	print(l);
	
	l.erase(l.begin(), l.end());
	cout << "l.empty()=" << l.empty() << endl;
	l.clear();
	cout << "l.empty()=" << l.empty() << endl;
	
	
	return 0;
}
