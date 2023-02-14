#include<iostream>

#include"AdjMatrix.h"

using namespace std;

int main() {

	cout << "Test 1: /n" << endl;

	AdjMatrix A(5); // we have the vertices 0,1,2,3,4

	A.addEdge(0, 1, 1);
	A.addEdge(1, 2, 2);
	A.addEdge(2, 3, 1);
	A.addEdge(1, 4, 10);
	A.addEdge(0, 3, 10);

	cout << "Adjacency Matrix:" << endl;

	A.printMatrix();

	cout << endl;

	int** C = A.Floyd();

	cout << "Floyd Matrix:" << endl; 
	cout << "(this matrix encodes the function generated in Floyds algorithm, so the numbers represent the weighted pathlength and 0 means that there is no path)" << endl;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << C[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Test 2: /n" << endl;

	AdjMatrix B(8); // we have the vertices 0,1,2,3,4,5,6,7

	B.addEdge(0, 4, 2);
	B.addEdge(6, 2, 1);
	B.addEdge(5, 7, 1);
	B.addEdge(7, 6, 8);

	cout << "Adjacency Matrix:" << endl;

	B.printMatrix();

	cout << endl;

	int** E = B.Floyd();

	cout << "Floyd Matrix:" << endl;
	cout << "(this matrix encodes the function generated in Floyds algorithm, so the numbers represent the weighted pathlength and 0 means that there is no path)" << endl;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << E[i][j] << " ";
		}
		cout << endl;
	}
}