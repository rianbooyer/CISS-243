/*	Week 1 Assignment 2 - carpet calculator
Rian Booyer - ccis 243 dea
Version 1.ungodly ammount of versions*/
#include <iostream>
//#include "FeetInches.h"
#include "RoomDimension.h"
using namespace std;
/*
The main for this program will create an instance of RoomCarpet and 
ask the user for the dimensions of the room and the price per square 
foot for the carpet. The application should then display the total 
cost of the carpet. It should allow the user to continue doing more 
calculations until the user indicates they are done.
*/
//global variables


//predefine functions

void main()
{
	//objects
	RoomDimension one;
	FeetInches width;
	FeetInches length;
	FeetInches Total;
	
	/*
	I stuck everything in main instead of making it modular. from what I could tell the
	program is supposed to use very simple portions of the FeetInches class in that it
	didn't seem like i needed to ask about inches since in my experience (lowes, home depot,
	menards, etc) don't sell carpet, vynyl, etc. in inches just one ft x length of roll (ex lenght
	of role is 15 ft so they sell it as 1 x 15 or 15 sq foot) so if you want a rectangle carpet that
	is aproximately 3 ft x 4 ft you would have to purchase a 3 ft x 15 ft piece of carpet from their
	stock and pay for the overage. 
	*/
	//variables
	int roomWidth, roomLength, costSqFt;
	char loopAnswer;
	bool repeatLoop = true;
	
	//begin loop
	do
	{
		system("cls");
		cout << "Please enter the dimentions of the room" << endl;
		cout << "Room Width: ";
		cin >> roomWidth;
		width.setFeet(roomWidth);
		cout << "Room length: ";
		cin >> roomLength;
		length.setFeet(roomLength);
		Total.setFeet(width.getFeet()*length.getFeet());
		cout << "Room square feet is: " << Total.getFeet() << endl;
		cout << "What is the cost per square foot: $";
		cin >> costSqFt;
		one.setCost(costSqFt);
		one.totalCost(Total);
		cout << "Toal cost is: $ " << one.getTotalCost() << endl;
		cout << "Would you like to do another calculation (y/n)? ";
		cin >> loopAnswer;
		if (toupper(loopAnswer) == 'Y')
			repeatLoop = true;
		if (toupper(loopAnswer) == 'N')
			repeatLoop = false;

	} while (repeatLoop == true);
	system("pause");// last teacher required this i use ctr-f5 to run so you have to hit any key anyway.
}