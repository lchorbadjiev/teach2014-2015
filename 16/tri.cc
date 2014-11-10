#include <iostream>
using namespace std;

int main() {
	int a=1;
	int b=2;
	
	int c = a>b?a:b;
	
	cout << ((a>b)?a:b) << endl;
	cout << ((a>b)? (a+1) : (b-2)) << endl;
	cout << ((a<b)? (a+41) : (b-44)) << endl;
	
	return 0;
}
