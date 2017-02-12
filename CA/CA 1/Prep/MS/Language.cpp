#include "Language.h"

Language::Language() : Repository(owner)
{
	name = "";
	count = 0;
}

Language::Language(string, string nameIn, int countIn)  : Repository(owner)
{
	name = nameIn;
	count = countIn;
}

const Language Language::operator=(Language* otherLanguage)
{
	owner = otherLanguage->owner;
	name = otherLanguage->name;
	count = otherLanguage->count;

	return *this;
}

const Language* Language::operator=(Language otherLanguage)
{
	owner = otherLanguage.owner;
	name = otherLanguage.name;
	count = otherLanguage.count;

	Language *l;
	l = this;
	return l;
}

bool operator<(Language & language, Language& otherLanguage)
{
	if (language.count < otherLanguage.count) {
		return true;
	}
	else {
		return false;
	}
}