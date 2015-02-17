all: draw

main.o: main.cc point.hh rectangle.hh shape.hh
point.o: point.cc point.hh
rectangle.o: rectangle.cc rectangle.hh shape.hh point.hh
drawing.o: drawing.cc drawing.hh shape.hh

draw: main.o point.o rectangle.o drawing.o
	g++ -Wall main.o point.o rectangle.o drawing.o -o draw


clean:
	rm -f *.o *~ draw a.out


