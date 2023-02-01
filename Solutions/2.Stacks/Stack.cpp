#include <iostream>
#include "Stack.h"
using namespace std;

template <class T>
Stack<T>::Stack() {
	size = 0;
}

template <class T>
Stack<T>::~Stack() {}


template <class T>
void Stack<T>::push(T element) {
        if (size >= MAX_SIZE) {
		// stack overflow
		// print message, throw error
		//cout << "Stack overflow" << endl;
		return;
	}
	data[size++] = element;
}

template <class T>
T Stack<T>::pop() {
	if (size <= 0) {
		// stack underflow
		// print message, throw error
		//cout << "Stack underflow (pop)" << endl;
		T dummy; // it should be recognizable as dummy
		return dummy;
	}
	return data[--size];
}

template <class T>
T Stack<T>::top() {
	if (size <= 0) {
		// stack underflow
		// print message, throw error
		//cout << "Stack underflow (top)" << endl;
		T dummy; // it should be recognizable as dummy
		return dummy;
	}
	return data[size - 1];
}

template <class T>
bool Stack<T>::isEmpty() {
	return !size;
}

template <class T>
void Stack<T>::reset() { 
	size = 0;
}

template <class T>
void Stack<T>::printStack () {
	cout << "[ ";
	for (int i = 0; i < size; i++)
		cout << data[i] << " ";
	cout << "]" << endl;
}

template class Stack<char>;
template class Stack<int>;



