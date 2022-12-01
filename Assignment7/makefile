# (Lines starting with # are comments)
# test.cpp contains the main function

all: test.o BinSearchTree.o
	g++ -o test test.o BinSearchTree.o

test.o: test.cpp BinSearchTree.h
	g++ -c test.cpp

Set.o: BinSearchTree.cpp BinSearchTree.h
	g++ -c BinSearchTree.cpp

clean:
	rm *.o test

