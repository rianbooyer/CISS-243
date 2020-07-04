/*	Week 6 Assignment 1 - power recursion
Rian Booyer - ccis 243 dea
Version 1.ungodly ammount of versions*/
#include <iostream>
#include <iomanip>
using namespace std;
/*
Write a function that uses recursion to raise a number to a power. 
The function should accept two arguments, the number to be raised 
and the exponent. Assume that the exponent is a nonnegative integer. 
Show that this function works correctly for several values.
*/
//global variables

//predefine functions
double fightThePower(double num, int pow);
void main()
{
	cout << setprecision(0) << fixed;
	cout << setw(30) << left << "Raising 2 to the power of 4: " << fightThePower(2, 4) << endl;
	cout << setw(30) << left << "Raising 48 to the power of 3: " << fightThePower(48, 3) << endl;
	cout << setw(30) << left << "Raising 5 to the power of 5: " << fightThePower(5, 5) << endl;
	cout << setw(30) << left << "Raising 1 to the power of 48: " << fightThePower(1, 48) << endl;
	system("pause");
}
double fightThePower(double num, int pow)
{
	if (pow == 0)
		return 1;
	else
		return num * fightThePower(num, pow - 1);
}