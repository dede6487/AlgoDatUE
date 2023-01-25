#pragma once

#include<random>

using namespace std;

//due to time problems I resorted to only implement parts of this assignment


//disclaimer for the Partition function:
//Because I had no Idea on how to implement this function, I used https://www.geeksforgeeks.org/cpp-program-for-quicksort/ as a reference
//this leads to similarities in parts of the function to their solution

int Partition(int arr[], int left, int m, int right) {
	int p = arr[m];

	int temp = 0;
	for (int i = left + 1; i <= right; i++) {
		if (arr[i] <= p) {
			temp++;
		}
	}

	p += left + temp;
	temp = arr[p];
	arr[p] = arr[left];
	arr[left] = temp;


	int partLeft = left;
	int partRight = right;
	while (partLeft < left && partRight < right) {
		while (arr[partLeft] <= p) {
			partLeft++;
		}
		while (arr[partRight] > p) {
			partRight--;
		}
		while (partLeft < p && partRight > p) {
			temp = arr[partLeft++];
			arr[partLeft++] = arr[partRight--];
			arr[partRight--] = temp;
		}
	}

	return p;
}


void QuickSort(int arr[], int left, int right) {
	if (left < right) {
		int range = left - right - 1;
		int m = rand() % range + left;

		int p = Partition(arr, left, m, right);

		QuickSort(arr, left, p - 1);
		QuickSort(arr, p + 1, right);
	}
	return;
}