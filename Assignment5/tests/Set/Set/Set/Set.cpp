#include <iostream>
#include "Set.h"
#include <algorithm>
using namespace std;

template <class T>
Set<T>::Set() {
	l = new list<T>;
}

template <class T>
Set<T>::~Set() {
	delete l;
}

template <class T>
void Set<T>::empty() {
	Set();
}

template <class T>
void Set<T>::insert(T element) {
	if (find((*l).begin(), (*l).end(), element) == (*l).end()) //checks if element is not in set, this ensures that there are no duplicates
	{
		(*l).push_front(element);
	}
}

template <class T>
void Set<T>::remove(T element)  {
	if (find((*l).begin(), (*l).end(), element) != (*l).end())
	{
		(*l).erase(find((*l).begin(), (*l).end(), element));
	}
}

template <class T>
bool Set<T>::member(T element){
	return find((*l).begin(), (*l).end(), element) != (*l).end();
}

template <class T>
bool Set<T>::isEmpty() {
	return (*l).empty();
}

template <class T>
typename Set<T>::Set Set<T>::unite(typename Set<T>::Set<T>& secondSet) {
	if (this->isEmpty()) {
		return secondSet;
	}
	else if ((secondSet).isEmpty()) {
		return *this;
	}
	Set<T> temp;
	list<T>* t = new list<T>;
	copy((*l).begin(), (*l).end(), back_inserter(*t));

	typename list<T>::template iterator<T> it;
	for (it = (*secondSet.l).begin(); it != (*secondSet.l).end(); it++)
	{
		t.insert(*it);
	}
	temp.l = t;

	return temp;
}

template <class T>
typename Set<T>::Set Set<T>::intersect(typename Set<T>::Set<T>& secondSet) {
	Set* temp = this->unite(secondSet);
	(*temp).remove_if([](const T elem) {
		return !(*secondSet.member(elem) || !this->member(elem));
		});
	return temp;
}

template <class T>
typename Set<T>::Set Set<T>::subtract(typename Set<T>::Set<T>& secondSet) {
	Set<T> temp;
	list<T>* n = new list<T>;
	n = *l;
	(n).remove_if([](const T elem) {
		return (*secondSet).member(elem);
	});
	temp.l = &n;
	return temp;
}

//Error VS C1075 "Kein übereinstimmendes Token gefunden"
template <class T>
typename Set<T>::Set Set<T>::symmDiff(typename Set<T>::Set<T>& secondSet) {
	return this->subtract(secondSet).unite(secondSet.subtract(this)); // (this \ secondSet) u (secondSet \ this)
}

// returns an array containing all the elements in the set
template <class T>
T* Set<T>::enumerate() {
	T arr = new T(l.size());

	int i = 0;
	typename list<T>::template iterator<T> it;
	for (it = (*l).begin(); it != (*l).end(); it++)
	{
		arr[i] = *it;
		i++;
	}
	return arr;
}

template <class T>
int Set<T>::getSize() {
	return (*l).size();
}

template <class T>
void Set<T>::printSet() {
	typename list<T>::template iterator<T> it;
	for (it = (*l).begin(); it != (*l).end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

template class Set<int>;


