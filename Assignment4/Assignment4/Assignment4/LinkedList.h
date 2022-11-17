#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

template <class T = int>
class LinkedList {
public:
	struct Node {
		T data;
		Node *next;
		Node *prev;
	};
private:
	Node *firstN;
	Node *lastN;

	Node* next(Node* node);
	Node* prev(Node* node);
	bool bol(Node* node);
	bool eol(Node* node);
	bool nodeInList(Node* node);
	
public:
	LinkedList();
	~LinkedList();
	LinkedList empty();
	Node* front();
	Node* last();
	void insert(Node* node, T value); //insert after node
	void remove(Node* node);
	void concat(LinkedList& tail);
	bool isEmpty();
	Node* find(T value);
	T retrieve(Node* node);
	void printList();
	void printCompleteList(); // only for debug purposes
};

#endif //LINKEDLIST_H_INCLUDED
