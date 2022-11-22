# This is the makefile of the queues and linked list homework
# (Lines starting with # are comments)
# test.cpp contains the main function

all: testBT.o BinaryTree.o
	g++ -o testBT testBT.o BinaryTree.o

test.o: testBT.cpp BinaryTree.h
	g++ -c testBT.cpp

BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -c BinaryTree.cpp

clean:
	rm *.o test

