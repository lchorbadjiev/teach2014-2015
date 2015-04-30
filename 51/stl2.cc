#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class PrintVal {

public:
	void operator()(const T& val) {
		cout << val << ", ";
	}
};

template<class T>
void print_all(const vector<T>& v) {
	PrintVal<T> print_val;
	for_each(v.begin(), v.end(), print_val);
	cout << endl;
}

class GreaterThan {
	int boundary_;
public:

	GreaterThan(int b)
	: boundary_(b)
	{}
	
	bool operator()(int val) {
		return val>boundary_;
	}
};


int main() {

	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int N = sizeof(a)/sizeof(a[0]);
	
	vector<int> v(a, a+N);
	
	print_all(v);

	vector<int>::iterator it=find(v.begin(), v.end(), 5);
	cout << "*it=" << *it << endl;
	
	it=find(v.begin(), v.end(), 42);
	if(it!=v.end()) {
		cout << "*it=" << *it << endl;
	} else {
		cout << "value 42 not found!!!" << endl;
	}
	
	GreaterThan gt5(5);
	
	cout << "gt5(5)=" << gt5(5) << endl;
	cout << "gt5(6)=" << gt5(6) << endl;
	
	it = find_if(v.begin(), v.end(), gt5);
	cout << "*it=" << *it << endl;

	GreaterThan gt42(42);
	it = find_if(v.begin(), v.end(), gt42);
	
	if(it!=v.end()) {
		cout << "*it=" << *it << endl;
	} else {
		cout << "value not found!!!" << endl;
	}
	
	int res = count_if(v.begin(), v.end(), gt5);
	cout << "res=" << res << endl;
	res=count_if(v.begin(), v.end(), gt42);
	cout << "res=" << res << endl;
	
	
	return 0;
}





