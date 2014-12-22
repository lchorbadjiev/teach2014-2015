#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

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
	bool visited_;
	
	string draw_wall(bool has_wall) const {
		return has_wall?"rlineto":"rmoveto";
	}
public:
	Cell(unsigned int row, unsigned int col)
	: row_(row), col_(col),
	  walls_(UP | RIGHT | DOWN | LEFT), // 1111
	  visited_(false)
	{}
	
	bool is_visited() const {
		return visited_;
	}
	
	Cell& visit() {
		visited_=true;
		return *this;
	}
	
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

	bool has_neighbour(const Cell& cell, Direction dir) {
		if(cell.get_row()==0 && dir==DOWN) {
			return false;
		}
		if(cell.get_row()==(height_-1) && dir==UP) {
			return false;
		}
		if(cell.get_col()==0 && dir==LEFT) {
			return false;
		}
		if(cell.get_col()==(width_-1) && dir==RIGHT) {
			return false;
		}
		return true;
	}
	
private:

	const static Direction DIRECTIONS[];
	const static unsigned NDIR = 4;
public:
	
	bool has_unvisited_neighbour(Cell& c) {
		for(unsigned d=0; d<NDIR; ++d) {
			Direction dir=DIRECTIONS[d];
			if(has_neighbour(c,dir)) {
				Cell& n=get_neighbour(c, dir);
				if(!n.is_visited()) {
					return true;
				}
			}
		}
		return false;
	}
	
	Direction get_random_unvisited_neighbour(Cell& c) {
		if(!has_unvisited_neighbour(c)) {
			throw BoardError();
		}
		
		while(true) {
			int d=rand()%NDIR;
			Direction dir=DIRECTIONS[d];
			if(has_neighbour(c,dir)) {
				Cell& n = get_neighbour(c,dir);
				if(!n.is_visited()) {
					return dir;
				}
			}
		}
	}
	
	Cell& drill(Cell& c, Direction dir) {
		c.unset_wall(dir);
		Cell& n=get_neighbour(c,dir);
		switch(dir) {
		case UP:
			n.unset_wall(DOWN);
			break;
		case DOWN:
			n.unset_wall(UP);
			break;
		case LEFT:
			n.unset_wall(RIGHT);
			break;
		case RIGHT:
			n.unset_wall(LEFT);
			break;
		default:
			throw BoardError();
		}
		return n;
	}
	
	void generate_maze(Cell& c) {
		c.visit();
		
		while(true) {
			if(!has_unvisited_neighbour(c)) {
				return;
			}
		
			Direction dir=get_random_unvisited_neighbour(c);
			Cell& n=drill(c, dir);
			generate_maze(n);
		}
	}
	
};
const Direction Board::DIRECTIONS[]={UP,LEFT,RIGHT,DOWN};

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
	Cell& c=board.get_cell(0, 9);
	board.generate_maze(c);
	board.draw();
	
	return 0;
}

