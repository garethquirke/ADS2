#pragma once
#include "Person.h"
using namespace std;

class Employee : public Person {
protected:
	double salary;
public:
	Employee(string, double);
	void printName();
};
