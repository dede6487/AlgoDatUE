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

	Node* copyTree(Node* node);
	void emptyRec(Node* node);
	void printBinaryTreeRec(Node* node);

public:
	BinaryTree();
	BinaryTree(Node* root);
	~BinaryTree();
	void empty();
	void makeTree(BinaryTree& leftT, T element, BinaryTree& rightT);
	T key();
	BinaryTree leftTree();
	BinaryTree rightTree();
	void printBinaryTree();
};

#endif //BINARYTREE_H_INCLUDED
