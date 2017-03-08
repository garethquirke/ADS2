#pragma once
#include <iostream>
using namespace std;


class City {
private:
	string name;
	pair<double, double> coordinates;
	double population;
	double averageTemperature;

public:
	City(string, pair<double, double>, double, double);
	~City();

	friend ostream& operator<<(ostream& os, const City& c);


	string getName();
	pair<double, double> getCoordinates();
	double getPopulation();
	double getAverageTemperature();
};