#include "Guitar.h"

Guitar::Guitar() : Product(name)
{
	price = 0;
}

Guitar::Guitar(string name, double priceIn) : Product(name)
{
	price = priceIn;
}

double Guitar::getPrice()
{
	return price;
}

void Guitar::printDetails()
{
	cout << "Name: " << name << " Price: " << price << endl;
}

bool operator<(const Guitar& guitar, const Guitar& otherGuitar)
{
	if (guitar.price < otherGuitar.price) {
		return true;
	}
	return false;
}

bool operator<=(const Guitar & guitar, const Guitar & otherGuitar)
{
	if (guitar.price <= otherGuitar.price) {
		return true;
	}
	return false;
}
