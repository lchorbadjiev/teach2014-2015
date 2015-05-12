#include <functional>
#include <iostream>

using namespace std;


int main() {

	plus<double> fpl;
	minus<double> fminus;
	
	cout << "plus(1,2)=" << fpl(1,2) << endl;
	cout << "minus(1,2)=" << fminus(1,2) << endl;
	
	
	equal_to<int> feq;
	cout << "equal_to(1,1)=" << feq(1,1) << endl;
	cout << "equal_to(1,2)=" << feq(1,2) << endl;
	
	logical_and<bool> fand;
	cout << "logical_and(true, true)=" << fand(true,true) << endl;
	cout << "logical_and(true, false)=" << fand(true,false) << endl;
	
	// find(v.begin(), v.end(), feq(42,??))
	
	// fun(X) -> feq(42, X)
	// pred(X) -> X==42??
	
	binder1st<equal_to<int> > pred42 = bind1st(equal_to<int>(),42);
	cout << "pred42(41)=" << pred42(41) << endl;
	cout << "pred42(42)=" << pred42(42) << endl;
	
	
	binder1st<less<int> > less5 =bind1st(less<int>(), 5); // less(5, X)
	cout << "less5(4)=" << less5(4) << endl;
	cout << "less5(5)=" << less5(5) << endl;
	cout << "less5(6)=" << less5(6) << endl;
	
	binder2nd<less<int> > less5s = bind2nd(less<int>(), 5); // less(X, 5)
	cout << "less5s(4)=" << less5s(4) << endl;
	cout << "less5s(5)=" << less5s(5) << endl;
	cout << "less5s(6)=" << less5s(6) << endl;
	
	
	return 0;
}

