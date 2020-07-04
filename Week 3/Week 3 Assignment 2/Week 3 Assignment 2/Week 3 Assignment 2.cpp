/*	Week 3 Assignment 2 - 
Rian Booyer - ccis 243 dea
Version 1.ungodly ammount of versions*/
#include <iostream>
#include "MinMax.h"
using namespace std;

/*Create a class called MinMax which will be a template class. 
The class will have two data members which have a data type of 
the template. The class will provide two member functions called 
minimum and maximum. The function minimum will determine which 
of the two data members is the lower of the two and return that 
value. The function maximum will determine which of the two data 
members is the larger of the two and return that value. Create a 
program that creates 3 instances of this class for the data types 
int, double and char.*/
//global variables


//predefine functions

void main()
{
	
	MinMax<int> intInstance(10, 20);
	MinMax<double> doubleInstance(10.155, 9.95);
	MinMax<char> charInstance('c', 'b');

	//following shows that the class is working
	cout << "Int Instance Maximum: " << intInstance.maximum() << " Int Instance Minimum: " << intInstance.minimum() << endl;
	cout << "Double Instance Maximum: " << doubleInstance.maximum() << " Double Instance Minimum: " << doubleInstance.minimum() << endl;
	cout << "Char Instance Maximum: " << charInstance.maximum() << " Char Instance Minimum: " << charInstance.minimum() << endl;
}