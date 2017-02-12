#pragma once
#include "Repository.h"
#include <string>
#include <iostream>
using namespace std;

class Language : Repository {
	friend bool operator<(Language& language, Language& otherLanguage);
	

public:
	string name;
	int count;
	Language();
	Language(string, string, int);
	const Language Language::operator=(Language* otherLanguage);
	const Language* Language::operator=(Language otherLanguage);
};