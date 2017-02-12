#include "Repository.h"
#include "Language.h"
#include <string>
#include <iostream>
using namespace std;


//Declarations
void mergeSort(Language* array[], int start, int end);
int merge(Language* array[], int start, int end);

// Templates to work with our object array
void mergeSort(Language* array[], int start, int end) {
	int mid;

	if (start < end) {
		mid = (start + end) / 2;
		mergeSort(array, start, mid);
		mergeSort(array, mid + 1, end);
		merge(array, start, end);
	}
	return;
}

int merge(Language* array[], int start, int end) {
	Language *temp = new Language[end + 1];

	int mid = (start + end) / 2;
	int firsthalf = start;
	int secondhalf = mid + 1;
	int current = start;

	while (firsthalf <= mid && secondhalf <= end)
	{
		if (array[firsthalf] < array[secondhalf]) {
			temp[current] = array[firsthalf];
			current++;
			firsthalf++;
		}
		else {
			temp[firsthalf] = array[secondhalf];
			current++;
			secondhalf++;
		}
	}

	while (firsthalf <= mid) {
		temp[current] = array[secondhalf];
		current++;
		secondhalf++;
	}
	while (secondhalf <= mid) {
		temp[current] = array[secondhalf];
		current++;
		secondhalf++;
	}

	for (firsthalf = start; firsthalf < current; firsthalf++) {
		array[firsthalf] = temp[firsthalf];
	}
}


int main() {

	// create a array of langauges
	Language* lang[10];
	lang[0] = new Language("Gareth", "C#", 44);
	lang[1] = new Language("Tom", "R", 86);
	lang[2] = new Language("Tim", "F#", 32);
	lang[3] = new Language("Bill", "VB", 11);
	lang[4] = new Language("Lor", "Java", 4);
	lang[5] = new Language("Rick", "JavaScript", 15);
	lang[6] = new Language("Kate", "Perl", 3);
	lang[7] = new Language("Jimbo", "PHP", 55);
	lang[8] = new Language("Maria", "C++", 23);
	lang[9] = new Language("Lewis", "C", 40);

	
	// sort by merge sort through the count field
	mergeSort(lang, 0, 9);

	for (int i = 0; i < 10; i++) {
		cout << lang[i];
	}

	system("pause");
	return 0;
}