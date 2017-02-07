#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(string nameIn)
{
	name = nameIn;
}

void Person::printName()
{
	cout << "Name: " << name << endl;
}
string Person::getName()
{
	return string();
}

bool operator>(const Person& person, const Person& otherPerson)
{
	for (int i = 0; i < person.name.length() && i <= otherPerson.name.length(); i++) {
		// > 0 = true means there is a difference between them
		if (person.name.compare(otherPerson.name) > 0) {
			return true;
		}
		return false;
	}
}
