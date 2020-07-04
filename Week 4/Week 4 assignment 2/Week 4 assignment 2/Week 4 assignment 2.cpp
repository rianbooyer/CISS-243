/*	Week 4 Assignment 2 -
Rian Booyer - ccis 243 dea
Version 1.ungodly ammount of versions*/

#include <iostream>
#include <string>
#include "FirstLinkedList.h"
#include "WeatherStats.h"
using namespace std;
/* Main will create an instance of the linked list with a data type of the WeatherStats (LinkedList<WeatherStats>). 
The program should ask the user for how many months they wish to enter weather statistics for. The program 
will then prompt the user for that information (rain, snow and sunny days). The data needs to be stored in 
the WeatherStats class and it should be appended to the linked list. Main must then call a function that 
displays the data in the list; this function will call the display function in the linked list. Main will 
call a function that determines the month with the largest and smallest amount of rain, snow and sunny days. 
This function should not be part of the linked list. It should appear in the same file as main. A function will 
need to be added to the linked list that provides an item from the list. The function in the linked list will 
return the object stored in the list. The function in main will need to request each item in the list one at a 
time. Another solution is to create a derived class of the linked list, which does all of the work for finding 
the largest and smallest.*/
//global variables

//predefine functions
void displayData(FirstLinkedList<WeatherStats>& l,int n);

void main()
{
	//variables
	double daysRain, daysSnow, daysSunny;
	int monthsToEnter=0;
	const int numMonths=12;

	FirstLinkedList<WeatherStats> listOne;//creates the linked list
	WeatherStats weatherOne[numMonths];//creates a weatherstats array to hold the data for const numMonths (set at 12)
	
	//prompts for number of months to enter data
	cout << "How many months do you want to enter data for? ";
	cin >> monthsToEnter;

	//following steps through number of months selected asks for the data and stores it into the single node
	for (int count = 0;count < monthsToEnter; count++)
	{
		
		cout << string(50, '-')<< endl;
		cout << "Month " << count + 1 << ":" << endl;
		cout << "How many days did it:" << endl;
		cout << "Rain: ";
		cin >> daysRain;
		cout << "Snow: ";
		cin >> daysSnow;
		cout << "Sunny: ";
		cin >> daysSunny;

		//after data gathered data is stored into the weatherOne[count] variables.
		weatherOne[count].setAmmountOfRain(daysRain);//rain stored in weatherOne[count] ammountOfRain variable
		weatherOne[count].setAmmountOfSnow(daysSnow);// snow stored "
		weatherOne[count].setNumberOfSunny(daysSunny);//sun stored "/		
		listOne.appendNode(weatherOne[count]); // appends weather array object into the linked list
	}
		
	displayData(listOne,monthsToEnter-1); //displays output
			
	system("pause");
	
	
}
void displayData(FirstLinkedList<WeatherStats>& l,int n)
{
	double rainHighest = 0, rainLowest = 999, snowHighest = 0, snowLowest = 999, sunHighest = 0, sunLowest = 999;
	int rainLowMonth, rainHighMonth, snowLowMonth, snowHighMonth, sunLowMonth, sunHighMonth;
	double rainTemp, snowTemp, sunTemp;
	int count = 0;
	
	//get lowest and highest ammount of rain and store in variables
	for (int count = 0; count <= n; count++)
	{
		
		rainTemp = l.getNode(count).getAmmountOfRain();

		if (rainTemp > rainHighest)
		{
			rainHighest = rainTemp;
			rainHighMonth = count + 1;
		}
		if (rainTemp < rainLowest)
		{
			rainLowest = rainTemp;
			rainLowMonth = count + 1;
		}
	}

	//gets highest and lowest snow total
	for (int count = 0; count <= n; count++)
	{
		
		snowTemp = l.getNode(count).getAmmountOfSnow();

		if (snowTemp > snowHighest)
		{
			snowHighest = snowTemp;
			snowHighMonth = count + 1;
		}
		if (snowTemp < snowLowest)
		{
			snowLowest = snowTemp;
			snowLowMonth = count + 1;
		}
		
	}

	//gets highest and lowest snow total
	for (int count = 0; count <= n; count++)
	{
	
		sunTemp = l.getNode(count).getNumberOfSunny();
		if (sunTemp > sunHighest)
		{
			sunHighest = sunTemp;
			sunHighMonth = count + 1;
		}
		if (sunTemp < sunLowest)
		{
			sunLowest = sunTemp;
			sunLowMonth = count + 1;
		}
		
	}
	//begin output
	cout << "The month with the highest rain total was month: " << rainHighMonth << " with " << rainHighest << " inches of rain." << endl;
	cout << "The month with the lowest rain total was month: " << rainLowMonth << " with " << rainLowest << " inches of rain." << endl;
	
	cout << endl;
	cout << "The month with the highest snow total was month: " << snowHighMonth << " with " << snowHighest << " inches of snow." << endl;
	cout << "The month with the lowest snow total was month: " << snowLowMonth << " with " << snowLowest << " inches of snow." << endl;
	
	cout << endl;
	cout << "The month with the highest sun total was month: " << sunHighMonth << " with " << sunHighest << " inches of sun." << endl;
	cout << "The month with the lowest sun total was month: " << sunLowMonth << " with " << sunLowest << " inches of sun." << endl;
	
	
}
