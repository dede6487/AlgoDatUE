#include "Queue.h"
#include "CircularQueue.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

void testQueue(int a[], int n) {
	Queue <int> q;
	cout << "Is the queue empty? " << (q.isEmpty() ? "yes" : "no") << endl;
	cout << "Is the queue full? " << (q.isFull() ? "yes" : "no") << endl << endl;
	q.enqueue(7);
	q.printQueue();
	cout << q.front();
	q.dequeue();
	cout << endl;
}

void testCircularQueue(int a[], int n) {
	CircularQueue <int> q;
	cout << "Is the queue empty? " << (q.isEmpty() ? "yes" : "no") << endl;
	cout << "Is the queue full? " << (q.isFull() ? "yes" : "no") << endl << endl;
	q.enqueue(7);
	q.printQueue();
	cout << q.front();
	q.dequeue();
	cout << endl;
}

void testList() {
	LinkedList <int> l;

}

int main()
{
	ifstream inputFile;
	inputFile.open("Integers.txt");

	int number, n = 0;
	while (inputFile >> number)
		++n;
	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	int* a = new int[n];
	int i = 0;
	while (inputFile >> a[i++]);

	testQueue(a, n);
	testCircularQueue(a, n);
	testList();
}


