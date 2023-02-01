#include "BST.h"
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

/* Implement the data structure binary search tree with the functions empty, isempty, member, insert and delete. Check your implemented functions with appropriate input tests. */

int main()
{
	BST<int> tree;

	int number;
	ifstream inputfile;


	cout << "Is the tree empty? " << (tree.isEmpty() ? "yes" : "no") << endl;
	inputfile.open("../../BST.txt");
	cout << endl << "Create tree:" << endl;
	while (inputfile >> number) {
		tree.insert(number);
	}
	tree.printBST();
	cout << endl << "Is the tree empty? " << (tree.isEmpty() ? "yes" : "no") << endl;
	cout << "Is 20 in the list? " << (tree.isMember(20) ? "yes" : "no") << endl;
	cout << "Is -7 in the list? " << (tree.isMember(-7) ? "yes" : "no") << endl;
	cout << "Is 120 in the list? " << (tree.isMember(120) ? "yes" : "no") << endl;
	cout << "Is 17 in the list? " << (tree.isMember(17) ? "yes" : "no") << endl;

	cout << endl << "Remove:" << endl;
	tree.remove (20);
	cout << "Removed 20: ";
	tree.printBST();
	tree.remove (3);
	cout << "Removed 3: ";
	tree.printBST();
	tree.remove (50);
	cout << "Removed 50: ";
	tree.printBST();
	tree.remove (17);
	cout << "Removed 17, nothing happened: ";
	tree.printBST();

	// here the destructor for tree is called automatically
}


