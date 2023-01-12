#pragma once

//merge sort with output in decending order according to the example done in the lecture

void merge(int array1[], int startIndex, int midIndex, int endIndex) {
	int* array2 = new int[endIndex - startIndex];

	int leftLen = midIndex - startIndex + 1;
	int rightLen = endIndex - midIndex;

	for (int i = 0; i < endIndex - startIndex + 1; i++) {
		if (i < midIndex - startIndex + 1) {
			array2[i] = array1[startIndex + i];
		}
		else {
			array2[i] = array1[midIndex + i + 1];
		}
	}

	int indexLeft = 0;
	int indexRight = midIndex + 1;
	int indexMerge = 0;

	while (indexLeft < leftLen && indexRight < rightLen) {
		if (array2[indexLeft] <= array2[indexRight]) {
			array1[indexMerge] = array2[indexLeft];
			indexLeft++;
		}
		else {
			array1[indexMerge] = array2[indexRight];
			indexRight++;
		}
		indexMerge++;
	}

	//copying the rest of the array

	while (indexLeft < leftLen) {
		array1[indexMerge] = array2[indexLeft];
		indexLeft++;
		indexMerge++;
	}

	while (indexRight < rightLen) {
		array1[indexMerge] = array2[indexRight];
		indexRight++;
		indexMerge++;
	}
}

void mergeSort(int array1[], int startIndex, int endIndex) {
	if (endIndex - startIndex <= 1) //base-case
	{
		return;
	}
	else {
		int m = endIndex + startIndex / 2;
		mergeSort(array1, startIndex, m);
		mergeSort(array1, m + 1, endIndex);
		merge(array1, startIndex, m, endIndex);
	}
}