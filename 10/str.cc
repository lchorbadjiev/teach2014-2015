#include <string>
#include <iostream>

using namespace std;

int main() {
	string s1="Hello";
	string s2("World");
	
	string str;
	
	str=s1+ ' ' + s2 + "!";
	cout << "str=" << str << endl;

	//'!'
	//"!"
	
	for(int i=0;i<str.size(); ++i) {
		cout << str[i] << ' ' << str.at(i) << endl;
	}
	
	cout << str.c_str() << endl;
	
	
	cout << str.substr(6, 5) << endl;
	
	if(s1>s2) {
		cout << "s1=" << s1 << endl;
	} else {
		cout << "s2=" << s2 << endl;
	}
	
	
	return 0;
}

