#include "Set.h"
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
	Set<int> s1, s2;
	s1.empty();
	s2.empty();

	ifstream inputfile;

	inputfile.open("Set.txt");

	int size;
	inputfile >> size;
	int elem;

	for (int i = 1; i <= size; i++) {
		inputfile >> elem;
		s1.insert(elem);
	}

	inputfile >> size;

	for (int i = 1; i <= size; i++) {
		inputfile >> elem;
		s2.insert(elem);
	}

	inputfile.close();

	s1.printSet();
	s2.printSet();

	Set<int> u, i, sub, sym;

	u = s1.unite(s2);
	i = s1.intersect(s2);
	sub = s1.subtract(s2);
	sym = s1.symmDiff(s2);

	u.printSet();
	i.printSet();
	sub.printSet();
	sym.printSet();


}


