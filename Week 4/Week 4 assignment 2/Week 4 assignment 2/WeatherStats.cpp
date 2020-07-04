#include "WeatherStats.h"
#include <cstdlib>


WeatherStats::WeatherStats()
{
}


WeatherStats::~WeatherStats()
{
}
ostream &operator << (ostream &strm, WeatherStats &obj)
{
	strm << obj.getAmmountOfRain() << " days of rain, " << obj.getAmmountOfSnow() << " days of snow, " << obj.getNumberOfSunny() << " days of sun. " << endl;
	return strm;
}
