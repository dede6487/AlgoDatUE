#include <iostream>
#include "Queue.h"
using namespace std;

template <class T>
Queue<T>::Queue() {
	frontIndex = 0;
	endIndex = 0;
}

template <class T>
Queue<T>::~Queue() {}

template <class T>
void Queue<T>::enqueue(T element) {
	if (isFull()) {
		// queue overflow
		// print message, throw error
		cout << "Queue overflow" << endl;
		return;
	}
	if (endIndex == MAX_SIZE) {
		cout << "The queue is shifted" << endl; // control print, it should be removed in a real life application
		for (int i = frontIndex; i < endIndex; i++)
			data[i - frontIndex] = data[i];
		endIndex -= frontIndex;
		frontIndex = 0;

	}
	data[endIndex++] = element;
}

template <class T>
void Queue<T>::dequeue() {
	if (!isEmpty())
		frontIndex++;
	else
		// queue underflow
		// print message, throw error
		cout << "Queue underflow (dequeue)" << endl;		
}

template <class T>
T Queue<T>::front() {
	if (isEmpty()) {
		// queue underflow
		// print message, throw error
		cout << "Queue underflow (front)" << endl;
		T dummy; // it should be recognizable as dummy
		return dummy;
	}
	return data[frontIndex];
}

template <class T>
bool Queue<T>::isEmpty() {
	return frontIndex == endIndex;
}

template <class T>
bool Queue<T>::isFull() {
	return endIndex - frontIndex == MAX_SIZE; 
}

template <class T>
void Queue<T>::printQueue () {
	cout << "[ ";
	for (int i = frontIndex; i < endIndex; i++)
		cout << data[i] << " ";
	cout << "]" << endl;
}

template class Queue<int>;

