#include <iostream>
#include "BinaryTree.h"
using namespace std;

template <class T>
BinaryTree<T>::BinaryTree() {
	root = NULL;
}

template <class T>
BinaryTree<T>::~BinaryTree() {
}

template <class T>
BinaryTree<T> BinaryTree<T>::empty() {
	BinaryTree* temp = new BinaryTree;
	Node* root_ = new Node;
	(*root_).data = NULL;
	(*root_).left = NULL;
	(*root_).right = NULL;
	(*temp).root = root_;
	return *temp;
}

template <class T>
void BinaryTree<T>::makeTree(BinaryTree& leftT, T element, BinaryTree& rightT) {
	BinaryTree* temp = new BinaryTree;
	*temp = empty();
	(*((*temp).root)).data = element;
	(*((*temp).root)).left = ((leftT).root);
	(*((*temp).root)).right = ((rightT).root);
	this->root = (*temp).root;
}

template <class T>
T BinaryTree<T>::key() {
	return (*root).data;
}

template <class T>
BinaryTree<T> BinaryTree<T>::leftTree() {
	BinaryTree temp = empty();
	temp.root = (*root).left;
	return temp;
}

template <class T>
BinaryTree<T> BinaryTree<T>::rightTree() {
	BinaryTree temp = empty();
	temp.root = (*root).right;
	return temp;
}

template <class T>
void BinaryTree<T>::printBinaryTree() {
	if (root == NULL) {
		return;
	}
	cout << (*(this->root)).data << endl;
	leftTree().printBinaryTree();
	rightTree().printBinaryTree();
}

template class BinaryTree<int>;

