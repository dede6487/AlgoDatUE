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
	else if(x < (*root).data) {
		(*leftTree()).insert(x);
	}
	else {
		(*rightTree()).insert(x);
	}

	rebalance();
}

template<class T>
void AVLTree<T>::del(T x)
{
	//first checking if root == nullptr, else it would try to get "nullptr.data"
	if (root == nullptr) {
		cout << "x not in Tree" << endl;
		abort();
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
		}
	}
	else if (x < (*root).data) {
		(*leftTree()).del(x);
	}
	else {
		(*rightTree()).del(x);
	}

	rebalance();
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

template <class T>
void AVLTree<T>::rebalance() {
	if (!AVL()) {

	}
}

template <class T>
bool AVLTree<T>::AVL() {
	if (abs(this->leftTree()->height() - this->rightTree()->heigth()) <= 1)
	{
		if this->leftTree()->height() == 0 || this->rightTree()->heigth() == 0) {
		return true
		}
		return this->rightTree()->AVL() && this->leftTree()->AVL();
	}
	else {
		return false
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