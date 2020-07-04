#ifndef FIRSTLINKEDLIST_H
#define FIRSTLINKEDLIST_H
#include <iostream>
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

};

#endif


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