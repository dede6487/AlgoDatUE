#include "BinSearchTree.h"

template<class T>
BinSearchTree<T>::BinSearchTree()
{
	//root = nullptr;
}

template<class T>
BinSearchTree<T>::~BinSearchTree()
{

}

template<class T>
BinSearchTree<T> BinSearchTree<T>::empty()
{
	return BinSearchTree<T>::BinSearchTree();
}

template<class T>
bool BinSearchTree<T>::isempty(BinSearchTree t)
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
			//case 2
		}
	}
	else if (root == nullptr) {
		cout<<"x not in Tree"<<endl;
		abort(-1);
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