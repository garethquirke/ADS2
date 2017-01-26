#pragma once
#include "Person.h"
using namespace std;

class Customer : public Person {
protected:
	string complaint;
public:
	Customer(string, string);
	void printName();
};