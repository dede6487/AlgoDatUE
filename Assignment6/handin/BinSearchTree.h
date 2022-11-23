#pragma once

template<class T>
class BinSearchTree
{
public:
	struct Node {
		T data;
		Node* left;
		Node* right;
	};
private:
	Node* root;

	BinSearchTree* makeTree(BinSearchTree& left, T x, BinSearchTree& right);

public:

	BinSearchTree();
	~BinSearchTree();

	void empty();
	bool isempty();
	bool member(T x);
	void insert(T x);
	void del(T x);

	//Helpfunctions
	BinSearchTree* leftTree();
	BinSearchTree* rightTree();

	Node* min();
};