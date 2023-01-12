#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

//place algos in seperate file!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1111!!!

//slow sorting algo, output sorted in ascending order
//insertionSort according to the alogrithm presented in the lecture

void insertionSort(int array[], int len) {
	for (int i = 1; i < len; i++)
	{
		int r = array[i];
		int j = i - 1;
		while (j > 0 && array[j] > r) {	//> for ascending
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = r;
	}
}


//merge sort with output in decending order as shown in the lecture

void merge(int array1[], int startIndex, int midIndex, int endIndex) {
	int arrayLeft = midIndex - startIndex + 1;
	int arrayRight = endIndex - midIndex;

	int* arrayLeft = new int[midIndex - startIndex + 1];
	int* arrayRight = new int[endIndex - midIndex];

	for (int i = 0; i < midIndex - startIndex + 1; i++) {
		arrayLeft[i] = array1[startIndex + i];
	}
	for (int i = 0; i < midIndex - startIndex + 1; i++) {
		arrayRight[i] = array1[midIndex + i + 1];
	}

	int indexOfSubArrayOne = 0;
	int indexOfSubArrayTwo = 0;
	int indexOfMergedArray = 0;

	while (indexOfSubArrayOne < arrayLeft
		&& indexOfSubArrayTwo < arrayRight) {
		if (arrayLeft[indexOfSubArrayOne]
			<= arrayRight[indexOfSubArrayTwo]) {
			array1[indexOfMergedArray]
				= arrayLeft[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array1[indexOfMergedArray]
				= arrayRight[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// left[], if there are any
	while (indexOfSubArrayOne < arrayLeft) {
		array1[indexOfMergedArray]
			= arrayLeft[indexOfSubArrayOne];
		indexOfSubArrayOne++;
		indexOfMergedArray++;
	}
	// Copy the remaining elements of
	// right[], if there are any
	while (indexOfSubArrayTwo < arrayRight) {
		array1[indexOfMergedArray]
			= arrayRight[indexOfSubArrayTwo];
		indexOfSubArrayTwo++;
		indexOfMergedArray++;
	}
	delete[] arrayLeft;
	delete[] arrayRight;
}

void mergeSort(int array1[], int startIndex, int endIndex) {
	if (endIndex - startIndex == 1) //base-case
	{
		return;
	}
	else {
		int m = endIndex + startIndex / 2;
		mergeSort(array1, startIndex, m);
		mergeSort(array1, m+1, endIndex);
		merge(array1, startIndex, m, endIndex);
	}
}


//testing and timing the methods
int main()
{
	// Read the data from the file

	int number;
	vector<int> tempv;

	ifstream inputfile;

	inputfile.open("IntegerWerte.txt");

	while (inputfile >> number)
	{
		tempv.push_back(number);
	}

	inputfile.close();

	//tempv stays in memory, should be deleted

	unsigned int size = tempv.size();
	//cout << size << endl;

	int* arr = new int[size];

	for (int j = 0; j < size; j++) {
		arr[j] = tempv[j];
	}

	// Clock each method by running it 300000 times
		// for a random c

	double time1 = 0;
	double time2 = 0;
	double time3 = 0;

	clock_t start;

	//Contains1
	start = clock();

	for (int k = 0; k < 30000; k++) {
		int val = rand() % 300000;
		contains(arr, size, val);
	}

	time1 = (clock() - start) / (double)
		CLOCKS_PER_SEC;


	//Contains2
	start = clock();

	for (int k = 0; k < 30000; k++) {
		int val = rand() % 300000;
		contains2(arr, size, val);
	}

	time2 = (clock() - start) / (double)
		CLOCKS_PER_SEC;

	cout << "Time it took the Algorithms for finishing the testcase:" << endl;
	cout << "Contains1 took (seconds):" << time1 << endl;
	cout << "Contains2 took (seconds):" << time2 << endl;
}

