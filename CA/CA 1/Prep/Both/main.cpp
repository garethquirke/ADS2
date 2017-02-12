// Author: Gareth Quirke
// Date: 12th February 2017
// Description: Show mergesort and Quicksort working for an array
#include <iostream>
using namespace std;

// Declaratations
void merge(int array[], int start, int lenght);
void mergeSort(int array[], int start, int length);

void quickSort(int* array, int first, int last);
int quickSortDivide(int* array, int first, int last);

void mergeSort(int array[], int start, int length)
{
	int mid;
	// check if the first element comes before the last
	if (start < length) {
		// declare a split in the array , left and right
		mid = (start + length) / 2;
		// first call. left half of the array
		mergeSort(array, start, mid);
		// second half of the array
		mergeSort(array, mid + 1, length);
		merge(array, start, length);
	}
	return;
}
void merge(int array[], int start, int lenght)
{
	int *temp = new int[lenght + 1];
	int mid = (start + lenght) / 2;

	// two variables to keep track of the two halfs: left & right
	int firsthalf = start;
	int secondhalf = mid + 1;
	
	// keep track of the sorted array
	int current = start;

	while (firsthalf <= mid && secondhalf <= lenght) {
		if (array[firsthalf] < array[secondhalf]) {
			temp[current] = array[firsthalf];
			current++;
			firsthalf++;
		}
		else {
			temp[current] = array[secondhalf];
			current++;
			secondhalf++;
		}
	}

	// sort remaining elements
	while (firsthalf <= mid) {
		temp[current] = array[firsthalf];
		current++;
		firsthalf++;
	}
	while (secondhalf <= mid) {
		temp[current] = array[secondhalf];
		current++;
		secondhalf++;
	}

	for (firsthalf = start; firsthalf < current; firsthalf++) {
		array[firsthalf] = temp[firsthalf];
	}

	delete[] temp;
	temp = NULL;

}


void quickSort(int* array, int first, int last) {
	int pivotPole;
	// check: have we reached the end of the sort
	if (first < last) {
		// split the array, find the pivot pole
		pivotPole = quickSortDivide(array, first, last);
		// sort before the pivot
		quickSort(array, first, pivotPole - 1);
		// sort after the pivot
		quickSort(array, pivotPole + 1, last);
	}
}

int quickSortDivide(int* array, int first, int last) {
	int pivot = array[first];
	int wall = first;

	for (int i = (first + 1); i <= last; i++) {
		if (array[i] <= pivot) {
			swap(array[wall + 1], array[i]);
			swap(array[wall], array[wall + 1]);
			wall++;
		}
	}
	return wall;
}


int main() {
	
	const int count = 100;
	int array1[count];
	for (int i = 0; i < count; i++) {
		array1[i] = rand() % 1000;
	}
	quickSort(array1, 0, count - 1);
	for (int i = 0; i < count; i++) {
		cout << array1[i] << ",";
	}
	cout << endl << endl;

	int array2[count];
	for (int i = 0; i < count; i++) {
		array2[i] = rand() % 1000;
	}
	mergeSort(array2, 0, count - 1);
	for (int i = 0; i < count; i++) {
		cout << array2[i] << ",";
	}

	system("pause");
	return 0;
}


