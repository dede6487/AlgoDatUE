#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED

template <class T = int>
class BST {
public:
	struct Node {
		T data;
		Node *left;
		Node *right;
	};
private:
	Node *root;

	void emptyR(Node* node);
	Node* insertR(Node* node, T& value);
	Node* removeR(Node* node, T& value);
	T minValue(Node* node);
	bool isMemberR(Node* node, T& value);
	void printBSTR(Node* node);
	
public:
	BST();
	~BST();
	void empty();
	void insert(T value);
	void remove(T value);
	bool isMember(T value);
	bool isEmpty();
	void printBST();
};

#endif //BST_H_INCLUDED
