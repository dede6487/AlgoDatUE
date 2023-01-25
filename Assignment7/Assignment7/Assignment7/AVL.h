#pragma once

//dichchankinh.com

template<class T>
class AVLTree
{
public:
	struct Node {
		T data;
		Node* left;
		Node* right;
		int balance = 0;
	};
private:
	Node* root;

	AVLTree* makeTree(AVLTree& left, T x, AVLTree& right);

	//both rotations change the root of the tree accordingly
	void leftRotation(Node& n);
	void rightRotation(Node& n);

	void testRightRotation(Node& n);
	void testLeftRotation(Node& n);

	void reorganizeRight(Node& n);
	void reorganizeLeft(Node& n);

	void correctBalance(Node& n);
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