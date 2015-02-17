#include <iostream>
using namespace std;

#include "drawing.hh"

void
Drawing::add_shape(Shape* sh) {
	shapes_.push_back(sh);
}

void
Drawing::print() const {
	cout << "Drawing{" << endl;
	for(std::vector<Shape*>::const_iterator it=shapes_.begin();
		it!=shapes_.end(); ++it) {
		
		(*it) -> print();
			
	}
	cout << "}" << endl;


}
