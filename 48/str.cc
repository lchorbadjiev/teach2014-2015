#include <sstream>
#include <string>
#include <iostream>
using namespace std;


int main() {
	string str="3.14 -1.11E-10";
	double pi=0.0;
	double epsilon=0.0;

	istringstream in(str);
	in >> pi;
	cout << "in.good()=" << in.good() << endl;

	in >> epsilon;
	cout << "pi=" << pi << endl;
	cout << "eps=" << epsilon << endl;

	cout << "in.bad()=" << in.bad() << endl;
	cout << "in.eof()=" << in.eof() << endl;
	
	string str1="ala bala";
	double val=0.0;
	
	istringstream in1(str1);
	in1>>val;
	if(in1) {
		cout << "success: val=" << val << endl;
	} else {
		cout << "error reading val!!!!" << endl;
	}
	
	ostringstream out;
	out << pi << ' ' << epsilon << ' ';
	
	cout << "out.str()=|" << out.str() << "|" << endl;
	
	return 0;
}

