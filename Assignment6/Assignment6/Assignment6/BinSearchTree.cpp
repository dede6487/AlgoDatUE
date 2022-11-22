#include "BinSearchTree.h"

template<class T>
BinSearchTree<T>::BinSearchTree()
{
	root = NULL;
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
	return root == NULL;
}

template<class T>
bool BinSearchTree<T>::member(T x)
{

}

template<class T>
BinSearchTree<T> BinSearchTree<T>::insert(T x)
{
	if (root == NULL) {
		
	}
	else {

	}
}

template<class T>
BinSearchTree<T> BinSearchTree<T>::del(T x)
{

}