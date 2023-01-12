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


//merge sort with output in decending order according to the example done in the lecture

void merge(int array1[], int startIndex, int midIndex, int endIndex) {
	int* array2 = new int[endIndex - startIndex];

	int leftLen = midIndex - startIndex + 1;
	int rightLen = endIndex - midIndex;

	for (int i = 0; i < endIndex - startIndex + 1; i++) {
		if (i < midIndex - startIndex + 1) {
			array2[i] = array1[startIndex + i];
		}
		else {
			array2[i] = array1[midIndex + i + 1];
		}
	}

	int indexLeft = 0;
	int indexRight = midIndex + 1;
	int indexMerge = 0;

	while (indexLeft < leftLen && indexRight < rightLen) {
		if (array2[indexLeft] <= array2[indexRight]) {
			array1[indexMerge] = array2[indexLeft];
			indexLeft++;
		}
		else {
			array1[indexMerge] = array2[indexRight];
			indexRight++;
		}
		indexMerge++;
	}

	//copying the rest of the array

	while (indexLeft < leftLen) {
		array1[indexMerge] = array2[indexLeft];
		indexLeft++;
		indexMerge++;
	}

	while (indexRight < rightLen) {
		array1[indexMerge] = array2[indexRight];
		indexRight++;
		indexMerge++;
	}
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

	inputfile.open("sortdaten.txt");

	while (inputfile >> number)
	{
		tempv.push_back(number);
	}

	inputfile.close();

	unsigned int size = tempv.size();

	int* arr = new int[size];

	for (int j = 0; j < size; j++) {
		arr[j] = tempv[j];
	}

	//testing the methods for correctness
	
	cout << "Testing if the algorithms are correct:" << endl;

	bool test1 = true;
	bool test2 = true;

	//slow sort
	int* testarr = new int[size];
	testarr = arr;

	insertionSort(testarr, size);

	for (int i = 1; i < size; i++) {
		if (! (testarr[i - 1] < testarr[i])) {
			test1 = false;
		}
	}

	cout << "insertion Sort is correct:" << test1 << endl;

	//merge sort
	//testarr = arr;

	//mergeSort(testarr, 0, size);

	//for (int i = 1; i < size; i++) {
	//	if (!(testarr[i - 1] < testarr[i])) {
	//		test2 = false;
	//	}
	//}

	cout << "merge Sort is correct:" << test2 << endl;

	cout << "Time it took the Algorithms for finishing the testcase:" << endl;

	// Clock each method by running it 30000 times
	//caution, these timings also include the copying of the array

	double time1 = 0;
	double time2 = 0;

	clock_t start;

	//slow sort
	start = clock();

	for (int k = 0; k < 30000; k++) {
		testarr = arr;
		insertionSort(testarr, size);
	}

	time1 = (clock() - start) / (double)
		CLOCKS_PER_SEC;

	cout << "insertion Sort took (seconds):" << time1 << endl;

	//merge sort
	//start = clock();

	//for (int k = 0; k < 30000; k++) {
	//	testarr = arr;
	//	mergeSort(testarr, 0, size);
	//}

	//time2 = (clock() - start) / (double)
	//	CLOCKS_PER_SEC;

	delete[] testarr;

	cout << "merge Sort took (seconds):" << time2 << endl;
}

