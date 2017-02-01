#include <iostream>
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
	start = (T2) 1;
	return (num1 + num2);
}
/*
Create a template function for the QuickSort algorithm  (http://en.wikipedia.org/wiki/Quicksort)

template<typename T>
T* quicksort(T* array)

*/
template<class T>
T parition(T* array, int start, int end) {
	
}

template<class T>
T* quicksort(T* array) {
	// wall, pivot  need to be abstracted first

	// from the current element create the quick sort algorithm

	/*
	Quicksort is an algorithm to sort a list. It is more efficient in most cases.
	O(n log n) ---> its big o notation

	test data: 6,5,1,3,8,4,7,9,2
	pivot is 2
	wall is to the left of 6
	current element is 6

	*/
}
int main() {
	// swap the values back and forth through the two template functions
	int a = 10 , b = 20;
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


	system("pause");
	return 0;
}