# This is the makefile of the queues and linked list homework
# (Lines starting with # are comments)
# test.cpp contains the main function

all: test.o Queue.o CircularQueue.o LinkedList.o
	g++ -o test test.o Queue.o CircularQueue.o LinkedList.o

test.o: test.cpp Queue.h CircularQueue.h LinkedList.h
	g++ -c test.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp

CircularQueue.o: CircularQueue.cpp CircularQueue.h
	g++ -c CircularQueue.cpp

LinkedList.o: LinkedList.cpp LinkedList.h
	g++ -c LinkedList.cpp

clean:
	rm *.o test

