
template <class T> class BinTree {
private:
	struct Node :{
		T* key;
		Node* right;
		Node* left;
	}

	Node* root;

public:

	int height(Node* startNode) {
		if (startNode == nullptr) { //assuming that the defaultvalue of left and right in a leaf is nullptr
			return 0;
		}
		else {
			return max(height((*startNode).left), height((*startNode).right)) + 1;
		}
	}
};



int main() {

}