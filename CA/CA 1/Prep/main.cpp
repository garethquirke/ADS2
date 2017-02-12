#include "Product.h"
#include "Guitar.h"
#include <iostream>
using namespace std;

// Create a template to sort an array of Guitars by price low to high
// use the quicksort method
int partition(Guitar *array[], int start, int end) {

	Guitar* pivot = array[start];
	int wall = start;

	for (int i = start + 1; i <= end; i++) {
		if (array[i]->getPrice() <= pivot->getPrice()) {
			wall++;
			swap(array[i], array[wall]);
			// the wall is incremented as this section of the array becomes sorted
			
		}
	}
	swap(array[wall], array[start]);
	return wall;

}

template <class T>
void quicksort(T *array[], int start, int end) {
	int pivotPole = 0;

	if (start < end) {
		pivotPole = partition(array, start, end);
		quicksort(array, start, pivotPole - 1);
		quicksort(array, pivotPole + 1, end);
	}
}

int main() {

	Guitar *garray[10];
	garray[0] = new Guitar("1", 40);
	garray[1] = new Guitar("2", 56);
	garray[2] = new Guitar("3", 59);
	garray[3] = new Guitar("4", 12);
	garray[4] = new Guitar("5", 113);
	garray[5] = new Guitar("6", 11);
	garray[6] = new Guitar("7", 9);
	garray[7] = new Guitar("8", 8);
	garray[8] = new Guitar("9", 3);
	garray[9] = new Guitar("10", 2);

	Guitar g = Guitar("Fender",34);
	g.printDetails();
	
	quicksort(garray, 0, 9);
	for (int i = 0; i < 10; i++) {
		 garray[i]->printDetails();
	}


	system("pause");
	return 0;
}