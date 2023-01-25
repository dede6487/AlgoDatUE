#pragma once

#include<vector>
#include<iostream>
#include <tuple>
#include <map>

using namespace std;

//due to time problems I resorted to only implement parts of this assignment

//implements a matrix of size nxn

template<class typeVertex, class typeEdge> class AMatrix {
private:
	vector<bool> matrixvec;
	
	map<typeVertex, int> vertexMap;

	int n = 0;	//rows == cols cause quadratic


	//private functions
private:
	//just takes one position marker and reads from first to last element in a column, 
	//then gets to the next row
	int operator() (int l) {
		return matrixvec[l];
	}

	//converts a single position marker into the form (i,j)
	tuple<int, int> position(int l) {
		int i = (l / n) + 1; //int div
		int j = (l % n) + 1;
		return make_tuple(i, j);
	}

	//takes row i and column j and writes the element e in the respective position
	void writeElem(int i, int j, bool e) {
		matrixvec[(i - 1) * n + j - 1] = e;
	}

	//just takes one position marker and reads from first to last element in a column, 
	//then gets to the next row
	void writeElem(int l, bool e) {
		matrixvec[l] = e;
	}



public:

	//costructor empty
	AMatrix() {}

	//destructor empty
	~AMatrix() {}

	//takes row i and column j and returns the respective element
	int operator() (int i, int j) {
		if (i <= n && j <= n) {
			return matrixvec[(i - 1) * n + j - 1];
		}
		else {
			throw "Error: element out of range";
		}
	}

	//prints the matrix
	void print() {
		cout << "\n";
		for (int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++){
				cout << matrixvec[(i - 1) * m + j - 1 ] << " ";
			}
			cout << "\n";
		}
	}

	//returns tuple with n and m
	tuple<int, int> size() 
	{
		tuple<int, int> temp;
		temp = make_tuple(n, n);
		return temp;
	}


	//adjacency functionality

	addVertex(typeVertex v) {
		vertexMap.insert({v, ++n}); //increases n, then uses the increased value
		vector<bool> temp;
		//very costly increase of the size of the matrix
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				temp.push_back(this->operator()(i, j));
			}
			temp.push_back(false);
		}
		for (int i = 0; i <= n; i++) {
			temp.push_back(false);
		}
	}

	bool adjacent(typeVertex v1, typeVertex v2) {
		int i = vertexMap[v1];
		int j = vertexMap[v2];
		return this->operator(i, j);
	}

	typeVertex[] neighbours(typeVertex v) {
		vector<typeVertex> neighbours;
		int pos = vertexMap[v];
		for (int i = pos; i < n; i += n) //horizontal traversal 
		{
			if (this - operator(pos, i)) {
				tuple t = position(pos * i)
				neighbours.push_back(vertexMap.find(get<1>t));
			}
			if (this - operator(i, pos)) {
				tuple t = position(pos * i)
				neighbours.push_back(vertexMap.find(get<0>t));
			}
		}
		int* temp = int(neighbours.size());
		for (int i = 0; i < neighbours.size(); i++) {
			temp[i] = neighbours[i];
		}
		return temp;
	}

	void removeVertex(typeVertex v) {

	}

	void addEdge(typeVertex v1, typeVertex v2) {//didn't know how to do this with typeEdge
		int i = vertexMap[v1];
		int j = vertexMap[v2];
		writeElem(i, j, true);
	}

	void removeEdge(typeVertex v1, typeVertex v2) {
		int i = vertexMap[v1];
		int j = vertexMap[v2];
		writeElem(i, j, false);
	}

	typeVertex[] depthFirstSearch(typeVertex startVertex) {

	}

	typeVertex[] breathFirstSearch(typeVertex startVertex) {

	}

	void dumbGraph() {

	}
};