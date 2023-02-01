#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

//Given finite set S decide if c is in the set
//With for

bool contains(int arr[], int n, int val)
{
	bool found = false;
	for (int i = 0; i < n; i++)
		if (arr[i] == val)
			found = true;
	return found;
}

bool contains2(int arr[], int n, int val)
{
	for (int i = 0; i < n; i++)
		if (arr[i] == val)
			return true;
	return false;
}

bool contains3(int arr[], int start, int end, int val)
{
	if (start > end)
		return false;
	int middle = start + (end  - start) / 2;
	if (arr[middle] == val)
		return true;
	if (arr[middle] > val)
		return contains3(arr, start, middle-1, val);
	return contains3(arr, middle+1, end, val);
}

int main()
{
	int i, n, number;

	ifstream inputFile;
	inputFile.open("../IntegerWerte.txt");

	n = 0;
	while (inputFile >> number)
		++n;
	inputFile.clear();
	inputFile.seekg(0, ios::beg);

	int s[n];
	i = 0;
	while (inputFile >> s[i++]);

	//cout << "This program decides if your number is in the given set." << std::endl;
	//cout << "Enter your number: ";
	//cin >> number;
	cout << contains(s, n, 179000) << endl;
	cout << contains(s, n, 179001) << endl;
	cout << contains2(s, n, 179000) << endl;
	cout << contains2(s, n, 179001) << endl;
	cout << contains3(s, 0, n - 1, 179000) << endl;
	cout << contains3(s, 0, n - 1, 179001) << endl;


	srand(time(0));

	clock_t start;
	double duration;
	
	//contains
	start = clock();
	for (i = 0; i < 100000; i++) {
		number = rand() % 299770;
		contains(s, n, number);
	}
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "duration: " << duration << endl;
	
	//contains2
	start = clock();
	for (i = 0; i < 100000; i++) {
		number = rand() % 299770;
		contains2(s, n, number);
	}
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout << "duration: " << duration << endl;

	//contains3
	start = clock();
	for (i = 0; i < 100000; i++) {
		number = rand() % 299770;
		contains3(s, 0, n - 1, number);
	}
	duration = (clock() - start) / (double)CLOCKS_PER_SEC;
	cout<< "duration: " << duration << endl;	
}


