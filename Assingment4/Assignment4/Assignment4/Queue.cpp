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
	//sdelete data;
}

template <class T>
void Queue<T>::enqueue(T element) {
	if (endIndex + 1 != MAX_SIZE - 1)
	{
		data[endIndex] = element;
		endIndex++;
	}
	else if(frontIndex == 100)
	{
		cout << "Queue is full!" << endl;
	}
	else
	{
		cout << "shifiting the data..." << endl;
		for (int i = 0; i <= endIndex - frontIndex; i++)
		{
			data[i] = data[frontIndex + i];
		}
		endIndex = frontIndex;
		frontIndex = 0;
	}
}

template <class T>
void Queue<T>::dequeue() {//check if empty
	endIndex--;
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
	return (endIndex - frontIndex) == MAX_SIZE;
}

template <class T>
void Queue<T>::printQueue () {
	for (int i = frontIndex; i < endIndex; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
}

template class Queue<int>;

