#include <iostream>
#include <vector>
using namespace std;


int main() {
	vector<int> v1;

	cout << "v1.size()=" << v1.size() << endl;
	cout << "v1.emtpy()=" << v1.empty() << endl;

	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	
	cout << "v1.size()=" << v1.size() << endl;
	cout << "v1.emtpy()=" << v1.empty() << endl;
	cout << "v1.capacity()=" << v1.capacity() << endl;
	v1.push_back(4);
	v1.push_back(5);

	cout << "v1.size()=" << v1.size() << endl;
	cout << "v1.capacity()=" << v1.capacity() << endl;
	
	for(int i=0;i<v1.size();++i) {
		cout << "v1[" << i << "]=" << v1[i] << endl;
		cout << "v1.at(" << i << ")=" << v1.at(i) << endl;
	}
	
	// int a = v1[6];
	// int b = v1.at(6);
	
	cout << "v1.size()=" << v1.size() << endl;
	v1.pop_back();
	cout << "v1.size()=" << v1.size() << endl;

	cout << "v1.front()=" << v1.front() << endl;
	cout << "v1.back()=" << v1.back() << endl;
	
	
	vector<int> v2(10);
	cout << "v2.size()=" << v2.size() << endl;
	
	for(int i=0;i<v2.size();++i) {
		v2[i]=i*42;
	}
	
	int a[] = {0,1,2,3,4,5,6,7,8,9};
	cout << "*a=" << (*a) << endl;
	cout << "*(a+9)=" << (*(a+9)) << endl;
	
	//??? a+10
	
	vector<int> v3(a,a+10);
	for(int i=0;i<v3.size();++i) {
		cout << v3[i] << endl;
	}
	
	vector<int>::iterator it;
	
	it=v3.begin();
	cout << (*it) << endl;
	++it;
	cout << (*it) << endl;

	v3.erase(it);
	it=v3.begin();
	v3.insert(it, -1);


	for(vector<int>::iterator it1=v3.begin();
		it1!=v3.end();
		++it1) {
		
		cout << (*it1) << endl;	
	}
	
	v3.erase(v3.begin(), v3.end());
	cout << "v3.empty()=" << v3.empty() << endl;

	
	return 0;
}

