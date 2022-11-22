# (Lines starting with # are comments)
# test.cpp contains the main function

all: test.o Set.o
	g++ -o testS testS.o Set.o

test.o: testS.cpp Set.h
	g++ -c testS.cpp

Set.o: Set.cpp Set.h
	g++ -c Set.cpp

clean:
	rm *.o test

