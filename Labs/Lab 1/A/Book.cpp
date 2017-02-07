#include "Book.h"

Book::Book(double netPrice) : Product(netPrice)
{
}

// no VAT on books
double Book::getGrossPrice() {
	return netPrice;
}