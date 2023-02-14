#pragma once

#include<iostream>

using namespace std;

//for this implementation we are using vertices numbered from 0 to number of vertices-1 with a fixed number of vertices

class AdjMatrix {
private:
	int** matrix;
	int dim;
public:
	AdjMatrix(int vertice_num) {
		int** temp = new int*[vertice_num];
		for (int i = 0; i < vertice_num; i++) {
			temp[i] = new int[vertice_num]();
		}
		matrix = temp;
		dim = vertice_num;
	}
	
	~AdjMatrix() {
		for (int i = 0; i < dim; i++) {
			delete matrix[i];
		}
		delete matrix;
	}

	void addEdge(int vertex1, int vertex2, int weight) {
		if (vertex1 < dim && vertex2 < dim) {
			matrix[vertex1][vertex2] = weight; // bidirectional graph
			matrix[vertex2][vertex1] = weight;
		}
		else {
			cout << "vertices out of range" << endl;
		}
	}

	int** Floyd() {
		int** C = new int* [dim];
		for (int i = 0; i < dim; i++) {
			C[i] = new int[dim]();
		}

		C = matrix;

		for (int i = 0; i < dim; i++) 
		{
			for (int j = 0; j < dim; j++)
			{
				for (int k = 0; k < dim; k++)
				{
					if ((C[j][k] == 0 || C[j][i] + C[i][k] < C[j][k]) && C[i][k] != 0 && C[j][i] != 0 && k !=j)
					{
						C[j][k] = C[j][i] + C[i][k];
					}
				}
			}
		}
		return C;
	}

	void printMatrix() {
		for (int i = 0; i < dim; i++) {
			for (int j = 0; j < dim; j++) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};