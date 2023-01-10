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
	BinaryTree empty();//changed datatype, before it woulve been void - so the wrong datatype
	BinaryTree makeTree(BinaryTree& leftT, T element, BinaryTree& rightT);//changed datatype, before it woulve been void - should also be binaryTree?
	//without garbage collection, if lefttree or righttree is deleted from outside, it's gone!!! copying would be better but also more costly
	//better have it private? so just inside the class it is usable, no problems then

	T key();
	BinaryTree leftTree();
	BinaryTree rightTree();
	void printBinaryTree();
};

#endif //BINARYTREE_H_INCLUDED
