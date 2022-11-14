#include <iostream>
#include "LinkedList.h"
using namespace std;

template <class T>
LinkedList<T>::LinkedList(){
	firstN = NULL;
	lastN = NULL;
}

template <class T>
LinkedList<T>::~LinkedList(){

}

template <class T>
LinkedList<T> LinkedList<T>::empty() {
	return LinkedList<T>::LinkedList();
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::front() {
	return firstN;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::last() {
	return lastN;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::next(Node *node) {
	return (*node).next;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::prev(Node* node) {
	return (*node).prev;
}

template <class T>
bool LinkedList<T>::bol(Node* node){
	return node == firstN;
}

template <class T>
bool LinkedList<T>::eol(Node* node){
	return node == lastN;
}

template <class T>
bool LinkedList<T>::nodeInList(Node* node){
	while (true)
	{
		Node* i = firstN;
		if ((*i).data == (*node).data && (*i).next == (*node).next && (*i).prev == (*node).prev) {
			return true;
		}
		if (i = lastN)
		{
			return false;
		}
		i = (*i).next;
	}
}

template <class T>
void LinkedList<T>::insert(Node* node, T value){

}

template <class T>
void LinkedList<T>::remove(Node* node){
	//we assume, that node is element of the linked list
	
	(*(*node).next).prev = (*node).prev;
	(*(*node).prev).next = (*node).next;

	delete (*node).next;
	delete (*node).prev;
	delete node; //also delete pointers
}

template <class T>
void LinkedList<T>::concat(LinkedList& tail){
	(*lastN).next = tail.firstN;
	(*tail.firstN).prev = lastN;
	lastN = tail.lastN;
}

template <class T>
bool LinkedList<T>::isEmpty(){
	return lastN == NULL && firstN == NULL;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(T value){
	while (true)
	{
		Node* i = firstN;
		if ((*i).data == value) {
			return i;
		}
		if (i == lastN)
		{
			return NULL;
		}
		i = (*i).next;
	}
}

template <class T>
T LinkedList<T>::retrieve(Node* node){
	//verstehe noch nicht ganz was das macht
	return NULL;
}

template <class T>
void LinkedList<T>::printList () {
	while (true)
	{
		Node* i = firstN;
		
		cout << (*i).data << ", ";

		if (i == lastN)
		{
			break;
		}
		i = (*i).next;
	}
	cout << endl;
}

template <class T>
void LinkedList<T>::printCompleteList () {
	while (true)
	{
		Node* i = firstN;

		cout << "(" << (*i).prev << " - " << (*i).data << " - " << (*i).next << ")";

		if (i == lastN)
		{
			break;
		}
		i = (*i).next;
	}
	cout << endl;
}

template class LinkedList<int>;

