# (Lines starting with # are comments)
# test.cpp contains the main function

all: Main.o
	g++ -o Main Main.o

Main.o: Main.cpp MergeSort.h InsertionSort.h
	g++ -c Main.cpp MergeSort.h InsertionSort.h

clean:
	rm *.o Main

