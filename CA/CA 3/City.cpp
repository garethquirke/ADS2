#include "City.h"
#include <iostream>
#include <string>
using namespace std;
City::City(string name, pair<double, double> coordinates, double population, double averageTemperature) : name(name), coordinates(coordinates), population(population), averageTemperature(averageTemperature)
{
}

City::~City()
{
}

string City::getName()
{
	return name;
}

pair<double, double> City::getCoordinates()
{
	return coordinates;
}

double City::getPopulation()
{
	return population;
}

double City::getAverageTemperature()
{
	return averageTemperature;
}

ostream & operator<<(ostream & os, const City & c)
{
	os << c.name  << " "<< c.coordinates.first << " degrees N " << c.coordinates.second <<  " degrees W " << c.population << " " << c.averageTemperature << " degrees celcius" << endl;
	return os;
}
//  Dublin, 53.3498° N, 6.2603° W, 527,612, 10.0°C 