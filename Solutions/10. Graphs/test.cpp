#include "GraphMat.h"
#include <iostream>
#include <cstdio>
using namespace std;

void printVertices(int vList[]) {
	for (int i = 0; i < MAX_SIZE; i++) {
		if (vList[i] == 0) break;
		cout << vList[i] << " ";
	}
	cout << endl;
}

void createGraph(GraphMat<int, int> &graph, bool dump = false) {
	if (dump) cout << "Adding edge (1, 2) with value 7" << endl;
	graph.addEdge((typename GraphMat<int, int>::Edge){.data = 7, .v1 = 1, .v2 = 2});
	if (dump) cout << "Adding edge (1, 3) with value 9" << endl;
	graph.addEdge((typename GraphMat<int, int>::Edge){.data = 9, .v1 = 1, .v2 = 3});
	if (dump) cout << "Adding edge (1, 6) with value 14" << endl;
	graph.addEdge((typename GraphMat<int, int>::Edge){.data = 14, .v1 = 1, .v2 = 6});
	if (dump) cout << "Adding edge (2, 3) with value 10" << endl;
	graph.addEdge((typename GraphMat<int, int>::Edge){.data = 10, .v1 = 2, .v2 = 3});
	if (dump) cout << "Adding edge (2, 4) with value 15" << endl;
	graph.addEdge((typename GraphMat<int, int>::Edge){.data = 15, .v1 = 2, .v2 = 4});
	if (dump) cout << "Adding edge (3, 4) with value 11" << endl;
	graph.addEdge((typename GraphMat<int, int>::Edge){.data = 11, .v1 = 3, .v2 = 4});
	if (dump) cout << "Adding edge (3, 6) with value 2" << endl;
	graph.addEdge((typename GraphMat<int, int>::Edge){.data = 2, .v1 = 3, .v2 = 6});
	if (dump) cout << "Adding edge (4, 5) with value 6" << endl;
	graph.addEdge((typename GraphMat<int, int>::Edge){.data = 6, .v1 = 4, .v2 = 5});
	if (dump) cout << "Adding edge (5, 6) with value 9" << endl;
	graph.addEdge((typename GraphMat<int, int>::Edge){.data = 9, .v1 = 5, .v2 = 6});
}

int main()
{
	GraphMat<int, int> graph(0, 0);

	cout << endl << "Create graph:" << endl << "=============" << endl;
	for(int i = 1; i < 10; i += 2) {
		cout << "Adding vertex " << i << endl;
		graph.addVertex(i);
	}
	graph.dumpGraph();
	createGraph(graph, true);
	graph.dumpGraph();

	cout << endl << "Adjacency:" << endl << "==========" << endl;
	cout << "Are 7 and 9 adjacent? " << (graph.adjacent(7, 9) ? "yes" : "no") << endl;
	cout << "Are 4 and 2 adjacent? " << (graph.adjacent(4, 2) ? "yes" : "no") << endl;
	cout << "Are 4 and 6 adjacent? " << (graph.adjacent(4, 6) ? "yes" : "no") << endl;

	cout << endl << "Removing elements:" << endl << "==================" << endl;
	cout << "Remove edge (1, 3):" << endl;
	graph.removeEdge((typename GraphMat<int, int>::Edge){.data = 9, .v1 = 1, .v2 = 3});	
	graph.dumpGraph();
	cout << endl << "Remove edge (1, 6) with value 8:" << endl;
	graph.removeEdge((typename GraphMat<int, int>::Edge){.data = 8, .v1 = 1, .v2 = 6});	
	graph.dumpGraph();
	cout << endl << "Remove vertex 7" << endl;
	graph.removeVertex(7);
	graph.dumpGraph();
	cout << endl << "Remove vertex 4" << endl;
	graph.removeVertex(4);
	graph.dumpGraph();
	
	cout << endl << "Traversals:" << endl << "===========" << endl;
	GraphMat<int, int> graph1(0, 0);
	createGraph(graph1);
	cout << "Initial graph:" << endl;
	graph1.dumpGraph();

	int vList[MAX_SIZE];
	graph1.depthFirstSearch(1, vList);
	cout << "Vertices in DFS order: ";
	printVertices(vList);

	graph1.breadthFirstSearch(1, vList);
	cout << "Vertices in BFS order: ";
	printVertices(vList);

	/*
	tree[1].makeTree(tree[9], 2, tree[9]);
	tree[1].printBinaryTree();
	tree[2].makeTree(tree[9], 3, tree[9]);
	tree[2].printBinaryTree();
	tree[3].makeTree(tree[9], 4, tree[9]);
	tree[3].printBinaryTree();
	tree[4].makeTree(tree[9], 5, tree[9]);
	tree[4].printBinaryTree();
	tree[5].makeTree(tree[0], 6, tree[1]);
	tree[5].printBinaryTree();
	tree[6].makeTree(tree[2], 7, tree[3]);
	tree[6].printBinaryTree();
	tree[7].makeTree(tree[5], 8, tree[6]);
	tree[7].printBinaryTree();
	tree[8].makeTree(tree[7], 9, tree[4]);
	tree[8].printBinaryTree();

	cout << endl << "Fail when trying to make a tree when one exists already: ";
	tree[8].makeTree(tree[7], 9, tree[4]);
	tree[8].printBinaryTree();

	cout << endl << "Retrieve information from the big tree:" << endl;
	cout << "The root is " << tree[8].key() << endl;
	cout << "The left subtree is ";
	tree[8].leftTree().printBinaryTree();
	cout << "The root of the left subtree is " << tree[8].leftTree().key() << endl;
	cout << "The right subtree is ";
	tree[8].rightTree().printBinaryTree();
	cout << "The root of the right subtree is " << tree[8].rightTree().key() << endl;

	cout << endl << "Empty trees:" << endl;
	tree[8].empty();
	cout << "We emptied the tree: ";
	tree[8].printBinaryTree();
	cout << "Try to retrieve its key: " << endl;
	tree[8].key();*/
	


	// here the destructor for BinaryTree is called automatically
}


