#include <algorithm>
#include <iterator>
#include <iostream>
#include <list>

using namespace std;

class IsOdd {

public:
	bool operator()(int val) {
		return val%2 == 1;
	}
};


int main() {
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int N = sizeof(a)/sizeof(a[0]);
	
	list<int> l(a, a+N);
	copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	IsOdd is_odd;
	
	list<int>::iterator it = remove_if(l.begin(), l.end(), is_odd);
	
	copy(l.begin(), it, ostream_iterator<int>(cout, " "));
	cout << endl;

	l.erase(it, l.end());
	copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	for(int i=0;i<10; ++i) {
		random_shuffle(a, a+N);
		copy(a, a+N, ostream_iterator<int>(cout, " "));
		cout << endl;	
	}


	return 0;
}

