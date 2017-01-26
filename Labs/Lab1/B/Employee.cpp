#include "Employee.h"
#include <iostream>
using namespace std;
// name is passed back to the person class
Employee::Employee(string name, double salary) : Person(name), salary(salary)
{
}

void Employee::printName()
{
	cout << "Name: " << name << " salary is: " << salary << endl;
}
