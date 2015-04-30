#include <iostream>
#include <iterator>
#include <algorithm>
#include <list>

using namespace std;

class MultBy {
	int val_;
public:
	MultBy(int val)
	: val_(val)
	{}
	
	int operator()(int val) {
		return val* val_;
	}

};


int main() {


	ostream_iterator<int> it = ostream_iterator<int>(cout, "\n");
	
	*it = 5;
	*it = 6;
	*it = 42;
	
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int N=sizeof(a)/sizeof(a[0]);
	
	copy(a, a+N, ostream_iterator<int>(cout, " "));
	cout << endl;
	
	list<int> l(N);
	copy(a, a+N, l.begin());
	copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
		
	back_insert_iterator<list<int> > bii(l);
	*bii = 42;
	*bii = 43;
	copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	
	front_insert_iterator<list<int> > fii(l);
	*fii = -1;
	*fii = -2;
	copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	list<int> l1;
	copy(a, a+N, back_insert_iterator<list<int> >(l1));
	copy(l.begin(), l.end(),front_insert_iterator<list<int> >(l1));
	
	copy(l1.begin(), l1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	list<int> l3;
	transform(a, a+N, back_insert_iterator<list<int> >(l3),
				MultBy(3));
	
	copy(l3.begin(), l3.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	
	return 0;
}

