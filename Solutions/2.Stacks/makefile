# This is the makefile of the arithmetic expression evaluation
# (Lines starting with # are comments)
# expression.cpp contains the main function

all: evaluator.o Stack.o
	g++ -o evaluator evaluator.o Stack.o

expression.o: evaluator.cpp Stack.h
	g++ -c evaluator.cpp

stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp
clean:
	rm *.o evaluator

