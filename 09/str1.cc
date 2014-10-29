#include <iostream>
#include <string>
using namespace std;

int main() {
	int a;
	string str;
/*	
	cin >> a;
	if(cin) {
		cout << "a=" << a << endl;	
	} else {
		cout << "error!!" << endl;
	}
*/
/*
	while(cin >> str) {
		cout << '<' << str << '>' << endl;
	}
*/
	while(cin) {
		getline(cin, str);
		cout << '<' << str << '>' << endl;
	}


	return 0;
}

