#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(string name, string complaint) : Person(name), complaint(complaint)
{
}

void Customer::printName()
{
	cout << "Name: " << name << " my complaint is: " << complaint << endl;
}
