#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Given finite set S decide if c is in the set

bool contains(int arr[], int n, int val)
{
	bool b = false;
	for (int i = 0; i <= n; i++)
	{
		if (arr[i] == val)
		{
			return b;
		}
	}
	return b;
}

bool contains2(int arr[], int n, int val)
{
	int i = 0;
	while (i <= n && arr[i] != val)
	{
		i++;
	}
	if (i <= n)
	{
		return true;
	}
	else {
		return false;
	}
}

bool contains3(int arr[], int start, int end, int val)
{
	int m = floor((end - start + 1) / 2);
	if (m == 0) {
		return false;
	}
	if (arr[m] == val)
	{
		return true;
	}
	else {
		if (val < m)
		{
			return contains3(arr, start, m - 1, val);
		}
		else
		{
			return contains3(arr, m + 1, end, val);
		}
	}


}

int main()
{
	// Read the data from the file

	int number;
	int c = 10;
	int* arr = new int[c];
	ifstream inputfile;

	inputfile.open("IntegerWerte.txt");

	for (int i = 0; i <= c; i++) {
		arr[i] = 0;
	}

	int i = 0;
	while (inputfile >> number)
	{
		if (c <= i) {
			int* temp = new int[2 * c];
			for (int j = 0; j <= c; j++) {
				temp[j] = arr[j];
			}
			arr = temp;
			delete[] temp;
		}
		arr[i] = number;
		i++;
	}

	// Test the three methods with chosen values
	// (to verify that it works)

	int val = 53;
	bool containsa = false;
	bool containsb = false;
	bool containsc = false;

	containsa = contains(arr, i, val);
	containsb = contains2(arr, i, val);
	containsc = contains3(arr, 0, i, val);

	// Clock each method by running it 300000 times
		// for a random c

	double time1 = 0;
	double time2 = 0;
	double time3 = 0;

	clock_t start;
	double duration;

	start = clock();

	for (int k = 0; k < 30000; k++) {
		int val = rand();//RANGEEEE!!!!!!
		contains(arr, i, val);
	}
	
	duration = (clock() - start) / (double)
		CLOCKS_PER_SEC;

	time1 = duration;
}

