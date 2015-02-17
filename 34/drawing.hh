#ifndef DRAWING_HH__
#define DRAWING_HH__

#include <vector>

#include "shape.hh"

class Drawing: public Shape {
	std::vector<Shape*> shapes_;
public:
	void add_shape(Shape* sh);
	void print() const;
};

#endif
