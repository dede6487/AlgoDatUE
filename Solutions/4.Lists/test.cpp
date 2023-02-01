#include "LinkedList.h"
#include <iostream>
#include <cstdio>
using namespace std;

/* Implement the algebra List2 from the main lecture with the help of doubled linked lists. Produce the list l=<2,4,6,...,100> and execute find(l,50), delete(l,50) and find(l,50) to test your functions. */

int main()
{
	LinkedList<int> l, l1, l2, l3;

	cout << "Create list:" << endl;
	for(int i = 2; i <= 100; i+=2) {
		typename LinkedList<int>::Node* last = l.last();
		l.insert(last, i);
	}
	l.printList();

	cout << endl << "Insert 0 at the beginning:" << endl;
	l.insert(NULL, 0);
	l.printList();

	cout << endl << "Is 50 in the list? " << (l.find(50) != NULL ? "yes" : "no") << endl;
	cout << "First element is: " << l.retrieve(l.front()) << endl;
	cout << "Last element is: " << l.retrieve(l.last()) << endl;

	typename LinkedList<int>::Node* node50 = l.find(50);
	cout << endl << "Insert 51 after 50:" << endl;
	l.insert(node50, 51);
	l.printList();

	cout << endl << "Find and retrieve:" << endl;
	cout << "Is 50 in the list? " << (l.find(50) != NULL ? "yes" : "no") << endl;
	cout << "First element is: " << l.retrieve(l.front()) << endl;
	cout << "Last element is: " << l.retrieve(l.last()) << endl;
	cout << "50 correctly found and retrived: " << l.retrieve(node50) << endl;
	cout << "NULL cannot be retrived: ";
	l.retrieve(NULL);

	l.remove(node50);
	cout << endl << "Remove:" << endl;
	cout << "50 was removed from the list:" << endl;
	l.printList();
	cout << "Is 50 in the list? " << (l.find(50) != NULL ? "yes" : "no") << endl;
	cout << "50 cannot be retrieved anymore, garbage should be returned: " << l.retrieve(node50) << endl;
	cout << "50 cannot be removed anymore:" << endl;
	l.remove(node50);
	l.printList();
	cout << "NULL cannot be removed" << endl;
	l.remove(NULL);
	l.printList();
	l.remove(l.front());
	cout << "First element was removed from the list:" << endl;
	l.printList();
	l.remove(l.last());
	cout << "Last element was removed from the list:" << endl;
	l.printList();

	cout << endl << "Concatenate the lists:" << endl;
	for(int i = 2; i <= 10; i+=2) {
		typename LinkedList<int>::Node* last = l1.last();
		l1.insert(last, i);
	}

	for(int i = 71; i <= 80; i+=2) {
		typename LinkedList<int>::Node* last = l2.last();
		l2.insert(last, i);
	}
	cout << "l1 = ";
	l1.printList();
	cout << "l2 = ";
	l2.printList();
	cout << "l3 = ";
	l3.printList();
	cout << "l3 + l3 = ";
	l3.concat(l3);
	l3.printList();
	cout << "l1 + l3 = ";
	l1.concat(l3);
	l1.printList();
	cout << "l3 + l2 = ";
	l3.concat(l2);
	l3.printList();
	cout << "l1 + l2 = ";
	l1.concat(l2);
	l1.printList();
	// here the destructor for l, l1 and l2 is called automatically
}


