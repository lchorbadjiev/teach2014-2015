#include <iostream>
using namespace std;


int main() {
	char line[1025];
	
	while(cin) {
		cin.getline(line,1024);
		if(!cin) {
			break;
		}
		cout << line << endl;
	}


	return 0;
}

