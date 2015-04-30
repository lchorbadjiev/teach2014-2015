#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

class MultBy {
	int mult_;
public:
	MultBy(int val)
	: mult_(val)
	{}
	
	int operator()(int val) {
		return mult_*val;
	}

};

int main() {

	ostream_iterator<int> it(cout, "\n");

	*it = 1;
	++it;
	*it = 2;
	*it = 42;
	
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int N = sizeof(a)/sizeof(a[0]);
	
	copy(a, a+N, it);
	
	copy(a, a+N, ostream_iterator<int>(cout, ", "));
	cout << endl;
	
	cout << "-----------------------------" << endl;
	
	list<int> l(N);
	copy(a, a+N, l.begin());
	copy(l.begin(), l.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;
	
	back_insert_iterator<list<int> > bii(l);
	*bii = 42;
	*bii = 43;
	copy(l.begin(), l.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;

	front_insert_iterator<list<int> > fii(l);
	*fii = -1;
	*fii = -2;
	
	copy(l.begin(), l.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;

	copy(a, a+N, bii);
	copy(a, a+N, fii);
	copy(l.begin(), l.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;
	
	
	list<int> l3;
	MultBy m_3(3);
	transform(a, a+N, 
		back_insert_iterator<list<int> >(l3),
		m_3);
	copy(l3.begin(), l3.end(), ostream_iterator<int>(cout, ", "));
	cout << endl;
	
	
	return 0;
}

