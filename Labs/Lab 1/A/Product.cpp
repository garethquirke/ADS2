#include "Product.h"

Product::Product(double netPricein)
{
	netPrice = netPricein;
}

Product::~Product()
{
	netPrice = 0.0;
}

double Product::getGrossPrice()
{
	// gross price = net price * tax rate 
	return (netPrice*1.21);
}
