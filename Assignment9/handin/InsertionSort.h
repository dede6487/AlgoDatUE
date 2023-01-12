#pragma once

//slow sorting algo, output sorted in ascending order
//insertionSort according to the alogrithm presented in the lecture

void insertionSort(int array[], int len) {
	for (int i = 1; i < len; i++)
	{
		int r = array[i];
		int j = i - 1;
		while (j > 0 && array[j] > r) {	//> for ascending
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = r;
	}
}


