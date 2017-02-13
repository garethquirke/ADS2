// Author: Gareth Quirke X00108966
// Date: 14th February 2017
// Title: CA 1 - Recursion
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

// Declarations
template<typename T>
void quicksort(T[], int start, int end);

template<typename T>
int partition(T[], int start, int end);


template<typename T>
int partition(T array[], int start, int end) {
	int wall = start;
	int pivot = array[start];
	// loop through the array, from start to finish
	for (int i = start + 1; i <= end; i++) {
		// if the the value in the loop is less then the pivot point
		if (array[i] < pivot) {
			// if it is: preform two swaps.
			// The wall here acts like the current element, beyond it lies the sorted elements for this iteration
			swap(array[wall + 1], array[i]);
			swap(array[wall], array[wall + 1]);
			wall++;
		}
	}
	// final steps of this method are to increment and return it 
	return wall;
}

template<typename T>
void quicksort(T array[], int start, int end) {
	// assign the pivotpole as the point in the array to be compared
	int pivotPole;

	// check if the sort is complete through the base case
	if (start < end) {
		// partition the array and assign this value to our pivotpole
		pivotPole = partition(array, start, end);

		// sort left side from the pivot
		quicksort(array, start, pivotPole);

		// now sort the right side from the pivot
		quicksort(array, (pivotPole+ 1), end);
	}
}



int main() {

	const int size = 50;
	int array[size];
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 1000;
	}
	cout << "Unsorted array of size " << size << endl;
	for (int i = 0; i < size; i++) {
		cout << array[i] << ",";
	}

	cout << endl << endl;

	cout << "Sorted array of size " << size << endl;
	quicksort(array, 0, size - 1);
	for (int i = 0; i < size; i++) {
		cout << array[i] << ",";
	}


	cout << endl;
	system("pause");
	return 0;
}