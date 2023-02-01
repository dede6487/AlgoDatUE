#include "Queue.h"
#include "CircularQueue.h"
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

/* 1. Implement statically a normal queue. Allow the usage of the whole space, by shifting it when reaches the last position. The queue should be initially populated with data read from a file called Integers.txt. The main function should additionally contain calls for removing and adding elements. When a shift happens, write a message on the console. When the allocated array is full, write a warning.
2. Implement statically a circular queue. The rest of requirements are as for problem 1.*/

void testQueue(int a[], int n) {
	Queue <int> q;
	cout << "Shifted queue" << endl;
	cout << "~~~~~~~~~~~~~" << endl;
	cout << "Is the queue empty? " << (q.isEmpty() ? "yes" : "no") << endl;
	cout << "Is the queue full? " << (q.isFull() ? "yes" : "no") << endl << endl;

	for(int i = 0; i < n; i++)
		q.enqueue(a[i]);
	cout << "Filled the queue from the file:" << endl;
	q.printQueue();
	cout << "Front element is: " << q.front() << endl;
	cout << "Is the queue empty? " << (q.isEmpty() ? "yes" : "no") << endl;
	cout << "Is the queue full? " << (q.isFull() ? "yes" : "no") << endl << endl;

	cout << "Try to insert element in the full queue:" << endl;
	q.enqueue(22);
	cout << endl;

	for(int i = 0; i < 4; i++)
		q.dequeue();
	cout << "Removed 4 elements from the queue:" << endl;
	q.printQueue();
	cout << "Insert 77, the queue needs to be shifted:" << endl;
	q.enqueue(77);
	q.printQueue();
	cout << "Is the queue empty? " << (q.isEmpty() ? "yes" : "no") << endl;
	cout << "Is the queue full? " << (q.isFull() ? "yes" : "no") << endl << endl;

	cout << "Remove 8 elements from a queue with 7:" << endl;
	for(int i = 0; i < 8; i++)
		q.dequeue();
	cout << "Is the queue empty? " << (q.isEmpty() ? "yes" : "no") << endl;
	cout << "Is the queue full? " << (q.isFull() ? "yes" : "no") << endl << endl;

	cout << "Call front() on an empty queue:" << endl;
	int f = q.front();
	cout << "The value returned should be some garbage: " << f << endl << endl;
	
}

void testCircularQueue(int a[], int n) {
	CircularQueue <int> q;
	cout << "Circular queue" << endl;
	cout << "~~~~~~~~~~~~~~" << endl;
	cout << "Is the queue empty? " << (q.isEmpty() ? "yes" : "no") << endl;
	cout << "Is the queue full? " << (q.isFull() ? "yes" : "no") << endl << endl;

	for(int i = 0; i < n; i++)
		q.enqueue(a[i]);
	cout << "Filled the queue from the file:" << endl;
	q.printQueue();
	cout << "Front element is: " << q.front() << endl;
	cout << "Is the queue empty? " << (q.isEmpty() ? "yes" : "no") << endl;
	cout << "Is the queue full? " << (q.isFull() ? "yes" : "no") << endl << endl;

	cout << "Try to insert element in the full queue:" << endl;
	q.enqueue(22);
	cout << endl;

	for(int i = 0; i < 4; i++)
		q.dequeue();
	cout << "Removed 4 elements from the queue:" << endl;
	q.printQueue();
	cout << "Insert 77, the end will move before the front:" << endl;
	q.enqueue(77);
	q.printQueue();
	cout << "Is the queue empty? " << (q.isEmpty() ? "yes" : "no") << endl;
	cout << "Is the queue full? " << (q.isFull() ? "yes" : "no") << endl << endl;

	cout << "Remove 8 elements from a queue with 7:" << endl;
	for(int i = 0; i < 8; i++)
		q.dequeue();
	cout << "Is the queue empty? " << (q.isEmpty() ? "yes" : "no") << endl;
	cout << "Is the queue full? " << (q.isFull() ? "yes" : "no") << endl << endl;

	cout << "Call front() on an empty queue:" << endl;
	int f = q.front();
	cout << "The value returned should be some garbage: " << f << endl << endl;
	
}

int main()
{
	ifstream inputFile;
	inputFile.open("../../Integers.txt");

	int number, n = 0;
	while (inputFile >> number)
		++n;
	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	int a[n];
	int i = 0;
	while (inputFile >> a[i++]);

	testQueue(a, n);
	testCircularQueue(a, n);
	//testList();
	
}


