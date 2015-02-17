#include "drawing.hh"


void
Drawing::add_shape(Shape* sh) {

	drawing_.push_back(sh);

}

void
Drawing::print() const {
	
	for(std::vector<Shape*>::const_iterator it=drawing_.begin();
		it!=drawing_.end();
		++ it) {
		
		(*it)->print();	
	}

}
