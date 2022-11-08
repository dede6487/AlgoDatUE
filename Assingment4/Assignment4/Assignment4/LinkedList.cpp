#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
LinkedList<T>::LinkedList(){
	*firstN = NULL;
	*lastN = NULL;
}

template <class T>
LinkedList<T>::~LinkedList(){
}

template <class T>
void LinkedList<T>::empty() {
	return LinkedList<T>::LinkedList();
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::front() {
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::last() {
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::next(Node *node) {
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::prev(Node* node) {
}

template <class T>
bool LinkedList<T>::bol(Node* node){
}

template <class T>
bool LinkedList<T>::eol(Node* node){
}

template <class T>
bool LinkedList<T>::nodeInList(Node* node){
}

template <class T>
void LinkedList<T>::insert(Node* node, T value){
}

template <class T>
void LinkedList<T>::remove(Node* node){
}

template <class T>
void LinkedList<T>::concat(LinkedList& tail){
}

template <class T>
bool LinkedList<T>::isEmpty(){
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(T value){
}

template <class T>
T LinkedList<T>::retrieve(Node* node){
}

template <class T>
void LinkedList<T>::printList () {
}

template <class T>
void LinkedList<T>::printCompleteList () {
}

template class LinkedList<int>;

