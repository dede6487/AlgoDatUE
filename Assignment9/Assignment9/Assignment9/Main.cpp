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


//merge sort with output in decending order

void merge(int array[], int startIndex, int midIndex, int endIndex) {

}

void mergeSort(int array[], int startIndex, int endIndex) {
	if (endIndex - startIndex == 2) //base-case
	{
		if (array[startIndex] > array[endIndex])
		{
			int temp = array[startIndex];
			array[startIndex] = array[endIndex];
			array[endIndex] = temp;
		}
	}
	else {
		int m = endIndex + startIndex / 2;
		mergeSort(array, 0, m);
		mergeSort(array, m+1, 0);
		merge(array, startIndex, m, endIndex);
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

