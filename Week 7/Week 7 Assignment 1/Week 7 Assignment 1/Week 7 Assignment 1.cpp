/*	Week 7 Assignment 1 - binary tree template
Rian Booyer - ccis 243 dea
Version 1.ungodly ammount of versions*/
#include <iostream>
#include "BinaryTree.h"
#include <cstdlib>
#include <ctime>
using namespace std;
/*
Create a class (BinaryTree)... The class should provide a function that 
counts the number of nodes in the tree, a function to count the number leaf 
nodes in the tree, and a function that determines the height of the tree. 
The height of a tree is the number of levels the tree has. Write a program 
that shows all these functions work.
*/
//global variables

//predefine functions

void main()
{
	//int temp;
	BinaryTree<int> treeOne;
	srand((unsigned int)time(0));
	
	/* Following can be un-commented to randomly seed 10 numbers into the tree*/
	/*for (int count = 0; count <= 10;count++)
	{
		int temp = (rand() % (120 - 1 + 1) - 0);
		treeOne.insertNode(temp);
	}*/
	
	/*followin inserts 5, 8, 3, 12, and 9*/
	treeOne.insertNode(5);
	treeOne.insertNode(8);
	treeOne.insertNode(3);
	treeOne.insertNode(12);
	treeOne.insertNode(9);

	/*Starts displaying the tree in order*/
	cout << "Displaying in order: " << endl;
	treeOne.displayInOrder();

	/*Tests the search function, the delete function, 
	then reinserts the number I specified*/
	cout << "Testing Search Function: " << endl;
	cout << "Is 12 there: " << boolalpha << treeOne.searchNode(12) << endl;
	cout << "Is 1000 there: " << boolalpha << treeOne.searchNode(1000) << endl << endl;
	cout << "Testing Delete Function: " << endl;
	treeOne.remove(12);
	cout << "Is 12 there: " << boolalpha << treeOne.searchNode(12) << endl;
	cout << "Reinserting 12: " << endl;
	treeOne.insertNode(12);
	cout << "Is 12 there: " << boolalpha << treeOne.searchNode(12) << endl;
	
	cout << "------------------------------------" << endl;
	system("pause");
	system("cls");

	/* displays tree in pre-order */
	cout << "Displaying In Pre Order:" << endl;
	treeOne.displayPreOrder();
	cout << "------------------------------------" << endl;
	system("pause");
	system("cls");

	/*displays tree in post order*/
	cout << "Displaying in Post Order: " << endl;
	treeOne.displayPostOrder();
	cout << "------------------------------------" << endl;
	system("pause");
	system("cls");
	
	/*displays number of nodes, leaves, and levels*/
	cout << "The Number Of Nodes Is: " << treeOne.countNodes() << endl;
	cout << "Number of leaves: " << treeOne.leaves() << endl;
	cout << "Number of levels: " << treeOne.levels() << endl;
	system("pause");
}