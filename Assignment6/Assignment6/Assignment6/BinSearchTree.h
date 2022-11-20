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

public:

	BinSearchTree();
	~BinSearchTree();

	BinSearchTree empty();
	bool isempty(BinSearchTree t);
	bool member(T x);
	BinSearchTree insert(T x);
	BinSearchTree del(T x);
};