#include <iostream>
#include <vector>
using namespace std;

enum Direction {
	NONE = 0,
	UP = 1,           // 0001
	RIGHT = 1 << 1,   // 0010
	DOWN = 1 << 2,    // 0100
	LEFT = 1 << 3     // 1000
};

class Cell {
	static const int PS_SIZE = 25;
	
	unsigned int row_;
	unsigned int col_;
	unsigned int walls_;
public:
	Cell(unsigned int row, unsigned int col)
	: row_(row),
	  col_(col),
	  walls_(UP | RIGHT | DOWN | LEFT) // 1111
	{}
	
	unsigned int get_row() const {
		return row_;
	}
	
	unsigned int get_col() const {
		return col_;
	}
	
	Cell& set_row(unsigned int row) {
		row_=row;
		return *this;
	}
	
	Cell& set_col(unsigned int col) {
		col_=col;
		return *this;
	}
	
	//  1100 1100
	//  0001 1000
	//  0000 1000
	
	bool has_wall(Direction dir) {
		return walls_ & dir;
	}
	
	// 1100 1100 
	// 0001 1000
	// 1101 1100
	
	void set_wall(Direction dir) {
		// walls_ = walls_ | dir;
		walls_ |= dir;   
	}
	
	//  1100 1100
	//  1000 0001
	//~ 0111 1110
	//  0100 1100
	
	void unset_wall(Direction dir) {
		// walls_ = walls_ & ~dir;
		walls_ &= ~dir;
	}	
	
	void draw() const {
		cout << col_*PS_SIZE << ' ' << row_*PS_SIZE
		     << " moveto" << endl;
		cout << PS_SIZE << " " << 0 << " " << "rlineto" << endl;
		cout << 0 << " " << PS_SIZE << " " << "rlineto" << endl;
		cout << -PS_SIZE << " " << 0 << " " << "rlineto" << endl;
		cout << 0 << " " << -PS_SIZE << " " << "rlineto" << endl;
	}
};

class Board {

	unsigned int width_;
	unsigned int height_;
	vector<Cell> board_;

public:
	Board(unsigned int width, unsigned int height)
	: width_(width),
	  height_(height)
	{
		for(unsigned int row=0; row<height_; row++) {
			for(unsigned int col=0; col<width_; col++) {
				board_.push_back(Cell(row, col));
			}
		}
	}
	
	Cell& at(unsigned int row, unsigned int col) {
		return board_[row*width_+col];
	}
	
	const Cell& at(unsigned int row, unsigned int col) const {
		return board_[row*width_+col];
	}
	
	void draw() const {
		cout << "newpath" << endl;
		for(unsigned int row=0;row<height_; ++row) {
			for(unsigned int col=0; col<width_; ++ col) {
				at(row, col).draw();
			}
		}
		cout << "stroke" << endl;
		cout << "showpage" << endl;
	}
	
};


int main() {
/*
	Cell c1(0,1);
	
	cout << c1.has_wall(UP) << endl;
	c1.unset_wall(UP);
	cout << c1.has_wall(UP) << endl;
	c1.set_wall(UP);
	cout << c1.has_wall(UP) << endl;
*/
	Board b(20,20);
	b.draw();
	
	return 0;
}



