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
	empty();
}

template <class T>
void LinkedList<T>::empty() {
	while (firstN != NULL) {
		Node* curr = firstN;
		firstN = next(firstN);
		delete curr;
	}
	firstN = NULL;
	lastN = NULL;
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
	if (node == NULL) return node;
	return node->next;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::prev(Node* node) {
	if (node == NULL) return node;
	return node->prev;
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
	if (node == NULL) return false;
	Node* curr = firstN;
	while (curr != NULL) {
		if (curr == node)
			return true;
		curr = next(curr);
	}
	return false;
}

template <class T>
void LinkedList<T>::insert(Node* node, T value){
//	cout << "Insert after: " << node << endl;
	Node* newNode = new(Node);
	newNode->data = value;
	newNode->prev = node;
	
	if (node == NULL) {
		newNode->next = firstN;
		firstN = newNode;
	}
	else {
		newNode->next = node->next;
		node->next = newNode;
	}
	if (newNode->next == NULL)
		lastN = newNode;
	else
		newNode->next->prev = newNode;
//	cout << "Inserted: " << newNode << " " << newNode->data << " " << newNode->prev << " " << newNode->next << endl;
//	cout << firstN << " " << lastN << endl;
}

template <class T>
void LinkedList<T>::remove(Node* node){
	if (not nodeInList(node)) {
		// queue underflow
		// print message, throw error or do nothing
		cout << "Node not in the list (remove)" << endl;
		return;
	}
	if (node == front()) 
		firstN = node->next;
	else 
		prev(node)->next = node->next;
	if (node == last())
		lastN = node->prev;
	else
		next(node)->prev = node->prev;
	delete node;
}

template <class T>
void LinkedList<T>::concat(LinkedList& tail){
	if (isEmpty()) {
		firstN = tail.front();
		lastN = tail.last();
		return;
	}
	lastN->next = tail.front();
	if (not tail.isEmpty()) {
		tail.front()->prev = lastN;
		lastN = tail.last();
	}
}

template <class T>
bool LinkedList<T>::isEmpty(){
	return firstN == NULL;
}

template <class T>
typename LinkedList<T>::Node* LinkedList<T>::find(T value){
	Node* curr = firstN;
	while (curr != NULL) {
		if (curr->data == value)
			return curr;
		curr = next(curr);
		
	}
	return NULL;
	
}

template <class T>
T LinkedList<T>::retrieve(Node* node){
	// check that node is in the list
	// by making the method private this would not be necessary anymore
	if (nodeInList(node))
		return node->data;
	// node not in the list
	// print message, throw error
	cout << "Node not in the list (retrieve)" << endl;
	T dummy; // it should be recognizable as dummy
	return dummy;

}

template <class T>
void LinkedList<T>::printList () {
	cout << "[ ";
	Node* curr = firstN;
	//cout << curr << endl;
	while (curr != NULL) {
		cout << curr->data << " ";
		curr = next(curr);
		//cout << curr << " ";
	}
	cout << "]" << endl;
}

template <class T>
void LinkedList<T>::printCompleteList () {
	cout << endl << "=====" << endl;
	cout << front() << endl;
	Node* curr = firstN;
	//cout << curr << endl;
	while (curr != NULL) {
		cout << curr->data << " " << curr << " " << curr->prev << " " << curr->next << " " << endl;
		curr = next(curr);
		//cout << curr << " ";
	}
	cout << last();
	cout << "=====" << endl;
}


template class LinkedList<int>;

