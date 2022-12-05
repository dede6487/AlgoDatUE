#pragma once

template<class T>
class AVLTree
{
public:
	struct Node {
		T data;
		Node* left;
		Node* right;
	};
private:
	Node* root;

	AVLTree* makeTree(AVLTree& left, T x, AVLTree& right);

	void rebalance();

	bool AVL();
public:

	AVLTree();
	~AVLTree();

	void empty();
	bool isempty();
	bool member(T x);
	void insert(T x);
	void del(T x);

	//Helpfunctions
	AVLTree* leftTree();
	AVLTree* rightTree();

	Node* min();

	int heigth();
};