#include <sstream>
#include <string>

#include <iostream>
using namespace std;


int main() {
	string str = "+3.14 1.11E-11";
	double pi=0.0;
	double epsilon=0.0;
	
	istringstream in(str);
	in >> pi;
	in >> epsilon;
	
	cout << "pi=" << pi << endl;
	cout << "eps=" << epsilon << endl;

	ostringstream out;
	out << "pi=" << pi << ' ' << "eps=" << epsilon << ' ';
	
	string ostr = out.str();
	cout << "ostr=|" << ostr << "|" << endl;
	
	return 0;
}

