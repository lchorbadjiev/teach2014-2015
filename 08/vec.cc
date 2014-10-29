#include <iostream>
#include <vector>
using namespace std;


int main() {
	vector<int> v1;
	cout << "v1.empty()=" << v1.empty() << endl;
	cout << "v1.size()=" << v1.size() << endl;
	
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	cout << "v1.empty()=" << v1.empty() << endl;
	cout << "v1.size()=" << v1.size() << endl;
	cout << "v1.capacity()=" << v1.capacity() << endl;

	v1.push_back(4);
	v1.push_back(5);
	
	cout << "v1.size()=" << v1.size() << endl;
	cout << "v1.capacity()=" << v1.capacity() << endl;

	v1.pop_back();
	cout << "v1.size()=" << v1.size() << endl;
	cout << "v1.capacity()=" << v1.capacity() << endl;
	

	vector<int> v2(10);
	cout << "v2.size()=" << v2.size() << endl;
	cout << "v2.capacity()=" << v2.capacity() <<endl;	
	
	for(int i=0;i<v2.size();++i) {
		v2[i]=i*42;
		v2.at(i)=i*42;
	}

	for(int i=0;i<v2.size();++i) {
		cout << v2[i] << ' ' << v2.at(i) << ' ';
	}
	cout << endl;
	
//	int a=v2.at(11);
//	int a=v2[11];

	int a[] = {0,1,2,3,4,5,6,7,8,9};
	// *a, *(a+9), a+10
	vector<int> v3(a, a+10);
	
	for(int i=0;i<10;i++) {
		cout << v3[i] << ' ';
	}
	cout << endl;
	
	vector<int>::iterator it;
	it=v3.begin();
	cout << (*it) << endl;
	it++;
	cout << (*it) << endl;

	for(vector<int>::iterator it1=v3.begin();
		it1!=v3.end(); ++it1) {
		
		cout << (*it1) << ' ';
	}	
	cout << endl;
	
	it=v3.begin();
	v3.insert(it, -1);
	it=v3.end();
	v3.insert(it, 10);
	
	for(vector<int>::iterator it1=v3.begin();
		it1!=v3.end(); ++it1) {
		
		cout << (*it1) << ' ';
	}
	// v3[0]=-13;	
	cout << endl;
	
	it=v3.begin();
	v3.erase(it);
	for(vector<int>::iterator it1=v3.begin();
		it1!=v3.end(); ++it1) {
		
		cout << (*it1) << ' ';
	}
	cout << endl;
	
	v3.erase(v3.begin(), v3.end());
	
	cout << "v3.empty()=" << v3.empty() << endl;
	
	
	return 0;
}


