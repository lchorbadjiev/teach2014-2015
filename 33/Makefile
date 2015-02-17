all: draw

point.o: point.cc point.hh
main.o: main.cc point.hh rectangle.hh
rectangle.o: rectangle.cc rectangle.hh point.hh shape.hh
drawing.o: drawing.cc drawing.hh shape.hh

draw: main.o point.o rectangle.o drawing.o
	g++ main.o point.o rectangle.o drawing.o -o draw


clean:
	rm -f *.o *~ draw

