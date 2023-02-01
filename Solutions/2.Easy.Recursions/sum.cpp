#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Implement a program that computes recursively the sum 
//of an array's elements (file Integers.txt).

int sum(int arr[], int n)
{
	if (n <= 0)
		return 0;
	return arr[n - 1] + sum(arr, n - 1);
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

	if (n > 5) cout << "S(5)  = " << sum(s, 5) << endl; // sum of the first 5 elements
	if (n > 10) cout << "S(10) = " << sum(s, 10) << endl; // sum of the first 10 elements
	cout << "S(n)  = " << sum(s, n) << endl; // sum of all elements
}


