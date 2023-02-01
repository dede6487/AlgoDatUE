# This is the makefile of the linked list homework
# (Lines starting with # are comments)
# test.cpp contains the main function

all: test.o LinkedList.o
	g++ -o lists test.o LinkedList.o

test.o: test.cpp LinkedList.h
	g++ -c test.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

clean:
	rm *.o lists

