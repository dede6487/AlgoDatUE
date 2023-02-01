# This is the makefile of the binary search trees homework
# (Lines starting with # are comments)
# test.cpp contains the main function

all: test.o BST.o
	g++ -o bstrees test.o BST.o

test.o: test.cpp BST.h
	g++ -c test.cpp

LinkedList.o: BST.cpp BST.h
	g++ -c BST.cpp

clean:
	rm *.o bstrees

