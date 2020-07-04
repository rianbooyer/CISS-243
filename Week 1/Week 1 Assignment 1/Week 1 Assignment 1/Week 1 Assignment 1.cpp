/*	Week 1 Assignment 1 - Number Of Days
Rian Booyer - ccis 243 dea
Version 1.ungodly ammount of versions*/
#include <iostream>
#include "NumDays.h"
using namespace std;
/*
-Note that when the number of hours changes, the number of days should 
always be updated. The user of this class should be able to use the 
object in a statement like C = A + B; where A, B and C are instances 
of the NumDays class. Main must show that the class and all the 
operators work correctly.
*/

//global variables

//predefine functions

void main()
{
	NumDays one(18);
	NumDays two(16);
	NumDays three(0);
	

	cout << "Displaying Contents" << endl;
	cout << "-------------------" << endl;
	cout << "One hours " << one.getHours() << "| One Days " << one.getDays() << endl;
	cout << "Two hours " << two.getHours() << "| Two Days " << two.getDays() << endl;
	cout << "Three hours " << three.getHours() << "| Three Days " << three.getDays() << endl;
	cout << "-------------------" << endl;
	
	cout << "Adding One and Two and storing into Three" << endl;
	three = one + two;
	cout << "Three hours " << three.getHours() << "| Three Days " << three.getDays() << endl;
	cout << "-------------------" << endl;
	cout << "Reseting objects;" << endl;

	// the following is really not very clean but it works just for a demonstration.
	one.setDays(0);
	one.setHours(18);
	two.setDays(0);
	two.setHours(16);
	three.setDays(0);
	three.setHours(0);
	system("pause");
	cout << "subtracting Two from One and storing into Three" << endl;
	three = one - two;
	cout << "Three hours " << three.getHours() << "| Three Days " << three.getDays() << endl;
	cout << "-------------------" << endl;
	

	cout << "Three Postfix Increment" << endl;
	three++;
	cout << "Three hours " << three.getHours() << "| Three Days " << three.getDays() << endl;
	cout << "-------------------" << endl;
	
	cout << "Three prefix Increment" << endl;
	++three;
	cout << "++Three " << three.getHours() << "|" << three.getDays() << endl;
	cout << "-------------------" << endl;
	
	cout << "Three Postfix decrement" << endl;
	three--;
	cout << "Three-- " << three.getHours() << "|" << three.getDays() << endl;
	cout << "-------------------" << endl;
	cout << "Three Prefix decrement" << endl;
	--three;
	cout << "--Three " << three.getHours() << "|" << three.getDays() << endl;
	

}