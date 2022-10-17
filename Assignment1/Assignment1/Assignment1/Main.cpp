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


	// Test the three methods with chosen values
	// (to verify that it works)


	// Clock each method by running it 300000 times
		// for a random c
}

