#include <fstream>
#include <iostream>
#include <cstdlib>

using namespace std;

void error(const char* msg) {
	cerr << "error: " << msg << endl;
	exit(1);
}


int main(int argc, char* argv[]) {

	if(argc!=3) {
		error("wrong number of arguments");
	}

	ifstream in(argv[1]);
	if(!in) {
		error("problem opeing input file");
	}
	
	ofstream out(argv[2]);
	if(!out) {
		error("problem opening output file");
	}

	char ch;
	while(in.get(ch) && out) {
		out.put(ch);
	}

	if(!in.eof() || !out) {
		error("problem while coping...");
	}
	
	return 0;
}

