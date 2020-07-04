/*	Week 5 Assignment 2 - inventory
Rian Booyer - ccis 243 dea
Version 1.ungodly ammount of versions*/

#include <iostream>
#include <string>
#include <stack>
#include "DynStack.h"
#include "InventoryBin.h"
using namespace std;
/*The program should then create a stack with a data type of 
InventoryBin (stack<InventoryBin>). The program should loop asking the user to 
enter in new items to the inventory stack or to remove an item from the inventory 
stack. The loop should continue until the user indicates they are done. This should 
be menu driven. When adding an item, the program should ask the user for the information 
it needs for the 3 data members of the InventoryBin class and add a new item to the 
stack. When removing an item from the stack, the program should display all of the 
information in the InventoryBin object that was popped off the stack. When the program 
ends, it should pop all of the remaining items off the stack and display the data that 
is in the Inventory items as it pops them off. There should be 3 utility functions that 
main uses.*/

//global variables
const int PUSH_CHOICE = 1,POP_CHOICE = 2,QUIT_CHOICE = 3; //taken from book

//predefine functions
void popItem(DynStack<InventoryBin>* stack);//, InventoryBin ib); // pops the item off the stack and displays it
void pushItem(DynStack<InventoryBin>* stack);//, InventoryBin ib); //pushes the item onto the stack
int menu(int &i);

void main()
{
	
	int choice;
	DynStack<InventoryBin> stackOne;//creates stack using dynStack with inventorybin as type
	InventoryBin binOne;//creates initial inventory object to use to store member variables
	
	do
		{
		 // Get the user's menu choice.
		menu(choice);
		
			 // Perform the user's choice.
		if (choice != QUIT_CHOICE)
		{
			switch (choice)
			{
			case PUSH_CHOICE:
				pushItem(&stackOne);
				cout << "pushed" << endl;
				break;
			case POP_CHOICE:
				popItem(&stackOne);
				cout << "popped" << endl;
			}
		}
		} while (choice != QUIT_CHOICE);
		
		//following runs at the end of the program to pop the rest of the values off the stack untill it is empty
		cout << "Popping objects off stack....Please wait...." << endl;
		do
		{
			popItem(&stackOne);
		} while (stackOne.isEmpty() == false);
		 if (stackOne.isEmpty() == true)
				cout << "Stack is finally empty...Quitting." << endl;
}

void popItem(DynStack<InventoryBin>* stack)
{
	InventoryBin temp;
	if (stack->isEmpty() == true)
		cout << "\nError: " << endl;
	if (stack->isEmpty() == false)
		cout << stack->getNode(0) << endl;
		stack->pop(temp);
		

}
void pushItem(DynStack<InventoryBin>* stack)//, InventoryBin ib)
{
	string md;
	int sn, ln;
	InventoryBin temp;//temporary object to hold values untill they are pushed onto the stack.

	cout << "Please enter Lot Number: ";
	cin >> ln;
	cout << "Please enter Serial Number: ";
	cin >> sn;
	cout << "Please Enter Manufacturing Date: ";
	cin >> md;
	temp.setAll(sn, ln, md);
	stack->push(temp);
	
}
int menu(int &i)
{
	
	cout << "Push Pull Stack" << endl;
	cout << "1 - Push item onto stack." << endl;
	cout << "2 - Pop item off of stack." << endl;
	cout << "3 - Quit. " << endl;
	cout << "Enter your choice: ";
	cin >> i;
	return i;
}