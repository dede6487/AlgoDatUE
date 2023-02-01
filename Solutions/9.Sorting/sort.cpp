#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iterator>
using namespace std;

//Sort in ascending order a given array

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void copyArray(int source[], int dest[], int n) {
	for (int i = 0; i < n; i++)
		dest[i] = source[i];
}

void selectionSort(int arr[], int n) {
	int m, aux;
	for (int i = 0; i < n - 1; i++) {
		m = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[m])
				m = j;
		aux = arr[m];
		arr[m] = arr[i];
		arr[i] = aux;
	}
}

void insertionSort(int arr[], int n) {
	int r, j;
	for (int i = 1; i < n; i++) {
		r = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > r)
			arr[j + 1] = arr[j--];
		arr[j + 1] = r;
	}
}

void merge(int arr[], int start, int middle, int end) {
	int aux1[middle - start + 1], aux2[end - start + 1];
	int n1 = middle - start, n2 = end - middle;
	copyArray(&arr[start], aux1, n1);
	copyArray(&arr[middle], aux2, n2);
	// instead of dealing separately with the remaining elements of
	// one of the merged arrays, we set the last element in each
	// array on the maximum possible value and in this way we are
	// guaranteed that we will finish both aux's in the main while
	aux1[n1] = aux2[n2] = INT_MAX;
	
	int i = start, i1 = 0, i2 = 0;
	while (i1 < n1 || i2 < n2) {
		if (aux1[i1] < aux2[i2])
			arr[i++] = aux1[i1++];
		else
			arr[i++] = aux2[i2++];
	}
}

void mergeSort(int arr[], int start, int end) {
	if (start >= end - 1) return;
	int middle = (start + end + 1) / 2;
	mergeSort(arr, start, middle);
	mergeSort(arr, middle, end);
	merge(arr, start, middle, end);
}

// we choose the last element as the pivot;
// there are better strategies than this,
// but the principle of placing the smaller elements to the left
// and the bigger to the right of the pivot stays the same
int partitionIt (int arr[], int left, int right) {
	int aux;
	int pivot = arr[right];
	// counter for the smaller elements
	int count = 0;
  
	for (int i = left; i < right; i++) 
	{ 
		if (arr[i] < pivot) 
		{ 
			count++;
			aux = arr[left + count - 1];
			arr[left + count - 1] = arr[i];
			arr[i] = aux; 
		} 
	} 
	
	aux = arr[left + count];
	arr[left + count] = arr[right];
	arr[right] = aux;
	return left + count;
}

void quickSort(int arr[], int left, int right) {
	if (right > left) {
		int partition = partitionIt(arr, left, right);
		quickSort(arr, left, partition -1);
		quickSort(arr, partition + 1 , right);
	}
}

int main() {
	int i, n, number;

	ifstream inputFile;
	inputFile.open("../../sortdaten.txt");
//	inputFile.open("../../sortSmall.txt");

	n = 0;
	while (inputFile >> number)
		++n;
	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	i = 0;
	int s[n], scopy[n];
	while (inputFile >> s[i++]);
	inputFile.close();
	copyArray(s, scopy, n);

	srand(time(0));

	clock_t start;
	double duration;
	
	//selection
	start = clock();
	selectionSort(s, n);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "selection sort duration: " << duration << endl;
	//printArray(s, n);

	copyArray(scopy, s, n);
	
	//insertion
	start = clock();
	insertionSort(s, n);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "insertion sort duration: " << duration << endl;
	//printArray(s, n);

	copyArray(scopy, s, n);

	//merge
	start = clock();
	mergeSort(s, 0, n);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "merge sort duration: " << duration << endl;
	//printArray(s, n);

	copyArray(scopy, s, n);

	//quick
	start = clock();
	quickSort(s, 0, n - 1);
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "quick sort duration: " << duration << endl;
	//printArray(s, n);
}


