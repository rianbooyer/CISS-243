/*	Week 4 Assignment 1 - linked lists
Rian Booyer - ccis 243 dea
Version 1.ungodly ammount of versions*/

#include <iostream>
#include "FirstLinkedList.h"
#include <string>
using namespace std;

/* Have main create two instances 
of the linked list with different data types and show that all of the functions 
work correctly.*/
//global variables

//predefine functions


void main()
{

	FirstLinkedList<double> listOne;
	FirstLinkedList<char> listTwo;

		 // Append some values to the lists.
		listOne.appendNode(2.5);
		listOne.appendNode(7.9);
		listOne.appendNode(12.6);
		listTwo.appendNode('a');
		listTwo.appendNode('b');
		listTwo.appendNode('d');

		// inserts node with value of 10.5
		listOne.insertNode(10.5);
		listOne.insertNode(42);
		listTwo.insertNode('c');
		 // Display the values in the list.
		cout << "List One (doubles) initial values:" << endl;
		 listOne.displayList();

		 cout << string(50, '-') << endl;
		 cout << string(50, '-') << endl;
		 cout << "List Two (char) initial values: " << endl;
		 listTwo.displayList();

		 //deletes value of 42 and c
		 listOne.deleteNode(42);
		 listTwo.deleteNode('c');

		 cout << string(50, '-') << endl;
		 cout << string(50, '-') << endl;
		 cout << "List One with value 42 deleted: " << endl;
		 listOne.displayList();

		 cout << string(50, '-') << endl;
		 cout << string(50, '-') << endl;
		 cout << "List Two with value of c deleted: " << endl;
		 listTwo.displayList();

		 cout << string(50, '-') << endl;
		 cout << string(50, '-') << endl;
		 cout << "Search positions from list one: " << endl;
		 cout <<"Search Position for 2.5 is: " << listOne.searchList(2.5) << endl;
		 cout << "Search Position for 7.9 is: " << listOne.searchList(7.9) << endl;
		 cout << "Search Position for 10.5 is: " << listOne.searchList(10.5) << endl;
		 cout << "Search Position for 12.6 is: " << listOne.searchList(12.6) << endl;
		 cout << "Search position for 42 is: " << listOne.searchList(42) << endl;

		 cout << string(50, '-') << endl;
		 cout << string(50, '-') << endl;
		 cout << "Search positions from list Two: " << endl;
		 cout << "Search Position for a is: " << listTwo.searchList('a') << endl;
		 cout << "Search Position for b is: " << listTwo.searchList('b') << endl;
		 cout << "Search Position for c is: " << listTwo.searchList('c') << endl;
		 cout << "Search Position for d is: " << listTwo.searchList('d') << endl;
		 
		 system("pause");
	
}