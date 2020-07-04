#ifndef DYNSTACK_H
#define DYNSTACK_H
#include <iostream>
using namespace std;
/*
create a
dynamic stack of any data type. The pop function must return a
bool; it should return a false if it was not able to pop an item
off the stack. Otherwise it returns true. The parameter to the pop
function is passed by reference and should be the item on the list
if it was able to pop something.
*/
template <class T>
class DynStack
{
private:
	//structure for stack nodes
	struct StackNode
	{
		T value; //value in the node
		StackNode *next; //pointer to the next node
	};

	StackNode *top;
public:
	DynStack();
	~DynStack();
	void push(T i);
	bool pop(T &i);
	bool isEmpty();
	
};
#endif
template <class T>
DynStack<T>::DynStack()
{top = nullptr;}

template <class T>
DynStack<T>::~DynStack()
{
	StackNode *nodePtr = nullptr, *nextNode = nullptr;
	nodePtr = top; //move nodeptr to the top

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}

}

template <class T>
void DynStack<T>::push(T i)
{
	StackNode *newNode = nullptr; //point to a new node
	//allocate a new node and store num there
	newNode = new StackNode;
	newNode->value = i;

	//if there are no nodes in the list make newNode the first node
	if (isEmpty())
	{
		top = newNode;
		newNode->next = nullptr;
	}
	else //otherwise, insert NewNode before top
	{
		newNode->next = top;
		top = newNode;
	}
		
}
/*
The pop function must return a bool; it should return a false if it was not able to pop an item
off the stack. Otherwise it returns true*/

/*Personal note - unsure of why pop would need to return a bool since main really doesn't nead it i
can see it being used INSIDE pop but not where it would be used in main.....waiting for clarification...*/
template <class T>
bool DynStack<T>::pop(T &i)
{
	bool status = true;
	StackNode *temp = nullptr; //temp pointer

	if (isEmpty())
	{
		cout << "The stack is empty." << endl;
		status = false;
	}
	else //pop value off top of stack
	{
		i = top->value;
		temp = top->next;
		delete top;
		top = temp;
		status = true;
	}
	return status;
}

template <class T>
bool DynStack<T>::isEmpty()
{
	bool status = true;

	if (!top)
		status = true;
	else
		status = false;
	return status;
}