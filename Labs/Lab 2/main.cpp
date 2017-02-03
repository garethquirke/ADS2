// Author: X00108966 Gareth Quirke
// Date: 30th January 2017

#include <iostream>
#include <algorithm>
using namespace std;

// template of generic type T
// Pass by reference
template<class T>
void swapOne(T& a, T& b) {
	T temp = b;
	b = a;
	a = temp;
}

// Pass by address
template<class T>
void swapTwo(T* a, T* b) {
	T temp = *b;
	*b = *a;
	*a = temp;
}

template<class T>
void multiples(T& sum, T x, int n) {
	// sum = 1 + x + 2x + 3x + ... + nx
	sum = 1;
	cout << "Multiples of " << x << " are ";
	for (int i = 0; i < n; i++) {
		sum = x * i;
		cout << sum << " ";
	}
	cout << endl;
}

// init sets the value of the parameter start to a T2 - type value of 1
// returns a T1 - type value which is the sum of num1 and num2
template<class T1, class T2>
T1 init(T1 num1, T1 num2, T2&start) {
	start = (T2)1;
	return (num1 + num2);
}

/*
Create a template function for the QuickSort algorithm  (http://en.wikipedia.org/wiki/Quicksort)

Source
Name: Quicksort (theory)
Source: https://www.youtube.com/watch?v=aQiWF4E8flQ
Usage: Based on information learned here.

Source
Name: DIT Computing 
Source: http://www.comp.dit.ie/rlawlor/Alg_DS/sorting/quickSort.c
Usage: Based on

Notes:
- Quicksort is an algorithm to sort a list. It is more efficient in most cases.
- O(n log n) ---> its big o notation

- test data: 6,5,1,3,8,4,7,9,2
- pivot is 2
- wall is to the left of 6
- current element is 6

*/
template<class T>
void quicksort(T array[], int start, int end) {
	int pivotPole;

	if (start < end) {
		// split the array and find the pivot point
		pivotPole = partition(array, start, end);
		// Recursion here to quicksort after the pivot point is found carry out two actions on the array
		// first, sort before the pivot pole
		quicksort(array, start, pivotPole - 1);
		// then sort after the pivot point
		quicksort(array, pivotPole + 1, end);
	}
}

template<class T>
T partition(T array[], T start, T end) {

	// pivot is passed in as the starting point 
	T pivot = array[start];
	T wall = start;

	// check the current position and switch values until the array is sorted
	for (int i = start + 1; i <= end; i++) {
		if (array[i] <= pivot) {
			swap(array[wall + 1], array[i]);
			swap(array[wall], array[wall + 1]);
			// the wall is incremented as this section of the array becomes sorted
			wall++;
		}
	}
	return wall;
}

int main() {
	// swap the values back and forth through the two template functions
	int a = 10, b = 20;
	float c = 10, d = 20;
	swapOne(a, b);
	swapOne(c, d);

	cout << a << "   " << b << endl;
	cout << c << "   " << d << endl;

	swapTwo(&a, &b);
	swapTwo(&c, &d);
	cout << a << "   " << b << endl;
	cout << c << "   " << d << endl;

	int sum, x = 5, n = 10;
	multiples(sum, x, n);
	cout << endl;

	int data[9] = { 6,5,1,3,8,4,7,9,2 };
	cout << "Before sort: ";
	for (int i = 0; i < 9; i++) {
		cout << data[i] << " ";
	}
	cout << endl;

	int start = 0, end = 8;

	quicksort(data, start, end);
	cout << "After sort: ";
	for (int i = 0; i < 9; i++) {
		cout << data[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}