#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <Matrix.h>
using namespace std;

//Given finite set S decide if c is in the set

bool contains(int arr[], int n, int val)
{
	bool b = false;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == val)
		{
			b = true;
		}
	}
	return b;
}

int* containsindex(int arr[], int n, int val)
{
	vector<int> temp;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == val)
		{
			temp.push_back(i);
		}
	}
	return temp.data();
}

bool contains2(int arr[], int n, int val)
{
	int i = 0;
	while (i < n && arr[i] != val)
	{
		i++;
	}
	if (i < n)
	{
		return true;
	}
	else {
		return false;
	}
}

//ther is some problem here which I can not spot
//comments for troubeshooting
bool contains3(int arr[], int start, int end, int val)
{
	int m = ((end - start) / 2) + start;//integer division so no floor
	//cout << m << endl;
	if (m == start || m == end)
	{
		return false;
	}
	if (arr[m] == val)
	{
		return true;
		//cout << "found" << endl;
	}
	else {
		if (val < arr[m])
		{
			return contains3(arr, start, m, val);
			//cout << "smaller" << endl;
		}
		else
		{
			return contains3(arr, m, end, val);
			//cout << "greater" << endl;
		}
	}
}

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

	//vector.data

	for (int j = 0; j < size; j++) {
		arr[j] = tempv[j];
		//cout << arr[j] << endl; //for manual checking if the array was loaded correctly
	}

	// Test the three methods with chosen values
	// (to verify that it works)

	int val = 53;
	bool containsa = false;
	bool containsb = false;
	bool containsc = false;

	containsa = contains(arr, size-1, val);
	containsb = contains2(arr, size-1, val);
	containsc = contains3(arr, 0, size-1, val);

	cout << "Testing if the Algorithms work by checking for the element " << val << endl;
	cout << "Contains1 " << containsa << endl;
	cout << "Contains2 " << containsb << endl;
	cout << "Contains3 " << containsc << endl;

	// Clock each method by running it 300000 times
		// for a random c

	double time1 = 0;
	double time2 = 0;
	double time3 = 0;

	clock_t start;

	//Contains1
	//start = clock();

	//for (int k = 0; k < 300000; k++) {
	//	int val = rand() % 300000;
	//	contains(arr, size-1, val);
	//}

	//time1 = (clock() - start) / (double)
	//	CLOCKS_PER_SEC;	


	//Contains2
	//start = clock();

	//for (int k = 0; k < 300000; k++) {
	//	int val = rand() % 300000;
	//	contains2(arr, size-1, val);
	//}

	//time2 = (clock() - start) / (double)
	//	CLOCKS_PER_SEC;

	//Contains3

	//start = clock();

	//for (int k = 0; k < 300000; k++) {
	//	int val = rand() % 300000;
	//	contains3(arr, 0, size-1, val);
	//}

	//time3 = (clock() - start) / (double)
	//	CLOCKS_PER_SEC;

	cout << "Time it took the Algorithms for finishing the testcase:" << endl;
	cout << "Contains1 took (seconds):" << time1 << endl;
	cout << "Contains2 took (seconds):" << time2 << endl;
	cout << "Contains3 took (seconds):" << time3 << endl;

	//just Algorithm 1 is suited for Task 2, because the 3rd requires an ordered array
	//and the 2nd breaks as soon as the first is found

	vector<int> temp2;

	ifstream Integer;

	Integer.open("Integers.txt");

	while (Integer >> number)
	{
		temp2.push_back(number);
	}

	Integer.close();

	int size2 = temp2.size();

	int* arr2 = new int[size2];

	arr2 = temp2.data();

	int val2 = 2;

	int* index;

	index = containsindex(arr2, size2 - 1, val2);

	//print index
}

