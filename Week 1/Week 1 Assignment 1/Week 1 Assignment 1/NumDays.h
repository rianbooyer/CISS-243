#ifndef NUMDAYS_H
#define NUMDAYS_H
#pragma once
/*Design a class called NumDays. The class’s 
purpose is to store a value that will convert the number of 
worked hours to a number of days. For example, 8 hours would 
be converted to 1 day, 12 hours would be converted to 1.5 days 
and 18 hours converted to 2.25 days. The class must have a 
constructor that accepts a number of hours. There must also 
be member function to set and get the hours and days. The 
class should have 2 data members, hours and days.*/
class NumDays
{
private: 
	double hours;
	double days;

public:
	NumDays(double h);
	~NumDays();
	double dayConvert();
	double getDays();
	double getHours();
	//mutators
	void setDays(double d);
	void setHours(double h);
	//overload operators
	
	NumDays operator + (const NumDays &right);//addition overload
	NumDays operator - (const NumDays &right);//subtraction overload
	NumDays operator ++ ();//prefix ++
	NumDays operator -- ();//prefix --
	NumDays operator ++ (int); // postfix ++
	NumDays operator -- (int); // postfix ++

};

#endif