#include <iostream>
#include <queue>
#include "GraphMat.h"
using namespace std;

// Matrix adjacency implementation for graphs
// with variable vertex and edge type.
// In this implementation types without a "<"
// operator will fail.
//
// For specific purposes, it might be better not 
// to use templates. The implementation will become 
// thus much simpler.
//
// Fail-safe checks are scarcely implemented.
//
// Adding and removing vertices will leave holes
// in the vertices structure, which could be removed
// when the MAX_SIZE limit is reached.
// Since it is a good idea for an exam subject, the 
// implementation of the defragmentation is missing.

template <class V, class E>
GraphMat<V, E>::GraphMat(V vertexZero, E edgeZero, bool dir) {
	counter = 0;
	vertexNullValue = vertexZero;
	edgeNullValue = edgeZero;
	directed = dir;
	initVertices();
	initMatrix();	
}

template <class V, class E>
GraphMat<V, E>::~GraphMat() {
}

template <class V, class E>
void GraphMat<V, E>::initVertices() {
	for(int i = 0; i < MAX_SIZE; i++)
		currVertices[i] = vertexNullValue;
}

template <class V, class E>
void GraphMat<V, E>::initMatrix() {
	for(int i = 0; i < MAX_SIZE; i++)
		for(int j = 0; j < MAX_SIZE; j++)
			edges[i][j] = edgeNullValue;
}

template <class V, class E>
void GraphMat<V, E>::defrag() {
	cout << "Graph full, implement defragmentation to make some space!" << endl;
}

template <class V, class E>
void GraphMat<V, E>::DFS(V start, bool known[], V vList[], int &c) {
	typename map<V, int>::iterator it;
	int vIndex = vertices[start];
	known[vIndex] = true;
	for(it = vertices.begin(); it != vertices.end(); it++) {
		int i = it->second;
		if (edges[vIndex][i] != edgeNullValue)
			if (!known[i]) {
				V nextVertex = currVertices[i];
				vList[c++] = nextVertex;
				DFS(nextVertex, known, vList, c);
			}
	}
}

template <class V, class E>
void GraphMat<V, E>::addVertex(V v) {
	if (counter >= MAX_SIZE) {
		defrag();
		// to be changed when defrag is implemented
		return;
	}
	if (vertices.find(v) != vertices.end()) return;
	vertices[v] = counter;
	currVertices[counter++] = v;
}

template <class V, class E>
void GraphMat<V, E>::removeVertex(V v){
	int vIndex = vertices[v];
	vertices.erase(v);
	currVertices[vIndex] = vertexNullValue;
	for(int i = 0; i < MAX_SIZE; i++)
		edges[vIndex][i] = edgeNullValue;
	if (!directed)
		for(int i = 0; i < MAX_SIZE; i++)
			edges[i][vIndex] = edgeNullValue;
}

template <class V, class E>
void GraphMat<V, E>::addEdge(Edge e){
	addVertex(e.v1);
	addVertex(e.v2);
	edges[vertices[e.v1]][vertices[e.v2]] = e.data;
	if (!directed) edges[vertices[e.v2]][vertices[e.v1]] = e.data;
}

template <class V, class E>
void GraphMat<V, E>::removeEdge(Edge e){
	if (e.data == edges[vertices[e.v1]][vertices[e.v2]])
		edges[vertices[e.v1]][vertices[e.v2]] = edgeNullValue;
}

template <class V, class E>
bool GraphMat<V, E>::adjacent(V v1, V v2){
	if (vertices.find(v1) == vertices.end() || vertices.find(v2) == vertices.end()) 
		return false;
	return edges[vertices[v1]][vertices[v2]] != edgeNullValue;
}

template <class V, class E>
void GraphMat<V, E>::depthFirstSearch(V start, V list[]){
	int c = 1;
	bool known[counter];
	for (int i = 0; i < counter; i++) {
		known[i] = false;
		list[i] = vertexNullValue;
	}
	list[0] = start;
	DFS(start, known, list, c);
}

template <class V, class E>
void GraphMat<V, E>::breadthFirstSearch(V start, V list[]){
	//initializations
	typename map<V, int>::iterator it;
	queue<int> q;
	int c = 0;
	bool known[counter];
	for (int i = 0; i < counter; i++) {
		known[i] = false;
		list[i] = vertexNullValue;
	}
	known[vertices[start]] = true;

	//traversal
	q.push(start);
	list[c++] = start;
	while (!q.empty()) {
		V nextVertex = q.front(); q.pop();
		int vIndex = vertices[nextVertex];
		for(it = vertices.begin(); it != vertices.end(); it++) {
			int i = it->second;
			if (edges[vIndex][i] != edgeNullValue)
				if (!known[i]) {
					V nextVertex = currVertices[i];
					list[c++] = nextVertex;
					q.push(nextVertex);
					known[i] = true;
				}
		}
	}
}

template <class V, class E>
void GraphMat<V, E>::dumpGraph(){
	bool connected[MAX_SIZE];
	bool found = false;
	cout << "Edges: ";
	for (int i = 0; i < counter; i++)
		connected[i] = false;
	for (int i = 0; i < counter; i++)
		if (currVertices[i] != vertexNullValue) 
			for (int j = i + 1; j < counter; j++) {
				if (edges[i][j] != edgeNullValue) {
					cout << "(" << currVertices[i] << ", " << currVertices[j] << ") -> " << edges[i][j] << "; ";
					connected[i] = true;
					connected[j] = true;
					found = true;
				}
				if (directed && edges[i][i] != edgeNullValue) {
					cout << "(" << currVertices[j] << ", " << currVertices[i] << ") -> " << edges[j][i] << "; ";
					connected[i] = true;
					connected[j] = true;
					found = true;
				}
			}
	if (!found) cout << "NOT FOUND";
	cout << endl << "Isolated vertices: ";
	found = false;
	for (int i = 0; i < counter; i++)
		if (currVertices[i] != vertexNullValue && !connected[i]) {
			cout << currVertices[i] << " ";
			found = true;
		}
	if (!found) cout << "NOT FOUND";
	cout << endl;
}

template class GraphMat<int, int>;

