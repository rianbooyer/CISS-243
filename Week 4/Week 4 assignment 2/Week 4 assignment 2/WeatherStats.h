#ifndef WEATHERSTATS_H
#define WEATHERSTATS_H
#include <iostream>
using namespace std;
class WeatherStats;
ostream &operator<< (ostream &, WeatherStats &);
/*First you will create a class that holds information about the weather for a given month which should 
be called WeatherStats. It should have data members that are doubles to hold the amount of rain for the 
month and the amount of snow for the month. It will also have a data member that holds the number of sunny 
days during the month. It should provide accessors and mutators for the private data members.*/
class WeatherStats
{
private:
	double ammountOfRain, ammountOfSnow, numberOfSunny;
public:
	WeatherStats();
	~WeatherStats();
	double getAmmountOfRain()
	{return ammountOfRain;}
	double getAmmountOfSnow()
	{return ammountOfSnow;}
	double getNumberOfSunny()
	{return numberOfSunny;}
	
	void setAmmountOfRain(double n)
	{ammountOfRain = n;}
	void setAmmountOfSnow(double n)
	{ammountOfSnow = n;}
	void setNumberOfSunny(double n)
	{numberOfSunny = n;}
friend ostream &operator << (ostream &, WeatherStats &);
};

#endif
