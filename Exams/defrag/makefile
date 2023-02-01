# This is the makefile of the binary trees
# (Lines starting with # are comments)
# test.cpp contains the main function

all: test.o GraphMat.o
	g++ -o test test.o GraphMat.o

test.o: test.cpp GraphMat.h
	g++ -c test.cpp

GraphMat.o: GraphMat.cpp GraphMat.h
	g++ -c GraphMat.cpp

clean:
	rm *.o test

