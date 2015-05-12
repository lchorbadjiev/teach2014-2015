#include <functional>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;


int main() {
	
	plus<double> pl;
	
	cout << "pl(1,2)=" << pl(1,2) << endl;
	
	minus<double> m;
	cout << "m(1,2)=" << m(1,2) << endl;
	
	
	negate<double> n;
	cout << "n(1)=" << n(1) << endl;
	
	
	equal_to<int> eq;
	cout << "eq(1,2)=" << eq(1,2) << endl;
	cout << "eq(1,1)=" << eq(1,1) << endl;
	
	
	logical_and<bool> land;
	cout << "land(true, true)=" << land(true, true) << endl;
	cout << "land(true, false)=" << land(true, false) << endl;
	
	// fun(X) -> greater<int>(X, 3);
	
	binder2nd<greater<int> > gt0=bind2nd(greater<int>(), 0);
	
	cout << "gt0(1)=" << gt0(1) << endl;
	cout << "gt0(0)=" << gt0(0) << endl;

	int a[] = {0,1,2,3,4,5,6,7,8,9};
	int N=sizeof(a)/sizeof(a[0]);
	
	vector<int> v(a, a+N);
	
	vector<int>::iterator vend = 
		remove_if(v.begin(), v.end(),
				  bind2nd(less<int>(), 3));
	
	copy(v.begin(),vend, ostream_iterator<int>(cout, " "));
	cout << endl;	

	
	
	
	
	

	return 0;
}

