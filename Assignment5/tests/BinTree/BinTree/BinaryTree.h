#ifndef BINARYTREE_H_INCLUDED
#define BINARYTREE_H_INCLUDED

template <class T = int>
class BinaryTree {
public:
	struct Node {
		T data;
		Node *left;
		Node *right;
	};
private:
	Node *root;

public:
	BinaryTree();
	~BinaryTree();
	BinaryTree empty();//changed datatype, before it woulve been void
	void makeTree(BinaryTree& leftT, T element, BinaryTree& rightT);
	T key();
	BinaryTree leftTree();
	BinaryTree rightTree();
	void printBinaryTree();
};

#endif //BINARYTREE_H_INCLUDED
