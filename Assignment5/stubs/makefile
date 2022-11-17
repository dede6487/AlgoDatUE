# This is the makefile of the queues and linked list homework
# (Lines starting with # are comments)
# test.cpp contains the main function

all: test.o Set.o BinaryTree.o LinkedList.o
	g++ -o test test.o Set.o BinaryTree.o LinkedList.o

test.o: test.cpp Set.h BinaryTree.h LinkedList.h
	g++ -c test.cpp

Set.o: Set.cpp Set.h
	g++ -c Set.cpp

BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -c BinaryTree.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

clean:
	rm *.o test

