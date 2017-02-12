#include "Product.h"

Product::Product()
{
	name = "";
}

Product::Product(string nameIn)
{
	name = nameIn;
}

Product::~Product()
{
	name = "";
}

string Product::getName()
{
	return name;
}

void Product::printName()
{
	cout << "Name of product: " << name;
}
