// Author: Gareth Quirke
// Date: 8th February 2017
#include <iostream>
using namespace std;

// declarations
void quickSort(int* array, int first, int last);
int quickSortDivide(int* array, int first, int last);

int main() {

	int data[9] = { 6,5,1,3,8,4,7,9,2 };
	int *dataptr = data;
	cout << "Before sort: ";
	for (int i = 0; i < 9; i++) {
		cout << data[i] << " ";
	}
	cout << endl;

	int start = 0, end = 8;

	quickSort(dataptr, start, end);
	cout << "After sort: ";
	for (int i = 0; i < 9; i++) {
		cout << data[i] << " ";
	}
	cout << endl;


	const int count = 50;
	int array3[count];
	for (int i = 0; i < count; i++) {
		array3[i] = rand() % 1000;
	}
	cout << "unsorted list" << endl;
	for (int i = 0; i < count; i++) {
		cout << array3[i] << ", ";
	}
	cout << endl;
	quickSort(array3, 0, count - 1);
	cout << "After sort" << endl;
	for (int i = 0; i < count; i++) {
		cout << array3[i] << ", ";
	}
	cout << endl;


	system("pause");
	return 0;
}

void quickSort(int* array, int first, int last)
{
	int pivotPole;
	
	// check: have we reached end of the sort?
	if (first < last ) {
		// split the array, find the pivot pole
		pivotPole = quickSortDivide(array, first, last);
		// sort the elements before the pivot pole
		quickSort(array, first, pivotPole - 1);
		// sort elements after the pivot pole
		quickSort(array, pivotPole + 1, last);
	}
}
/*
Source
Name: Quicksort (theory)
Source: https://www.youtube.com/watch?v=aQiWF4E8flQ
Usage: Based on information learned here.

Name: DIT Computing
Source: http://www.comp.dit.ie/rlawlor/Alg_DS/sorting/quickSort.c
Usage: Based on
*/
int quickSortDivide(int* array, int first, int last)
{
	// The pivot is our starting point
	int pivot = array[first];
	int wall = first;

	// comapre values, move the wall up one once the comparison is complete to assess the array further
	for (int i = (first + 1); i <= last; i++) {
		if (array[i] <= pivot) {
			swap(array[wall + 1], array[i]);
			swap(array[wall], array[wall + 1]);
			wall++;
		}
	}
	// the wall is returned this is our new pivot point
	return wall;
}
