# (Lines starting with # are comments)
# test.cpp contains the main function

all: test.o AVL.o
	g++ -o test test.o AVL.o

test.o: test.cpp AVL.h
	g++ -c test.cpp

Set.o: AVL.cpp AVL.h
	g++ -c AVL.cpp

clean:
	rm *.o test

