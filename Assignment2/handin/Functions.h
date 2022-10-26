//*********************************************************************************
//This file contains all the functions that had to be implemented for Assignment2
//keeping everything in the Main.cpp file would have lead to a lack of clarity
//
//*********************************************************************************

#pragma once

#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <time.h>

#include "Matrix.h"
#include <vector>

using namespace std;


//************************************ Task 1 *******************************************


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

bool contains3(int arr[], int start, int end, int val)
{
	int m = ((end - start) / 2) + start;//integer division so no floor
	if (m == start || m == end)
	{
		return false;
	}
	if (arr[m] == val)
	{
		return true;
	}
	else {
		if (val < arr[m])
		{
			return contains3(arr, start, m, val);
		}
		else
		{
			return contains3(arr, m, end, val);
		}
	}
}


//************************************ Task 2 *******************************************


//using the contains1 algorithm from above, the function containsindex returns an int-vector containing all the indices
//of val in arr
vector<int> containsindex(int arr[], int n, int val)
{
	vector<int> temp;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == val)
		{
			temp.push_back(i + 1);
		}
	}
	return temp;
}


//************************************ Task 3 *******************************************


//auxilary function for the matrix binary search
tuple<int, int> containsMatrixAux(Matrix matrix, int start, int end, int val) {
	int m = ((end - start) / 2) + start;//integer division so no floor
	if (m == start || m == end)
	{
		cout << "Error: element not in matrix";
		tuple<int, int> ret;
		return make_tuple(-1, -1);
	}
	if (matrix(m) == val)
	{
		return matrix.position(m);
	}
	else {
		if (val < matrix(m))
		{
			return containsMatrixAux(matrix, start, m, val);
		}
		else
		{
			return containsMatrixAux(matrix, m, end, val);
		}
	}
}

//matrix binary search
tuple<int, int>  containsMatrix(Matrix matrix, int val)
{
	tuple<int, int> size = matrix.size();
	int rows = get<0>(size);
	int cols = get<1>(size);

	return containsMatrixAux(matrix, 0, rows * cols, val);
}


//************************************ Task 5 *******************************************


int intSum(int arr[], int n)
{
	if (n > 0) {
		return arr[n] + intSum(arr, n - 1);
	}
}