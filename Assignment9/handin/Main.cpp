#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

#include"InsertionSort.h"
#include"MergeSort.h"

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

	for (unsigned int j = 0; j < size; j++) {
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

	for (unsigned int i = 1; i < size - 1; i++) {
		if (testarr[i] > testarr[i + 1]) { //!(testarr[i] <= testarr[i + 1]
			test1 = false;
		}
	}

	cout << "insertion Sort is correct:" << test1 << endl;

	//merge sort
	testarr = arr;

	mergeSort(testarr, 0, size);

	for (unsigned int i = 1; i < size - 1; i++) {
		if (testarr[i] > testarr[i + 1]) { //!(testarr[i] <= testarr[i + 1]
			test2 = false;
		}
	}

	//for testing for smaller arrays if the code is correct:
	//for (unsigned int i = 1; i < size; i++) {
	//	cout << testarr[i] << endl;
	//}

	cout << "merge Sort is correct:" << test2 << endl;

	cout << "Time it took the Algorithms for finishing the testcase:" << endl;

	// Clock each method by running it 1 times
	//caution, these timings also include the copying of the array

	double time1 = 0;
	double time2 = 0;

	clock_t start;

	//slow sort
	start = clock();

	for (int k = 0; k < 1; k++) {
		testarr = arr;
		insertionSort(testarr, size);
	}

	time1 = (clock() - start) / (double)
		CLOCKS_PER_SEC;

	cout << "insertion Sort took (seconds):" << time1 << endl;

	//merge sort
	start = clock();

	for (int k = 0; k < 1; k++) {
		testarr = arr;
		mergeSort(testarr, 0, size);
	}

	time2 = (clock() - start) / (double)
		CLOCKS_PER_SEC;

	delete[] testarr;

	cout << "merge Sort took (seconds):" << time2 << endl;
}

//even though merge sort still has a problem, I still included the timing for this algorithm as well

//output for a testrun:

//Testing if the algorithms are correct :
//insertion Sort is correct : 1
//merge Sort is correct : 0
//Time it took the Algorithms for finishing the testcase :
//insertion Sort took(seconds) : 2.346
//merge Sort took(seconds) : 0.039

