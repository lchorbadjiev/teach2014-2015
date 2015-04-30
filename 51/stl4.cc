#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>

using namespace std;

class IsOdd {

public:

	bool operator()(int val) {
		return val % 2 == 1;
	}

};


int main() {
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int N = sizeof(a)/sizeof(a[0]);
	
	vector<int> v(a, a+N);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	IsOdd is_odd;
	
	vector<int>::iterator last = remove_if(v.begin(), v.end(), is_odd);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	copy(v.begin(), last, ostream_iterator<int>(cout, " "));
	cout << endl;
	
	v.erase(last, v.end());
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	
	
	for(int i=0;i<10;++i) {
		random_shuffle(a, a+N);
		copy(a, a+N, ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	return 0;
}

