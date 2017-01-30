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
void multiples(T sum, T x, int n) {
	
	for (int i = 0; i < n; i++) {
		
	}
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

	system("pause");
	return 0;
}