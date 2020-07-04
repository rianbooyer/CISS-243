/*	Week 2 Assignment 1 - Customer Data
Rian Booyer - ccis 243 dea
Version 1.ungodly ammount of versions*/
#include "CustomerData.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;
/*
Create a program that will create two instances of the CustomerData class. It must 
create one instance using the default constructor and then another using the second 
constructor. Once both instances are fully populated with data, call a function 
that will display the customer information.

void displayCustomer(CustomerData c)*/

//global variables 

//predefine functions
void displayCustomer(CustomerData c);
void main()
{
	
	CustomerData one;
	one.setAddress("24 countryside ln");
	one.setCity("montreal");
	one.setCustomerNumber(001);
	one.setFirstName("Rian");
	one.setLastName("Booyer");
	one.setMailingList(false);
	one.setState("AK");
	one.setPhoneNumber("5732555555");
	one.setZipCode("44444");

	CustomerData two(1757885, false, "polo", "Marco", "233 porko lane", "moro", "AK", "65004", "5732568888");
	cout << "Customer #1" << endl;
	cout << "-----------" << endl;
	displayCustomer(one);
	system("pause");
	cout << "Customer #1" << endl;
	cout << "-----------" << endl;
	displayCustomer(two);
	system("pause");
	

}
/*displayCustomer - displays information from CustomerData Object passed to it from main*/
void displayCustomer(CustomerData c)
{
	int fieldWidth = 17;
	cout << setw(fieldWidth) << left << "First Name: " << c.getFirstName() << endl;
	cout << setw(fieldWidth) << "Last Name: " << c.getLastName() << endl;
	cout << setw(fieldWidth) <<  "Address: " << c.getAddress()<< endl;
	cout << setw(fieldWidth) << "City: " << c.getCity() << endl;
	cout << setw(fieldWidth) << "State: " << c.getState() << endl;
	cout << setw(fieldWidth) << "Zip Code: " << c.getZipCode() << endl;
	cout << setw(fieldWidth) << "Phone Number: " << c.getPhoneNumber() << endl;
	cout << setw(fieldWidth) << "Customer Number: " << c.getCustomerNumber() << endl;
	cout << setw(fieldWidth) << "On Mailing List: " << boolalpha << c.getMailingList() << endl;
	
	
}