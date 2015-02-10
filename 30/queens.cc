#include <iostream>
#include <vector>
using namespace std;


static const int N=8;

bool under_attack(vector<int>& board, int row, int col) {
	for(int r=0; r<row; r++) {
		int c=board[r];
		
		if(c == col) {
			return true;
		}
		int delta_col = (col>c)?col-c:c-col;
		if( delta_col == row-r ) {
			return true;
		}
	}
	return false;
}

void print_sol(vector<int>& board) {
	for(int row=0; row<N; row++) {
		for(int col=0; col<N; col++) {
			cout << ' ';
			cout << ((board[row] == col)?'Q':'-');
			cout << ' ';
		}
		cout << endl;
	}
	cout << endl << endl;
}


void solve(vector<int>& board, int row) {
	if(row==N) {
		// solution found!!
		print_sol(board);
		return;
	}

	for(int col=0; col<N; col++) {
		if(!under_attack(board, row, col)) {
			board[row]=col;
			solve(board, row+1);
		}
	}
	// solve(board, row+1);
}


int main() {
	vector<int> board(N, -1);


	solve(board, 0);
	
	return 0;
}

