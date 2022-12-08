#include "AVL.h"

#include<iostream>

using namespace std;

template<class T>
AVLTree<T>::AVLTree()
{
	root = nullptr;
}

template<class T>
AVLTree<T>::~AVLTree()
{

}

template<class T>
void AVLTree<T>::empty()
{
	root = nullptr;
}

template<class T>
bool AVLTree<T>::isempty()
{
	return root == nullptr;
}

template<class T>
bool AVLTree<T>::member(T x)
{
	//first checking if root == nullptr, else it would try to get "nullptr.data"
	if (root == nullptr) {
		return false;
	}
	else if ((*root).data == x) {
		return true;
	}
	else if (x < (*root).data) {
		(*leftTree()).member(x);
	}
	else {
		(*rightTree()).member(x);
	}
}

template<class T>
void AVLTree<T>::insert(T x)
{
	if (root == nullptr) {
		Node* r = new Node;
		(*r).data = x;
		(*r).left = nullptr;
		(*r).right = nullptr;
		this->root = r;
	}
	if ((*root).data == x) { //note: this case was missing in binsearchtree, now it is implemented
		throw "Error: Element already in tree";
	}
	else if(x < (*root).data) {
		(*leftTree()).insert(x);
		testRightRotation(root);
	}
	else {
		(*rightTree()).insert(x);
		testLeftRotation(root);
	}
}

template<class T>
void AVLTree<T>::del(T x)
{
	//first checking if root == nullptr, else it would try to get "nullptr.data"
	if (root == nullptr) {
		throw "Error: x not in Tree";
	}
	else  if ((*root).data == x) {
		if ((*root).left == nullptr && (*root).right != nullptr)
		{
			(*root).data = (*(*root).right).data;
			(*root).left = (*(*root).right).left;
			(*root).right = (*(*root).right).right;
		}
		else if ((*root).left != nullptr && (*root).right == nullptr)
		{
			(*root).data = (*(*root).left).data;
			(*root).left = (*(*root).left).left;
			(*root).right = (*(*root).left).right;
		}
		else
		{
			Node* a = (*rightTree()).min();
			AVLTree* T1 = leftTree();
			AVLTree* T2 = rightTree();
			(*T2).del((*a).data);
			AVLTree* temp;
			temp = makeTree(*T1, (*a).data, *T2);
			root = (*temp).root;

			testRightRotation(root);
		}
	}
	else if (x < (*root).data) {
		(*leftTree()).del(x);
		testLefttRotation(root);
	}
	else {
		(*rightTree()).del(x);
		testRightRotation(root);
	}
}



template <class T>
AVLTree<T>* AVLTree<T>::leftTree() {
	AVLTree* temp = new AVLTree;
	(*temp).empty();
	(*temp).root = (*root).left;
	return temp;
}

template <class T>
AVLTree<T>* AVLTree<T>::rightTree() {
	AVLTree* temp = new AVLTree;
	(*temp).empty();
	(*temp).root = (*root).right;
	return temp;
}

template <class T>
typename AVLTree<T>::Node* AVLTree<T>::min() {
	AVLTree<T>::Node* mi = root;
	if ((*root).left == nullptr)
	{
		return mi;
	}
	mi = (*leftTree()).min();
}

template <class T>
AVLTree<T>* AVLTree<T>::makeTree(AVLTree& left, T x, AVLTree& right) {
	AVLTree* temp = new AVLTree;
	(*temp).empty();
	(*((*temp).root)).data = x;
	(*((*temp).root)).left = ((left).root);
	(*((*temp).root)).right = ((right).root);
	return temp;
}

//the algorithms are implemented according to the lecture, if given, using those from the lecture
//also the book "Algorythmen und Datenstrukturen" by Karsten Weicker and Nicole Weicker was used for reference

template <class T>
void AVLTree<T>::leftRotation(Node& n) {
	Node* high = new Node;
	(*high) = (*root).right;
	(*root).right = (*high).left;
	(*high).left = n;
	root = high;
}

template <class T>
void AVLTree<T>::rightRotation(Node& n) {
	Node* high = new Node;
	(*high) = (*root).left;
	(*root).left = (*high).right;
	(*high).right = n;
	root = high;
}

template <class T>
void AVLTree<T>::testRightRotation(Node& n) {
	if (n.balance == 0) {
		n.balance = -1;
	}
	if (n.balance == 1) {
		n.balance = 0;
	}
	if (n.balance == -1) {
		return reorganizeRight(n);
	}
}

template <class T>
void AVLTree<T>::testLeftRotation(Node& n) {
	if (n.balance == 0) {
		n.balance = 1;
	}
	if (n.balance == -1) {
		n.balance = 0;
	}
	if (n.balance == 1) {
		return reorganizeLeft(n);
	}
}

template <class T>
void AVLTree<T>::reorganizeRight(Node& n) {
	if (n.balance == -1) {
		rightRotation(n);
		(*((*n).right)).balance = 0;
		n.balance = 0;
	}
	if (n.balance == 0) {
		rightRotation(n);
		(*((*n).right)).balance = -1;
		n.balance = 1;
	}
	if (n.balance == 1) {
		leftRotation((*n).left);
		rightRotation(n);
		correctBalance(n);
		(*((*n).right)).balance = 0;
		n.balance = 0;
	}
}

template <class T>
void AVLTree<T>::reorganizeLeft(Node& n) {
	if (n.balance == 1) {
		leftRotation(n);
		(*((*n).right)).balance = 0;
		n.balance = 0;
	}
	if (n.balance == 0) {
		leftRotation(n);
		(*((*n).right)).balance = 1;
		n.balance = -1;
	}
	if (n.balance == 1) {
		rightRotation((*n).right);
		leftRotation(n);
		correctBalance(n);
		(*((*n).right)).balance = 0;
		n.balance = 0;
	}
}

template <class T>
void AVLTree<T>::correctBalance(Node& n) {
	if ((*n).balance == -1) {
		(*((*n).right)).balance = 1;
		(*((*n).left)).balance = 0;
	}
	if ((*n).balance == 1) {
		(*((*n).right)).balance = 0;
		(*((*n).left)).balance = -1;
	}
	if ((*n).balance == 0) {
		(*((*n).right)).balance = 0;
		(*((*n).left)).balance = 0;
	}
}

template <class T>
int AVLTree<T>::heigth() {
	if (this->root == nullptr) {
		return 0
	}
	else {
		return max(this->leftTree()->height(), this->rightTree()->height()) + 1;
	}
}

template class AVLTree<int>;