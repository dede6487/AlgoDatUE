#pragma once

#include<vector>
#include<iostream>

using namespace std;

//implements a matrix of size n+1 x m+1, this means the first element is at position (0,0)

class Matrix {
private:
	vector<int> matrixvec;

	int n;	//rows
	int m;	//columns

public:

	//costructor constructs the 0 Matrix of size n*m
	Matrix(int n, int m) {
		this->m = m;
		this->n = n;
		vector<int> temp((n) * (m), 0);
		matrixvec = temp;
	}

	//destructor empty
	~Matrix(){}

	//takes row i and column j and returns the respective element
	int operator() (int i, int j){
		if (i <= n && j <= m) {
			return matrixvec[i * j];
		}
		else {
			cout << "Error: element out of range" << endl;
		}
	}

	//takes row i and column j and writes the element e in the respective position
	void writeElem(int i, int j, int e) {
		matrixvec[i * j] = e;
	}

};