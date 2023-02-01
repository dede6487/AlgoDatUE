# This is the makefile of the binary trees
# (Lines starting with # are comments)
# test.cpp contains the main function

all: test.o BinaryTree.o
	g++ -o test test.o BinaryTree.o

test.o: test.cpp BinaryTree.h
	g++ -c test.cpp

BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -c BinaryTree.cpp

clean:
	rm *.o test

