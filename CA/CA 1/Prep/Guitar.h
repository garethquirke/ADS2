#pragma once
#include "Product.h"
class Guitar : public Product {

	friend bool operator<(const Guitar& guitar, const Guitar& otherGuitar);
	friend bool operator<=(const Guitar& guitar, const Guitar& otherGuitar);
protected:
	double price;
public:
	Guitar();
	Guitar(string, double);
	double getPrice();

	void printDetails();
};