#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Implement a program that computes recursively the maximum 
//of an array's elements (file Integers.txt).

int max(int arr[], int n)
{
	if (n == 1)
		return arr[0];
	int oldmax = max(arr, n - 1);
	return arr[n - 1] > oldmax ? arr[n-1] : oldmax ;
}

int main()
{
	int i, n, number;

	ifstream inputFile;
	inputFile.open("Integers.txt");

	n = 0;
	while (inputFile >> number)
		++n;
	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	int s[n];
	i = 0;
	while (inputFile >> s[i++]);
	inputFile.close();

	cout << "Max(n)  = " << max(s, n) << endl;
}


