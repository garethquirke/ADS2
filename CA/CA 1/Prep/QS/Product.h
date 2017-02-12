#pragma once
#include <string>
#include <iostream>
using namespace std;

class Product abstract{
public:
	string name;
	Product();
	Product(string);
	~Product();

	string getName();
	virtual void printName();
};