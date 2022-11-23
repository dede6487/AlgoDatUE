#include "BinSearchTree.h"

#include<iostream>

using namespace std;

template<class T>
BinSearchTree<T>::BinSearchTree()
{
	root = nullptr;
}

template<class T>
BinSearchTree<T>::~BinSearchTree()
{

}

template<class T>
void BinSearchTree<T>::empty()
{
	root = nullptr;
}

template<class T>
bool BinSearchTree<T>::isempty()
{
	return root == nullptr;
}

template<class T>
bool BinSearchTree<T>::member(T x)
{
	if ((*root).data == x) {
		return true;
	}
	else if (root == nullptr) {
		return false;
	}
	else if (x < (*root).data) {
		leftTree().member(x);
	}
	else {
		rightTree().member(x);
	}
}

template<class T>
void BinSearchTree<T>::insert(T x)
{
	if (root == nullptr) {
		Node r = new Node;
		*r.data = x;
		*r.left = nullptr;
		*r.right = nullptr;
		this->root = r;
	}
	else if(x < (*root).data) {
		leftTree().insert(x);
	}
	else {
		rightTree().insert(x);
	}
}

template<class T>
void BinSearchTree<T>::del(T x)
{
	if ((*root).data == x) {
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
			Node a = rightTree().min();
			BinSearchTree T1 = leftTree();
			BinSearchTree T2 = rightTree();
			T2.del(a);
			BinSearchTree* temp;
			temp = makeTree(T1, (*(a.root)).data, T2);
			root = (*temp).root;
		}
	}
	else if (root == nullptr) {
		cout<<"x not in Tree"<<endl;
		abort();
	}
	else if (x < (*root).data) {
		leftTree().del(x);
	}
	else {
		rightTree().del(x);
	}
}



template <class T>
BinSearchTree<T> BinSearchTree<T>::leftTree() {
	BinSearchTree temp = new BinSearchTree;
	temp = empty();
	(*temp).root = (*root).left;
	return temp;
}

template <class T>
BinSearchTree<T> BinSearchTree<T>::rightTree() {
	BinSearchTree temp = new BinSearchTree;
	temp = empty();
	(*temp).root = (*root).right;
	return temp;
}

template <class T>
typename BinSearchTree<T>::Node* BinSearchTree<T>::min() {
	BinSearchTree<T>::Node* min = root;
	if ((*root).left == nullptr)
	{
		return prev;
	}
	min = leftTree().min();
}

template <class T>
BinSearchTree<T>* BinSearchTree<T>::makeTree(BinSearchTree& left, T x, BinSearchTree& right) {
	BinSearchTree* temp = new BinSearchTree;
	*temp = empty();
	(*((*temp).root)).data = x;
	(*((*temp).root)).left = ((left).root);
	(*((*temp).root)).right = ((right).root);
	return temp;
}