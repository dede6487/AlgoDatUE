#ifndef SET_H_INCLUDED
#define SET_H_INCLUDED
#include "LinkedList.h"

template <class T = int>
class Set {
private:
	LinkedList<T> *l;

public:
	Set();
	~Set();
	void empty();
	void insert(T element);
	void remove(T element);
	bool member(T element);
	bool isEmpty();
	Set unite(Set& secondSet);
	Set intersect(Set& secondSet);
	Set subtract(Set& secondSet);
	Set symmDiff(Set& secondSet);
	T* enumerate();
	int getSize();
	void printSet();
};

#endif //SET_H_INCLUDED
