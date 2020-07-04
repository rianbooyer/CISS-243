#include "NumDays.h"


//NumDays Constructor
NumDays::NumDays(double h)
{
	hours = h;
	dayConvert();
}

//NumDays destructor
NumDays::~NumDays()
{
}
/*NumDays::dayConvert - converts hours to days using an 8 hour day*/
double NumDays::dayConvert()
{
	double daytemp = hours / 8;
	days = (hours / 8.0);
	return days;
}
/*NumDays::getDays - returns number of days*/
double NumDays::getDays()
{
	return days;
}
/*NumDays::getHours - returns hours*/
double NumDays::getHours()
{
	return hours;
}

//mutators
void NumDays::setDays(double d)
{
	days = d;
	dayConvert();
}
void NumDays::setHours(double h)
{
	hours = h;
	dayConvert();
}

//overload operator functions

/*-the addition operator. This operator will add the hours of the two
objects and return a new instance of the NumDays with its hour’s
data member set to the sum of the other two objects.*/
NumDays NumDays::operator + (const NumDays &right)
{
	NumDays temp(0);
	temp.hours = hours + right.hours;
	temp.dayConvert();
	return temp;

}
/*the subtraction operator will also be overloaded which will 
subtract the two objects and return a new instance of the NumDays class.*/
NumDays NumDays::operator - (const NumDays &right)
{
	NumDays temp(0);
	temp.hours = hours - right.hours;
	temp.dayConvert();
	return temp;
}

/*the prefix and postfix decrement operator. These operators should 
decrement the number of hours stored in the object. It will return 
an instance of the NumDays object.*/

NumDays NumDays::operator -- (int)
{
	NumDays temp(hours);

	hours--;
	temp.dayConvert();
	return temp;
}
NumDays NumDays::operator -- ()
{
	--hours;
	dayConvert();
	return *this;
}
/*-the prefix and postfix increment operator. These operators should 
increment the number of hours stored in the object. It will return 
an instance of the NumDays object.*/

NumDays NumDays::operator ++ ()
{
	++hours;
	dayConvert();
	return *this;
}
NumDays NumDays::operator ++ (int)
{
	NumDays temp(hours);

	hours++;
	dayConvert();
	return temp;
}

