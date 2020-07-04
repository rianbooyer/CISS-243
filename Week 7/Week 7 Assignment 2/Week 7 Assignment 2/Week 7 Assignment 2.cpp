/*	Week 7 Assignment 2 - employee's tree
Rian Booyer - ccis 243 dea
Version 1.ungodly ammount of versions*/
#include <iostream>
#include <string>
#include "EmployeeInfo.h"
#include "BinaryTree.h"
using namespace std;
/*
In this program you are going to use the binary tree class you created in Assignment 1 
this week. The program will create an instance of the binary tree 
class with a data type of EmployeeInfo (BinaryTree<EmployeeInfo>). The binary tree 
will be sorted by the Employee ID number found in the EmployeeInfo class. The program 
should then allow the user to search for Employee by the Employee ID. If the employee 
is found in the tree, its name and ID should be displayed. If not, a message should be 
displayed indicating that it was not found. Sample data would be

1021       John Williams
1057       Bill Witherspoon
2487       Jennifer Twain
3769       Sophia Lancaster
1017       Debbie Reece
1275       George McMullen
1899       Ashley Smith
4218       Josh Plemmons
*/
//global variables

//predefine functions
void setInfo(BinaryTree<EmployeeInfo> *,int a, string en);
void searchStuff(BinaryTree<EmployeeInfo> *);
void main()
{	
	char searchYN;
	bool searchTF;
	BinaryTree<EmployeeInfo> treeOne;
	
	setInfo(&treeOne, 1021, "John Williams");
	setInfo(&treeOne, 1057, "Bill WitherSpoon");
	setInfo(&treeOne, 2487, "Jennifer Twain");
	setInfo(&treeOne, 3769, "Sophia Lancaster" );
	setInfo(&treeOne, 1017, "Debbie Reece" );
	setInfo(&treeOne, 1275, "George McMullen" );
	setInfo(&treeOne, 1899, "Ashley Smith" );
	setInfo(&treeOne, 4218, "Josh Plemmons" );
	
	do
	{
		system("cls");
		treeOne.displayInOrder();
		cout << "Do you wish to search Y/N? ";
		cin >> searchYN;
		if (toupper(searchYN) == 'Y')
		{	
			searchTF = true;
			searchStuff(&treeOne);
		}
		if (toupper(searchYN) == 'N')
		{
			searchTF = false;
			cout << "Thanks For Playing" << endl;
		}
	} while (searchTF == true);
	system("pause");

	
}
void setInfo(BinaryTree<EmployeeInfo> * btemp,int a, string en)
{
	EmployeeInfo temp;
	temp.setAll(a, en);
	btemp->insertNode(temp);
}
/*
The program
should then allow the user to search for Employee by the Employee ID. If the employee
is found in the tree, its name and ID should be displayed. If not, a message should be
displayed indicating that it was not found.
*/
void searchStuff(BinaryTree<EmployeeInfo> *btemp)
{
	int eid;
	EmployeeInfo temp;
	cout << "Enter an employee ID to search for: ";
	cin >> eid;
	temp.setEmpID(eid);
	btemp->searchNodeResponse(temp);
	system("pause");
	
}