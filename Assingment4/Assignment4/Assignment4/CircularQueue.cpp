#include <iostream>
#include "CircularQueue.h"
using namespace std;

//problem with this kind of impolementation is, that we cannot differenciate between a full and an empty circularqueue
//solutions: storing the number of elements
//or storing as a bool, if the last operation was insert or delete and checking by that then
//or just using modulo wehen working with end and frontindex, when reaching limit of int, reset - then you can check the difference


//need to check if queue is full, didn't do that most of the time

template <class T>
CircularQueue<T>::CircularQueue() {
	for (int i = 0; i < MAX_SIZE; i++) {
		data[i] = NULL;
	}
	frontIndex = 0;
	endIndex = 0;
}

template <class T>
CircularQueue<T>::~CircularQueue() {}

template <class T>
void CircularQueue<T>::enqueue(T element) {
	data[endIndex] = element;
	endIndex = (endIndex + 1) % MAX_SIZE;
}

template <class T>
void CircularQueue<T>::dequeue() {
	endIndex = (endIndex - 1) % MAX_SIZE;
}

template <class T>
T CircularQueue<T>::front() {
	return data[frontIndex];
}

template <class T>
bool CircularQueue<T>::isEmpty() {
	return frontIndex == endIndex;
}

template <class T>
bool CircularQueue<T>::isFull() {
	return (endIndex + 1 == frontIndex);
}

template <class T>
void CircularQueue<T>::printQueue () {
	for (int i = frontIndex; i < endIndex; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

template class CircularQueue<int>;

