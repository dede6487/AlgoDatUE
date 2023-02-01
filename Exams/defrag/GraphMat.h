#ifndef GRAPHMAT_H_INCLUDED
#define GRAPGMAT_H_INCLUDED
#define MAX_SIZE 20
#include<map>

template <class V = int, class E = int>
class GraphMat {
public:
	struct Edge {
		E data;
		V v1;
		V v2;
	};

private:
	bool directed;
	int counter;
	E edgeNullValue;
	V vertexNullValue;
	std::map<V, int> vertices;
	V currVertices[MAX_SIZE];
	E edges[MAX_SIZE][MAX_SIZE];

	void defrag();
	void initVertices();
	void initMatrix();
	void DFS(V start, bool known[], V vList[], int& c);

public:
	GraphMat(V vertexZero, E edgeZero, bool dir = false);
	~GraphMat();
	void addVertex(V v);
	void removeVertex(V v);
	void addEdge(Edge e);
	void removeEdge(Edge e);
	bool adjacent(V v1, V v2);
	void depthFirstSearch(V start, V list[]);
	void breadthFirstSearch(V start, V list[]);
	void dumpGraph();
};

#endif //GRAPGMAT_H_INCLUDED
