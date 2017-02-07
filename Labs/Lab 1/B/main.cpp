// Author: X00108966 Gareth Quirke
// Date: 26th January 2017

#include<iostream>
#include <algorithm>
#include "Person.h"
#include "Employee.h"
#include "Customer.h"
using namespace std;

// Declaration
void sort(Person *people[5]);

int main() {

	// base class pointer
	Person *personPtr;

	//personPtr = new Person("Timbo Timber");
	//personPtr->printName();

	Customer c("Bishop Muzorewa", "this is a complaint");
	personPtr = &c;
	personPtr->printName();

	Employee e("Tim Canterbury", 40000);
	personPtr = &e;
	personPtr->printName();

	system("pause");

	Person*people[5];
	people[0] = new Customer("alan", "complaint ugh");
	people[1] = new Employee("zombie", 56000);
	people[2] = new Customer("cris", "i complain alot");
	people[3] = new Employee("bob", 34000);
	people[4] = new Customer("david brent", "sometimes the complaints will be false");

	// Before sort runs
	cout << "Before sort is run" << endl;
	for (int i = 0; i < 5; i++) {
		people[i]->printName();
	}
	system("pause");

	sort(people);
	cout << "After sort is run" << endl;
	for (int i = 0; i < 5; i++) {
		people[i]->printName();
	}

	system("pause");
}

void sort(Person * people[5])
{
	bool swap = false;
	Person*temp;
	do {
		swap = false;
		for (int i = 1; i < 5; i++) {

			// overloaded operator > returns true or false to determine if switch needs to be made
			if ((people[i - 1]->name > people[i]->name) == true) {
				temp = people[i];
				people[i] = people[i - 1];
				people[i - 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}