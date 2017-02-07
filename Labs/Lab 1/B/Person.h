#pragma once
#include <string>
#include <iostream>
using namespace std;

class Person abstract
{
	friend bool operator>(const Person& person, const Person& otherPerson);

protected:
	
public:
	Person(string); // initialise the name
	// when virtual is taken out, overriding within the subclasses is not allowed
	virtual void printName();
	string name;
	string getName();
};

/* From the cake book
A class with one or more pure virtual functions is called an abstract class . An
abstract class can only be used as a base class to derive other classes. You cannot create
objects of an abstract class, since it is not a complete class definition.

This person class was made abstract. It turns the class into an interface and no longer
allows instances of itself to be created.
*/