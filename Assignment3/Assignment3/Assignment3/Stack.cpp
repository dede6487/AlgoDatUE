#include <iostream>
#include "Stack.h"
using namespace std;

template <class T>
Stack<T>::Stack() {
	for (int i = 0; i < MAX_SIZE; i++) {
		data[i] = NULL;
	}
	size = 0;
}

template <class T>
Stack<T>::~Stack() {
	//delete data;
}


template <class T>
void Stack<T>::push(T element) {
	if (size < MAX_SIZE) {
		data[size] = element;
		size++;
	}
	else {
		cout << "Error: overflow, out of Range(MAX_SIZE, Push())" << endl;
		abort();//bad practice,  dont use abort, because the user of the class might want to do sth else if this does not work
		//better, throw error
	}
	
}

template <class T>
T Stack<T>::pop() {
	if (size >= 0) {
		T temp = data[size-1];
		size--;
		return temp;
	}
	else {
		cout << "Error: Stack is empty (pop())" << endl;
		abort();
	}
}

template <class T>
T Stack<T>::top() {
	if (size > 0) {
		return data[size-1];
	}
	else {
		cout << "Error: Stack is empty (pop())" << endl;
		abort();
	}
}

template <class T>
bool Stack<T>::isEmpty() {
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}

template <class T>
void Stack<T>::reset() { //empty
	size = 0;
}

template <class T>
void Stack<T>::printStack () {
	cout << "[";
	for (int i = 0; i < size; i++) {
		cout << data[i] << ", ";
	}
	cout << "]" << endl;
}

template class Stack<char>;
template class Stack<int>;



