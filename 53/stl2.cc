#include <map>
#include <iostream>
#include <string>

using namespace std;


int main() {

	map<string,int> m;
	m["ala"] = 1;
	m["bala"] = 2;
	m["portokala"] = 3;
	
	cout << "m[ala]=" << m["ala"] << endl;
	
	for(map<string,int>::iterator it=m.begin();
		it!=m.end(); ++it) {
		
		cout << "map member:" << endl;
		pair<string, int> p = *it;
		cout << "p.first=" << p.first << endl;
		cout << "p.second=" << p.second << endl;
		cout << endl;
			
	}

	cout << "m.size()=" << m.size() << endl;
	cout << "m[foo]=" << m["foo"] << endl;
	cout << "m.size()=" << m.size() << endl;

	map<string, int>::iterator it=m.find("bar");
	if(it!=m.end()) {
		cout << "key <bar> found..." << endl;
	} else {
		cout << "key <bar> NOT found..." << endl;
	}
	
	m["ala"] = 42;
	cout << "m[ala]=" << m["ala"] << endl;
	
	return 0;
}

