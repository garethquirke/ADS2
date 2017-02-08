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


	if (start >= length)
	{
		return;
	}

	mid = (start + length) / 2;

	mergeSort(array, start, mid);

	mergeSort(array, mid + 1, length);
	merge(array, start, length);
}

void merge(int array[], int start, int length)
{

	int size = (length - start) + 1;
	int *temp = new int[size]();

	int current = start;
	int mid = (start + length) / 2;

	int x = 0;
	int y = mid + 1;

	while (x < size)
	{
		if ((current <= mid) && (array[current] < array[y]))
		{
			temp[x++] = array[current++];
		}
		else
		{
			temp[x++] = array[y++];
		}

	}

	for (x = 0; x < size; x++)
	{
		array[start + x] = temp[x];
	}

	delete[]temp;

}

int main()
{
	int array[10] = { 9,5,8,4,7,2,6,3,2,10 };

	mergeSort(array, 0, 9);


	for (int i = 0; i < 10; i++)
	{
		cout << array[i] << endl;
	}
	system("pause");
	return 0;
}