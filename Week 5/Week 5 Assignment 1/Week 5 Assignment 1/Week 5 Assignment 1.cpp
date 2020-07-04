/*	Week 5 Assignment 1 -dynamic stack class template
Rian Booyer - ccis 243 dea
Version 1.ungodly ammount of versions*/

#include <iostream>
#include <string>
#include "DynStack.h"
using namespace std;
/*Write your own version of a class template that will create a 
dynamic stack of any data type. Create a driver program (main) that 
shows that the stack works for at least two different data types.*/

// global variables

//forward function declaration

void main()
{
	int intCatch;
	char charCatch;
	DynStack<int> intStack;
	DynStack<char> charStack;

	//push some int's onto the stack
	cout << "Pushing 3" << endl;
	intStack.push(3);
	cout << "Pushing 2" << endl;
	intStack.push(2);
	cout << "Pushing 1" << endl;
	intStack.push(1);
	
	system("pause");
	cout << string(50, '-') << endl;
	cout << "Popping int's..." << endl;
	intStack.pop(intCatch);
	cout << intCatch << endl;
	intStack.pop(intCatch);
	cout << intCatch << endl;
	intStack.pop(intCatch);
	cout << intCatch << endl;
	cout << "Trying pop again on the int's" << endl;
	intStack.pop(intCatch);
	system("pause");

	cout << "Pushing c" << endl;
	charStack.push('c');
	cout << "Pushing b" << endl;
	charStack.push('b');
	cout << "Pushing a" << endl;
	charStack.push('a');
	
	system("pause");
	cout << string(50, '-') << endl;
	cout << "Popping char's..." << endl;
	charStack.pop(charCatch);
	cout << charCatch << endl;
	charStack.pop(charCatch);
	cout << charCatch << endl;
	charStack.pop(charCatch);
	cout << charCatch << endl;
	cout << "Trying pop again on the char's" << endl;
	charStack.pop(charCatch);
	system("pause");
}