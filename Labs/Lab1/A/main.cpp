// Author: X00108966 Gareth Quirke
// Date: 24th January 2017

#include<iostream>
#include "Product.h"
#include "Software.h"
#include "Book.h"
using namespace std;

// Declaration
void sort(Product *array[10]);

int main() {

	// array of 10 pointers to Product
	Product *products[10];

	// pointer to a: book, software
	Book *book;
	Software *software;

	

	// enter details for a book and a software item
	// store the addresses in the pointers created above
	double inputPrice;

	cout << "Enter a price for a book item: " << endl;
	cin >> inputPrice;
	Book bookObj(inputPrice);
	book = &bookObj;

	cout << "Enter a price for a software item: " << endl;
	cin >> inputPrice;
	Software softwareObj(inputPrice);
	software = &softwareObj;

	// add the pointers to the products array( of pointers)
	products[0] = book;
	products[1] = software;

	// verify if the gross price method works 
	cout << "Book gross price is: €" << bookObj.getGrossPrice() << endl;
	cout << "Software gross price is: €" << softwareObj.getGrossPrice() << endl;

	// Fill the remaining 8 spaces in the array from user input
	// loop backwards from 10 --> 2, 0 & 1 are occupied
	for (int i = 10; i-- > 1;) {

		int choice;
		cout << "Enter 1 for Book, 2 for Software" << endl;
		cin >> choice;

		if (choice == 1) {
			double inputPrice;
			cout << "Enter price of book" << endl;
			cin >> inputPrice;
			products[i] = new Book(inputPrice);
		}
		else if (choice == 2) {
			double inputPrice;
			cout << "Enter price of software" << endl;
			cin >> inputPrice;
			products[i] = new Software(inputPrice);
		}
		else {
			cout << "Incorrect choice" << endl;
		}
	}

	// print price of each item
	for (int i = 0; i < 10; i++) {
		cout << products[i]->getGrossPrice() << endl;
	}


	// create a sort function to sort by ascending order of price


	system("pause");
	return 0;
}
// Bubble sort
void sort(Product * products[10])
{
	for (int i = 0; i < 10; i++) {
		if (products[i + 1]->getGrossPrice() < products[i]->getGrossPrice()) {
			// finsish this part
		}
	}
}
