// For a binary search tree, implement a method that returns the number of occurrences of a given key, computed in an optimal way. 
// Provided the tests and all methods needed for the tests to run.

template <class T> class BinTree {
private:
	struct Node {
		T key;
		Node* left;
		Node* right;
	};

	Node* root;
	Node* leafEnd; //vlue that should be at the end of a Branch, ie where left and right point to

	void insertHelper(Node* elem, Node* startNode) {
		if ((*elem).key <= (*startNode).key) {
			if ((*startNode).left != leafEnd) {
				insertHelper(elem, (*startNode).left);
			}
			else {
				(*startNode).left = elem;
			}
		}
		else {
			if ((*startNode).right != leafEnd) {
				insertHelper(elem, (*startNode).right);
			}
			else {
				(*startNode).right = elem;
			}
		}
	}
public:
	BinTree(Node* root_, Node* leafEnd_) {
		this->root = root_;
		this->leafEnd = leafEnd_;
	}
	~BinTree() {

	}

	void insert(Node* elem) {
		insertHelper(elem, root);
	}

	int keyOcc(int key, Node* startNode) {
		int count = 0;
		if (key < (*startNode).key) {
			return count + keyOcc(key, (*startNode).left);
		}
		else if (key > (*startNode).key) {
			return count + keyOcc(key, (*startNode).right);
		}
		else if(key == (*startNode).key) {
			return 1 + keyOcc(key, (*startNode).left); // only left because of the implementation of insert
		}
		else { // so if there is no element at the end or it an element has been found and after it is another or no element
			return 0;
		}
		return count;
	}
};

int main() {

}
