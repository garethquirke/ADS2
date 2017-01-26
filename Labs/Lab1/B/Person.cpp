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

bool Person::operator>(const Person & p)
{
	// iterate through the name
	for (int i = 0; i < name.length; i++) {
		if (name.at(i) > p.name.at(i)) {
			{
				return true;
			}
		}
		return false;
	}
}
