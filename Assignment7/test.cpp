#include<iostream>

#include "BinSearchTree.h"

using namespace std;

int main() {

	//ERROR: LNK2019 in VS - Verweis auf nicht aufgelöstes externes Symbol

	BinSearchTree<int> a;
	a.empty();
	
	if (a.isempty()) {
		cout << "a is empty" << endl;
	}
	else {
		cout << "a is not empty" << endl;
	}

	a.insert(1);//insert doesn't work
	a.insert(2);
	a.insert(3);
	a.insert(42);

	if (a.member(2)) {
		cout << "2 is member of a" << endl;
	}
	else {
		cout << "2 is not member of a" << endl;
	}

	a.del(2);//because insert does not work, delete aborts

	if (a.member(2)) {
		cout << "2 is member of a" << endl;
	}
	else {
		cout << "2 is not member of a" << endl;
	}

	return 0;
}
