#ifndef LLIST_H_
#define LLIST_H_
#define MAX_SIZE 100


template <class T>
class Stack {
private:
	T data[MAX_SIZE];
	int size;
public:
	Stack();
	~Stack();
	void push(T element);
	T pop();
	T top();
	bool isEmpty();
	void reset();
	void printStack ();
};

#endif
