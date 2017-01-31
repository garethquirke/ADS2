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
template<class T1>
T1 init(T1 num1, T1 num2, T2&start) {

}
/*
1.	Create the C++ Function Template named init so that it has three
parameters whose types are determined by the function template type
parameters T1 and T2.  The function header is shown below.  init sets
the value of the parameter start to a T2-type value of 1.  init
returns a T1-type value which is the sum of num1 and num2.

T1 init (T1 num1, T1 num2, T2& start)

Create a template function for the QuickSort algorithm  (http://en.wikipedia.org/wiki/Quicksort)

template<typename T>
T* quicksort(T* array)

*/

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