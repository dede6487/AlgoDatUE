# (Lines starting with # are comments)
# test.cpp contains the main function

all: Main.o AdjMAtrix.o
	g++ -o Main Main.o AdjMatrix.o

Main.o: Main.cpp AdjMatrix.h
	g++ -c Main.cpp

clean:
	rm *.o test

