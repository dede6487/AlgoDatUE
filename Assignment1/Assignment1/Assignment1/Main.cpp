#include <iostream>
#include <fstream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <time.h>
#include <vector>
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

bool contains2(int arr[], int n, int val)//fine
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
	int m = (end - start) / 2;//integer division so no floor //+start
	//cout << m << endl;
	if(arr[m] == val)
	{
		return true;
		//cout << "found" << endl;
	}
	else {
		if (val < arr[m])
		{
			return contains3(arr, start, m - 1, val);
			//cout << "smaller" << endl;
		}
		else
		{
			return contains3(arr, m + 1, end, val);
			//cout << "greater" << endl;
		}
	}
	return false;
	//no end condition
	//restructure to fix
}

//Exercise 3 *******************************************************

//the idea here is, to save all the indices first, thus we only have to traverse the array once
//technically we still have the same number of operations because we then traverse the two arrays red and blue though
void RedBlue(bool arr[], int n) {
	vector<int> red;
	vector<int> blue;

	//here we assume red as true and blue as false

	for (int i = 0; i < n; i++) {
		if (arr[i] == true) {
			red.push_back(i);
		}
		else {
			blue.push_back(i);//print instead of storing
		}
	}

	cout << "red indices:" << endl;

	for (int i = 0; i < red.size(); i++) {
		cout << i << endl;
	}

	cout << "blue indices:" << endl;

	for (int i = 0; i < blue.size(); i++) {
		cout << i << endl;//then not needed
	}
}

//******************************************************************

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
		//cout << arr[j] << endl; //for manual checking if the array was loaded correctly
	}

	// Test the three methods with chosen values
	// (to verify that it works)

	int val = 53;
	bool containsa = false;
	bool containsb = false;
	bool containsc = false;

	containsa = contains(arr, size, val);
	containsb = contains2(arr, size, val);
	//containsc = contains3(arr, 0, size, val);

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

	//Contains3

	//start = clock();

	//for (int k = 0; k < 30000; k++) {
	//	int val = rand() % 300000;
	//	contains3(arr, 0, size, val);
	//}

	//time3 = (clock() - start) / (double)
	//	CLOCKS_PER_SEC;

	cout<< "Time it took the Algorithms for finishing the testcase:"<<endl;
	cout << "Contains1 took (seconds):" << time1 << endl;
	cout << "Contains2 took (seconds):" << time2 << endl;
	cout << "Contains3 took (seconds):" << time3 << endl;
}

