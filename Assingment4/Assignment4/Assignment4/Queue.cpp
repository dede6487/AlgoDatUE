#include <iostream>
#include "Queue.h"
using namespace std;

template <class T>
Queue<T>::Queue() {
	for (int i = 0; i < MAX_SIZE; i++) {
		data[i] = NULL;
	}
	frontIndex = 0;
	endIndex = 0;
}

template <class T>
Queue<T>::~Queue() {
	//delete data;
}

template <class T>
void Queue<T>::enqueue(T element) {
	data[endIndex] = element;
	endIndex = (endIndex + 1) % MAX_SIZE;
}

template <class T>
void Queue<T>::dequeue() {//check if empty
	endIndex = (endIndex - 1) % MAX_SIZE;
}

template <class T>
T Queue<T>::front() {
	return data[frontIndex];
}

template <class T>
bool Queue<T>::isEmpty() {
	return frontIndex == endIndex;
}

template <class T>
bool Queue<T>::isFull() { 
	return (endIndex - frontIndex) == MAX_SIZE; //wrong
}

template <class T>
void Queue<T>::printQueue () {
	for (int i = frontIndex; i <= endIndex; i++)
	{
		cout << data[i];
	}
	cout << endl;
}

template class Queue<int>;

