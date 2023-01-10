# (Lines starting with # are comments)
# test.cpp contains the main function

all: Main.o DistPoly.o
	g++ -o Main Main.o DistPoly.o

Main.o: Main.cpp DistPoly.h
	g++ -c Main.cpp

DistPoly.o: DistPoly.cpp DistPoly.h Monom.h
	g++ -c DistPoly.cpp

clean:
	rm *.o test

