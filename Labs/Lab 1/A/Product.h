#pragma once

class Product {
protected:
	double netPrice;

public:
	Product(double);
	~Product();

	double getGrossPrice();
};
