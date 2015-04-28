#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void error(const char* msg) {
	cerr << "error: " << msg << endl;
	exit(1);
}

int main(int argc, char* argv[]) {
	if(argc!=3) {
		error("no right number of arguments");
	}
	
	ifstream in(argv[1]);
	if(!in) {
		error("problem opening input file");	
	}

	ofstream out(argv[2]);
	if(!out) {
		error("problem opening output file");
	}
	char ch;
	
	while(in.get(ch)) {
		out.put(ch);
	}

	if(!in.eof() || !out) {
		error("problem copyting input to output file");
	}

	return 0;
}

