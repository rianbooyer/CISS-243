
#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <iostream>
#include "media.h"
using namespace std;

template <class T>
class Linked_List
{
private:

	struct ListNode
	{
		T value;
		//struct ListNode *next;
		ListNode *next;
	};

	ListNode *head;

public:
	Linked_List();
	~Linked_List();

	void appendNode(T);
	void insertNode(T);
	void deleteNode(T);
	
	void displayList() const;
	int searchList(T) const;
	T returnItem(T);
};


/********* constructor ***********/
template <class T>
Linked_List<T>::Linked_List()
{
	head = nullptr;
}

/********* destructor **********
This needs fixed*/
template <class T>
Linked_List<T>::~Linked_List()
{
	ListNode *nodePtr;
	ListNode *nextNode;
	nodePtr = head;

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		// delete nodePtr;
		nodePtr = nextNode;
	}
}

//appends node
template <class T>
void Linked_List<T>::appendNode(T num)
{
	ListNode *newNode = nullptr;
	ListNode *nodePtr = nullptr;

	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	if (!head)
		head = newNode;
	else
	{
		nodePtr = head;

		while (nodePtr->next)
			nodePtr = nodePtr->next;

		nodePtr->next = newNode;
	}
}

//inserts node
template <class T>
void Linked_List<T>::insertNode(T num)
{
	ListNode *newNode;
	ListNode *nodePtr;
	ListNode *previousNode = nullptr;

	newNode = new ListNode;
	newNode->value = num;

	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		nodePtr = head;
		previousNode = nullptr;

		while (nodePtr != nullptr && nodePtr->value < num)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (previousNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

//deletes node thanks to sourceforge for the help
template <class T>
void Linked_List<T>::deleteNode(T num)
{
	// find node to remove
	ListNode *nodePtr;
	ListNode *prevNode;
	ListNode *current = nullptr;
	if (!head)
		return;
	for (prevNode = 0, nodePtr = head; nodePtr; prevNode = nodePtr, nodePtr = nodePtr->next)
		if (nodePtr->value == num)
			break;

	// deallocate node here
	if (!nodePtr) return; // no match
	if (prevNode) prevNode->next = nodePtr->next; else head = nodePtr->next;
	if (nodePtr == current) current = current->next;
	num = nodePtr->value;
	delete nodePtr;
}

// displays node data
template <class T>
void Linked_List<T>::displayList() const
{
	ListNode *nodePtr;
	nodePtr = head;

	while (nodePtr)
	{
		cout << nodePtr->value;
		nodePtr = nodePtr->next;
	}
}

//searches nodes for value
template <class T>
int Linked_List<T>::searchList(T item) const
{

	int index = 0;

	ListNode *nodePtr;
	nodePtr = head;

	while (nodePtr)
	{
		if (nodePtr->value == item)
			return index;
		else
		{
			nodePtr = nodePtr->next;
			index++;
		}
	}
	index = -1;
	return index;
}

//returns all data in value from obj passed
template <class T>
T Linked_List<T>::returnItem(T item)
{
	ListNode *nodePtr;
	nodePtr = head;

	while (nodePtr)
	{
		if (nodePtr->value == item)
			return nodePtr->value;
		else
		{
			nodePtr = nodePtr->next;
		}
	}
	return item;
}
#endif