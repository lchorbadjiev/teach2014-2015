#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum Direction {
	NONE=0,
	UP=1,       // 0001
	RIGHT=1<<1, // 0010
	DOWN=1<<2,  // 0100
	LEFT=1<<3   // 1000
};


class Cell {
	static const int PS_SIZE=20;

	unsigned int row_;
	unsigned int col_;
	unsigned int walls_;
	
	string draw_wall(bool has_wall) const {
		return has_wall?"rlineto":"rmoveto";
	}
public:
	Cell(unsigned int row, unsigned int col)
	: row_(row), col_(col),
	  walls_(UP | RIGHT | DOWN | LEFT) // 1111
	{}
	
	unsigned int get_row() const {
		return row_;
	}
	unsigned int get_col() const {
		return col_;
	}
	
	// 1100 1100
	// 0100 0001
	// 0100 0000
	
	bool has_wall(Direction dir) const {
		return walls_ & dir;
	}
	
	// 1100 1100
	// 0001 1000
	// 1101 1100
	
	Cell& set_wall(Direction dir) {
		// walls_ = walls_ | dir
		walls_ |= dir;
		
		return *this;
	}
	
	//  1100 1100
	//  1000 0001
	//~ 0111 1110
	//  0100 1100
	
	Cell& unset_wall(Direction dir) {
		walls_ &= ~dir;
		return *this;
	}
	
	
	void draw() const {
		cout << col_*PS_SIZE << ' ' << row_*PS_SIZE << ' '
			<< "moveto" << endl;
		cout << PS_SIZE << " " << 0 << " " 
			<< draw_wall(has_wall(DOWN)) << endl;
		cout << 0 << " " << PS_SIZE << " " 
			<< draw_wall(has_wall(RIGHT)) << endl;
		cout << -PS_SIZE << " " << 0 << " " 
			<< draw_wall(has_wall(UP)) << endl;
		cout << 0 << " " << -PS_SIZE << " " 
			<< draw_wall(has_wall(LEFT)) << endl;
	}
};

class BoardError {};

class Board {
	unsigned int width_;
	unsigned int height_;
	vector<Cell> board_;
public:
	Board(unsigned int width, unsigned int height)
	: width_(width),
	  height_(height)
	{
		for(unsigned int row=0; row<height_; ++row) {
			for(unsigned int col=0; col<width_; ++col) {
				board_.push_back(Cell(row, col));
			}
		}
	}

	Cell& get_cell(unsigned int row, unsigned int col) {
		return board_[row*width_+col];
	}

	const Cell& get_cell(unsigned int row, unsigned int col) const {
		return board_[row*width_+col];
	}


	void draw() const {
		cout << "newpath" << endl;
		for(unsigned int row=0; row< height_; ++row) {
			for(unsigned int col=0; col< width_; ++col) {
				get_cell(row, col).draw();
			}
		}
		cout << "stroke" << endl;
		cout << "showpage" << endl;
	}
	
	Cell& get_neighbour(const Cell& cell, Direction dir) {
		int row=cell.get_row();
		int col=cell.get_col();
		
		switch(dir) {
		case UP:
			row+=1;
			break;
		case RIGHT:
			col+=1;
			break;
		case DOWN:
			row-=1;
			break;
		case LEFT:
			col-=1;
			break;
		default:
			throw BoardError();
		}
		if(row<0 || row>=height_ || col<0 || col>=width_) {
			throw BoardError();
		}
		return get_cell(row, col);
	}

};

int main() {
/*
	Cell c1(0,0);
	cout << c1.has_wall(UP) << endl;
	c1.unset_wall(UP);
	cout << c1.has_wall(UP) << endl;
	c1.set_wall(UP);
	cout << c1.has_wall(UP) << endl;
*/
	Board board(20, 20);

	Cell& c1=board.get_cell(1,1);
	Cell& c2=board.get_cell(2,1);
	c1.unset_wall(UP);
	c2.unset_wall(DOWN);

	Cell& c3 = board.get_neighbour(c2, UP);
	c2.unset_wall(UP);
	c3.unset_wall(DOWN);
	
	board.draw();
	
	return 0;
}

