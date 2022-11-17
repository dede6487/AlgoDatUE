#include <iostream>
#include "Set.h"
using namespace std;

template <class T>
Set<T>::Set() {
}

template <class T>
Set<T>::~Set() {
}

template <class T>
void Set<T>::empty() {
}

template <class T>
void Set<T>::insert(T element) {
}

template <class T>
void Set<T>::remove(T element)  {
}

template <class T>
bool Set<T>::member(T element){
}

template <class T>
bool Set<T>::isEmpty() {
}

template <class T>
typename Set<T>::Set Set<T>::unite(typename Set<T>::Set<T>& secondSet) {
}

template <class T>
typename Set<T>::Set Set<T>::intersect(typename Set<T>::Set<T>& secondSet) {
}

template <class T>
typename Set<T>::Set Set<T>::subtract(typename Set<T>::Set<T>& secondSet) {
}

template <class T>
typename Set<T>::Set Set<T>::symmDiff(typename Set<T>::Set<T>& secondSet) {
}

// returns an array containing all the elements in the set
template <class T>
T* Set<T>::enumerate() {
}

template <class T>
int Set<T>::getSize() {
}

template <class T>
void Set<T>::printSet() {
}

template class Set<int>;


