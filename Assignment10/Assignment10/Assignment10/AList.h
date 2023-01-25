#pragma once

#include<map>
#include<list>

using namespace std;

//due to time problems I resorted to only implement parts of this assignment

template<class typeVertex, class typeEdge> class AList {
private:
	list<typeVertex> Vertices[];
	map<list<typeVertices>, int> vertexMap;

	int num = 0;
public:
	AList(){}

	~AList(){}



	addVertex(typeVertex v) {
		list<typeVertex>* temp = temp(num++);
		for (int i = 0; i < num; i++) {
			temp[i] = Vertices[i]
		}
		list<typeVertex> v_list;
		v_List.push_back(v);
		temp[num++] = v_list;
		Vertices = temp;
		vertexMap.insert({ v_list,++num });
		delete[] Vertices;
	}

	bool adjacent(typeVertex v1, typeVertex v2) {
		int key = vertexMap[v1];
		list<typeVertex>::iterator it;
		for (it = Vertices[key].begin(); it != Vertices[key].end(); it++) {
			if (it == v2) {
				return true;
			}
		}
		return false;
	}

	typeVertex[] neighbours(typeVertex v) {
	
	}

	void removeVertex(typeVertex v) {
		int key = vertexMap[v];
		vertexMap.erase(key);
		delete Vertices[key];
		//this can lead to the Vertices array growing indefinitely, to avoid this, we would have to create a new array and copy the data
	}

	void addEdge(typeVertex v1, typeVertex v2) {//didn't know how to do this with typeEdge, also assuming the edge is directed from v1 to v2
		int key = vertexMap[v1];
		Vertices[key].push_back(v2);//also need to check if the edge already exists!
	}

	void removeEdge(typeVertex v1, typeVertex v2) {

	}

	typeVertex[] depthFirstSearch(typeVertex startVertex) {

	}

	typeVertex[] breathFirstSearch(typeVertex startVertex) {

	}

	void dumbGraph() {

	}
};