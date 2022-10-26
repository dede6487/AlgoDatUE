#pragma once

#include<vector>
#include<iostream>
#include <tuple>

using namespace std;

//implements a matrix of size nxm

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
	~Matrix() {}

	//takes row i and column j and returns the respective element
	int operator() (int i, int j) {
		if (i <= n && j <= m) {
			return matrixvec[(i - 1) * m + j - 1];
		}
		else {
			cout << "Error: element out of range" << endl;
			abort;
		}
	}

	//just takes one position marker and reads from first to last element in a column, 
	//then gets to the next row
	int operator() (int l) {
		return matrixvec[l];
	}

	//converts a single position marker into the form (i,j)
	tuple<int,int> position(int l) {
		int i = (l / m)+1; //int div
		int j = (l % m)+1; 
		return make_tuple(i, j);
	}

	//takes row i and column j and writes the element e in the respective position
	void writeElem(int i, int j, int e) {
		matrixvec[(i - 1) * m + j - 1] = e;
	}

	//just takes one position marker and reads from first to last element in a column, 
	//then gets to the next row
	void writeElem(int l, int e) {
		matrixvec[l] = e;
	}

	//prints the matrix
	void print() {
		cout << "\n";
		for (int i = 1; i <= n; i++) {
			for(int j = 1; j <= m; j++){
				cout << matrixvec[(i - 1) * m + j - 1 ] << " ";
			}
			cout << "\n";
		}
	}

	//returns tuple with n and m
	tuple<int, int> size() 
	{
		tuple<int, int> temp;
		temp = make_tuple(n, m);
		return temp;
	}

};