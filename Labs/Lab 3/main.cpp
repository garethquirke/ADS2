// Author: Gareth Quirke
// Date: 7th February 2017

#include <iostream>
using namespace std;

// Declarations
void merge(int array[], int start, int length);
void mergeSort(int array[], int start, int length);

void mergeSort(int array[], int start, int length)
{
	int mid;
	// check if the first element comes before the last
	if (start < length) {
		// declare a mid point, this will be used to sort the first half of the array
		mid = (start + length) / 2;
		// first call, first half of the array
		mergeSort(array, start, mid);
		// second half of the array
		mergeSort(array, mid + 1, length);
	
		merge(array, start, length);
	}
	return;
}
/*
Source: Merge Sort on Youtube
Availible at: https://www.youtube.com/watch?v=bz5m-1yZ5D4
Usage: Based on this implementation structure. Modifying it to suit the paramters outlined in the 
	   labsheet. It gave me an overview of merge sort being used and called recursively. 
*/
void merge(int array[], int start, int length)
{
	// temporrary array to be filled with sorted members
	int *temp = new int[length];

	int mid = (start + length) / 2;
	// two variables to keep track of the the two halfs
	int firstHalf = start;
	// the second half starts one member past the midpoint
	int secondHalf = mid + 1;

	// keep track of the sorted array with this variable, current
	int current = start;


	// The array is in "two parts", check if the first element of each side is less than the last element of their side
	// [firstHalf......mid.......End of second half]
	while (firstHalf <= mid && secondHalf <= length) {

		// check if the first element in left array is less than right array
		// add it to temp if it is and increment the tracker variables
		if (array[firstHalf] < array[secondHalf]) {
			temp[current] = array[firstHalf];
			current++;
			firstHalf++;
		}
		// else the condition is the other way arround
		// increment the respective variables in this scenario
		else {
			temp[current] = array[secondHalf];
			current++;
			secondHalf++;
		}
	}
	// to catch the remaining elements of each half and position them in the sorted array
	while (firstHalf <= mid) {
		temp[current] = array[firstHalf];
		current++;
		firstHalf++;
	}
	while (secondHalf<= mid) {
		temp[current] = array[secondHalf];
		current++;
		secondHalf++;
	}
	// now assign elements of the sorted temporary array to the array
	for (firstHalf = start; firstHalf < current; firstHalf++) {
		array[firstHalf] = temp[firstHalf];
	}
}
int main()
{
	int array[10] = { 6,5,4,3,2,1,10,9,8,7 };
	cout << "Before sort" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << ", ";
	}
	cout << endl;
	cout <<"After sort" << endl;


	mergeSort(array, 0, 9);

	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << ", ";
	}
	cout << endl;
	system("pause");
	return 0;
}