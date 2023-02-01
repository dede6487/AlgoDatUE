#include <iostream>
#include "CircularQueue.h"
using namespace std;

template <class T>
CircularQueue<T>::CircularQueue() {
	// if the queue is not empty, it points to the first element
	frontIndex = 0;
	// if queue is not empty, it points to the location next to the last element
	endIndex = 0;
	queueFull = false;
}

template <class T>
CircularQueue<T>::~CircularQueue() {}

template <class T>
void CircularQueue<T>::enqueue(T element) {
	if (isFull()) {
		// queue overflow
		// print message, throw error
		cout << "Queue overflow" << endl;
		return;
	}
	data[endIndex] = element;
	endIndex = (endIndex + 1) % MAX_SIZE;
	if (endIndex == frontIndex)
		queueFull = true;
}

template <class T>
void CircularQueue<T>::dequeue() {
	if (!isEmpty()) {
		frontIndex = (frontIndex + 1) % MAX_SIZE;
		queueFull = false;
	}
	else
		// queue underflow
		// print message, throw error
		cout << "Queue underflow (dequeue)" << endl;			
}

template <class T>
T CircularQueue<T>::front() {
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
bool CircularQueue<T>::isEmpty() {
	return not queueFull and (endIndex == frontIndex);
}

template <class T>
bool CircularQueue<T>::isFull() {
	return queueFull;
}

template <class T>
void CircularQueue<T>::printQueue () {
	cout << "[ ";
	if (not isEmpty()) {
		int n = endIndex;
		if (endIndex <= frontIndex)
			n += MAX_SIZE;
		for (int i = frontIndex; i < n; i++)
			cout << data[i % MAX_SIZE] << " ";
	}
	cout << "]" << endl;
}

template class CircularQueue<int>;

