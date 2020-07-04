#ifndef FIRSTLINKEDLIST_H
#define FIRSTLINKEDLIST_H
#include <iostream>
//#include "WeatherStats.h"

using namespace std;

/*Design your own linked list class that works as a template class. It 
should provide member functions for appending, inserting and deleting 
nodes. The destructor should destroy the list. The class should also provide 
a member function that will display the contents of the list to the screen. 
The class should also provide a member function to search the list for an 
element in the list. The search should return the index (location) of the item 
in the list. So if it is the first element in the list then it should return 0. 
If the item is not in the list, it should return -1.*/
template <class T>
class FirstLinkedList
{

//declare a structure for the list

struct ListNode
	{
		//insert variables
		T value;
		struct ListNode *next;
	};
	ListNode *head;	
public:


	FirstLinkedList()
	{
		head = nullptr;
	};
	~FirstLinkedList();
	void appendNode(T n);
	void insertNode(T n);
	void deleteNode(T n);
	void displayList() const;
	int searchList(T n);
	//void getLowestHighest(int n);
	T FirstLinkedList<T>::getNode(int n);
	
};

#endif

//template <class T>
//attempt to make a dirived list i left it in so if you could offer a suggestion that would be great.
/* This was a failed attempt to create a derived class. For some reason i couldn't figure out the 
inheritance of the struct linkedlist from the base class.

template <class T>
class LinkedLargeSmall : protected FirstLinkedList<T>
{
public:
	
	LinkedLargeSmall()
	{}
	~LinkedLargeSmall()
	{
		delete this;
	}
	//void getLowestHighest(int n);
	
	void getLowestHighest(int n)
	{
		
		ListNode *nodePtr;
		//ListNode *nodePtr;
		nodePtr = head;
		double rainHighest = 0, rainLowest = 999, snowHighest = 0, snowLowest = 999, sunHighest = 0, sunLowest = 999;
		int rainLowMonth, rainHighMonth, snowLowMonth, snowHighMonth, sunLowMonth, sunHighMonth;
		double rainTemp, snowTemp, sunTemp;
		int count = 0;
		//gets highest and lowest rain total
		for (int count = 0; count <= n; count++)
		{
			if (nodePtr == nullptr)
				break;
			
			rainTemp = nodePtr->value.getAmmountOfRain();

			if (rainTemp > rainHighest)
			{
				rainHighest = rainTemp;
				rainHighMonth = count;
			}
			if (rainTemp < rainLowest)
			{
				rainLowest = rainTemp;
				rainLowMonth = count;
			}
			nodePtr = nodePtr->next;
		}

		//gets highest and lowest snow total
		nodePtr = head; //sends back to the first node for next test
		for (int count = 0; count <= n; count++)
		{
			if (nodePtr == nullptr)
				break;
			snowTemp = nodePtr->value.getAmmountOfSnow();

			if (snowTemp > snowHighest)
			{
				snowHighest = snowTemp;
				snowHighMonth = count;
			}
			if (snowTemp < snowLowest)
			{
				snowLowest = snowTemp;
				snowLowMonth = count;
			}
			nodePtr = nodePtr->next;
		}

		//gets highest and lowest snow total
		nodePtr = head; //sends back to the first node for next test
		for (int count = 0; count <= n; count++)
		{
			if (nodePtr == nullptr)
				break;
			sunTemp = nodePtr->value.getNumberOfSunny();
			if (sunTemp > sunHighest)
			{
				sunHighest = sunTemp;
				sunHighMonth = count;
			}
			if (sunTemp < sunLowest)
			{
				sunLowest = sunTemp;
				sunLowMonth = count;
			}
			nodePtr = nodePtr->next;
		}
		cout << "Highest Rain Was: " << rainHighest << " Month: " << rainHighMonth << endl;
		cout << "Lowest Rain Was: " << rainLowest << " Month: " << rainLowMonth << endl;
		cout << endl;
		cout << "Highest Snow Was: " << snowHighest << " Month: " << snowHighMonth << endl;
		cout << "Lowest Snow Was: " << snowLowest << " Month: " << snowLowMonth << endl;
		cout << endl;
		cout << "Highest Sun Was: " << sunHighest << " Month: " << sunHighMonth << endl;
		cout << "Lowest Sun Was: " << sunLowest << " Month: " << sunLowMonth << endl;
	}
};*/
#pragma region
template <class T>
FirstLinkedList<T>::~FirstLinkedList()
{
	ListNode *nodePtr;
	ListNode *nextNode;
	
	// goto head
	nodePtr = head;

	//while not at end of list
	while (nodePtr != nullptr)
	{
		//save a pointer to the next node
		nextNode = nodePtr->next;
		//delte current node
		delete nodePtr;
		// goto the next node
		nodePtr = nextNode;
	}
}
template <class T>
void FirstLinkedList<T>::appendNode(T n)
{
	ListNode *newNode;
	ListNode *nodePtr;

	//allocate a new node (from book)
	newNode = new ListNode;
	newNode->value = n; // need to change this once member variable name is decared
	newNode->next = nullptr; // important because the last node will need to be a null pointer
	
							 //checks to see if there is a node that exists if not makes newNode the first one
	if (!head)
		head = newNode;
	else //otherwise, insert newNode at end.
	{
		nodePtr = head;

		//find last node
		while (nodePtr->next)
			nodePtr = nodePtr->next;
		//insert newNode as the last node
		nodePtr->next = newNode;
	
	}
}
template <class T>
void FirstLinkedList<T>::insertNode(T n)
{
	ListNode *newNode;
	ListNode *nodePtr;
	ListNode *previousNode = nullptr;

	newNode = new ListNode;
	newNode->value = n;

	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		nodePtr = head;
		previousNode = nullptr;
		//skip nodes whose value is less than n
		while (nodePtr != nullptr && nodePtr->value < n)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		//if node is to be first
		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else // otherwise insert after the previous node.
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}
template <class T>
void FirstLinkedList<T>::deleteNode(T n)
{
	ListNode *nodePtr;
	ListNode *previousNode;

	//checks to see if the list is empty
	if (!head)
		return;

	//determine if the first node is the one
	if (head->value == n)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		//initialize nodePtr to head
		nodePtr = head;

		//skip all nodes whose value member is not equal to num.
		while (nodePtr != nullptr && nodePtr->value != n)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		//if nodePtr is not at the end, link the prev node to the node after nodePtr, then delete nodePtr
		if (nodePtr)
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}
template <class T>
void FirstLinkedList<T>::displayList() const
{
	ListNode *nodePtr; // moves through the list

					   //goto head
	nodePtr = head;
	
	//while nodePtr points to a node, traverse the list
	while (nodePtr)
	{
		//displays value in node
		cout << nodePtr->value << endl;

		//move to the next node
		nodePtr = nodePtr->next;
	}

}
template <class T>
int FirstLinkedList<T>::searchList(T n)
{
	int temp = 0;
	int listPos=-1;//this is the easiest way for me to return that value wasn't found
	ListNode *nodePtr;
	nodePtr = head;
	
	while (nodePtr != nullptr)
	{
		temp++;
		//move to the next node
		
		nodePtr = nodePtr->next;
	}
	
	// returns nodePtr to head again after finding how many nodes there are
	nodePtr = head;

	//starts loop to find what position (starting at 0) the value is at.
	for (int count = 0; count <= temp; count++)
	{
			// if nodePtr is a nullptr then it breaks the loop and leaves count as is.
		if (nodePtr == nullptr)
			break;
		
			if (nodePtr->value == n)//assigns count value to listPos
					listPos = count;
			
			nodePtr = nodePtr->next;//moves to next node
	}
	return listPos;
}
#pragma endregion

template <class T>
T FirstLinkedList<T>::getNode(int n)
{	
	ListNode *nodePtr;
	nodePtr = head;
	
	for (int count = 0; count < n; count++)
	{
		if (nodePtr == nullptr)
			nodePtr = head;
		
		nodePtr = nodePtr->next;
		
	}

	
	return nodePtr->value;
}