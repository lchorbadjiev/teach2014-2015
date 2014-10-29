#include <string>
#include <iostream>
using namespace std;


int main() {
	string s1="Hello";
	string s2("World");
	
	string s3=s1+" " + s2 + "!";
	cout << s3 << endl;

	cout << "s3.size()=" << s3.size() << endl;
	cout << "s3.length()=" << s3.length() << endl;
	
	for(int i=0;i<s3.size(); ++i) {
		cout << s3[i] << ' ' << s3.at(i) << endl;
	}

//	s3.pop_back();
	cout << s3 << endl;
	
	s3.c_str();
	
	return 0;
}

