#include <iostream>
#include "BinaryTree.h"
using namespace std;

template <class T>
BinaryTree<T>::BinaryTree() {
	root = NULL;
}

template <class T>
BinaryTree<T>::BinaryTree(Node* root) {
	this->root = copyTree(root);
}

template <class T>
typename BinaryTree<T>::Node* BinaryTree<T>::copyTree(Node* node) {
	if (node == NULL) return node;
	Node* newNode = new Node;
	newNode->data = node->data;
	newNode->left = copyTree(node->left);
	newNode->right = copyTree(node->right);
	return newNode;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
	empty();
}

template <class T>
void BinaryTree<T>::empty() {
	emptyRec(root);
	root = NULL;
}

template <class T>
void BinaryTree<T>::emptyRec(Node* node) {
	if (node != NULL){
		emptyRec(node->left);
		emptyRec(node->right);
		delete node;
	}
}

// efficient but unsafe version
// the trees in the arguments should be copied in order
// to not allow making degenerate trees or the
// partial destruction of the current tree
template <class T>
void BinaryTree<T>::makeTree(BinaryTree& leftT, T element, BinaryTree& rightT) {
	if (root != NULL) {
		// tree is not empty, it cannot be made again
		// print message, throw error
		cout << "Tree is empty, key cannot be recreated" << endl;
		return;
	}
	
	root = new Node;
	root->data = element;
	root->left = leftT.root;
	root->right = rightT.root;
}

template <class T>
T BinaryTree<T>::key() {
	if (root != NULL)
		return root->data;
	// tree is empty
	// print message, throw error
	cout << "Tree is empty, key cannot be retrieved" << endl;
	T dummy; // it should be recognizable as dummy
	return dummy;
}

template <class T>
BinaryTree<T> BinaryTree<T>::leftTree() {
	BinaryTree leftT(root == NULL? NULL : root->left);
	return leftT;
}

template <class T>
BinaryTree<T> BinaryTree<T>::rightTree() {
	BinaryTree rightT(root == NULL? NULL: root->right);
	return rightT;
}

template <class T>
void BinaryTree<T>::printBinaryTree() {
	cout << "[ ";
	printBinaryTreeRec(root);
	cout << "]" << endl;
}

template <class T>
void BinaryTree<T>::printBinaryTreeRec (Node* node) {
	if (node == NULL) return;
	printBinaryTreeRec(node->left);
	cout << node->data << " ";
	printBinaryTreeRec(node->right);
}

template class BinaryTree<int>;

