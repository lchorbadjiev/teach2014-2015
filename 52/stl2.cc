#include <map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {

	map<string, int> mm;
	
	mm["ala"] = 1;
	mm["bala"] = 2;
	mm["portokala"] = 3;
	
	for(map<string, int>:: iterator it= mm.begin(); it!=mm.end(); ++it) {
		cout << "map element:" << endl;
		pair<string,int> p = *it;
		cout << "pair.first=" << p.first << ", pair.second="
			<< p.second << endl;
	}
	
	cout << "mm[ala]=" << mm["ala"] << endl;
	cout << "mm.size()=" << mm.size() << endl;
	
	cout << "mm[foo]=" << mm["foo"] << endl;
	cout << "mm.size()=" << mm.size() << endl;

	map<string, int>::iterator it=mm.find("bar");
	if(it!=mm.end()) {
		cout << "bar key found!!" << endl;
	} else {
		cout << "bar key NOT found!!" << endl;
	}
	cout << "mm.size()=" << mm.size() << endl;
	
	mm["ala"] = 42;
	cout << "mm[ala]=" << mm["ala"] << endl;	


	map<string, vector<int> > mv;

	return 0;
}

