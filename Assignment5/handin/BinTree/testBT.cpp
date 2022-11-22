#include "BinaryTree.h"
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
	BinaryTree<int> a, b, c;
	a = a.empty();
	b = b.empty();

	c.makeTree(a ,5 , b);

	cout << c.key() << endl;

 	c.printBinaryTree(); //because of data type int, cpp automatically reads NULL as 0, so it prints the last two NULLs in root too
}


