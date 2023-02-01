# This is the makefile of the queues and linked list homework
# (Lines starting with # are comments)
# test.cpp contains the main function

all: test.o Queue.o CircularQueue.o
	g++ -o queues test.o Queue.o CircularQueue.o

test.o: test.cpp Queue.h CircularQueue.h
	g++ -c test.cpp

Queue.o: Queue.cpp Queue.h
	g++ -c Queue.cpp

CircularQueue.o: CircularQueue.cpp CircularQueue.h
	g++ -c CircularQueue.cpp

clean:
	rm *.o queues

