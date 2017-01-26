// Author: X00108966 Gareth Quirke
// Date: 26th January 2017

#include<iostream>
#include <algorithm>
#include "Person.h"
#include "Employee.h"
#include "Customer.h"
using namespace std;

// Declaration


int main() {

	// base class pointer
	Person *personPtr;

	//personPtr = new Person("Timbo Timber");
	//personPtr->printName();

	personPtr = new Employee("Tim Canterbury", 40000);
	personPtr->printName();

	personPtr = new Customer("Bishop Muzorewa", "this is a complaint");
	personPtr->printName();

	system("pause");

}