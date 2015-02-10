#include <vector>
#include <iostream>
using namespace std;


bool is_hit(int c1, int r1,
			int c2, int r2) {
	if(c1 == c2 || r1 == r2) {
		return true;
	}

	if(c1-r1 == c2 - r2) {
		return true;
	}
			
	if(c1+r1 == c2+r2) {
		return true;
	}
	
	return false;
}

void print_sol(int board[]) {
	for(int col=0; col<8; col++) {
		cout << board[col] << ", ";
	}
	cout << endl;
}

void solve(int board[], int col) {
	for(int row=0; row<8; row++) {
	
		bool is_ok=true;
		for(int c=0; c<col; c++) {
			if(is_hit(c, board[c], col, row)) {
				is_ok = false;
				break;
			}
		}
		
		if(is_ok) {
			board[col]=row;
			if(col<7) {
				solve(board, col+1);
			} else {
				print_sol(board);
				return;
			}
		}
	}
} 



int main() {
	int board[] = {-1,-1,-1,-1, -1,-1,-1,-1};

	solve(board, 0);



	return 0;	
}
