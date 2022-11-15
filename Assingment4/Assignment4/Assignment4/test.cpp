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
	cout << "Is the list empty? " << (l.isEmpty() ? "yes" : "no") << endl;
	LinkedList<int>::Node* f = l.front();
	l.insert(f, 7);
	cout << (*l.front()).data << endl;
	//cout << (*l.last()).data << endl;
	//l.printList();
	//l.printCompleteList();
	//LinkedList<int>::Node* n = l.find(7);
	//cout << (*n).data;
	//l.remove(l.front());
	cout << endl;
}

//there are still many problems with the linked list - did not have enough time to fix them
//iterating through the list doesn't work, because the insert operation is faulty

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


