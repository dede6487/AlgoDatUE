#include <iostream>
#include "BST.h"
using namespace std;

template <class T>
BST<T>::BST(){
	root = NULL;
}

template <class T>
BST<T>::~BST(){
	empty();
}

template <class T>
void BST<T>::empty() {
	emptyR(root);
}


template <class T>
void BST<T>::emptyR(Node* node) {
	if (node != NULL){
		emptyR(node->left);
		emptyR(node->right);
		delete node;
	}
}


template <class T>
void BST<T>::insert(T value){
	root = insertR(root, value);
}

template <class T>
typename BST<T>::Node* BST<T>::insertR(Node* node, T& value){
	if (node == NULL) {
		Node* newNode = new(Node);
		newNode->data = value;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}

	if (value < node->data)
		node->left = insertR(node->left, value);
	else // or (if value > node->data)
		node->right = insertR(node->right, value);
}


template <class T>
T BST<T>::minValue(Node* node){
	// since the procedure is private we have control on how we call it:
	// never for an empty node, thus no test is needed
	T result = node->data;
	while (node->left != NULL) {
		result = node->left->data; 
		node = node->left;
	}
	return result;
}

template <class T>
void BST<T>::remove(T value){
	root = removeR(root, value);
}

template <class T>
typename BST<T>::Node* BST<T>::removeR(Node* node, T& value){
	if (node == NULL)
		return node;
	if (value < node->data) 
		node->left = removeR(node->left, value);
	else if (value > node->data) 
		node->right = removeR(node->right, value);
	else {
		Node* tempNode;
		if (node->left == NULL) {
			tempNode = node->right;
			delete node;
			return tempNode;
		}
		else if (node->right == NULL) {
			tempNode = node->left;
			delete node;
			return tempNode;
		}
		node->data = minValue(node->right);
		node->right = removeR(node->right, node->data);
	}
}

template <class T>
bool BST<T>::isMember(T value){
	return isMemberR(root, value);
}

template <class T>
bool BST<T>::isMemberR(Node* node, T& value){
	if (node == NULL) return false;
	if (node->data == value) return true;
	if (node->data > value) return isMemberR(node->left, value);
	return isMemberR(node->right, value);
}

template <class T>
bool BST<T>::isEmpty(){
	return root == NULL;
}

template <class T>
void BST<T>::printBST () {
	cout << "[ ";
	printBSTR(root);
	cout << "]" << endl;
}

template <class T>
void BST<T>::printBSTR (Node* node) {
	if (node == NULL) return;
	printBSTR(node->left);
	cout << node->data << " ";
	printBSTR(node->right);
}

template class BST<int>;

