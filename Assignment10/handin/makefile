# (Lines starting with # are comments)
# test.cpp contains the main function

all: Main.o AList.o AMatrix.o QuickSort.o
	g++ -o Main Main.o AList.o AMatrix.o QuickSort.o

Main.o: Main.cpp AList.h AMatrix.h QuickSort.h
	g++ -c Main.cpp

clean:
	rm *.o test

