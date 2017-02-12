#pragma once
#include <string>
#include <iostream>
using namespace std;

class Repository {
protected:
	string owner;

public:
	Repository();
	Repository(string);
};