#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;

/*
Create a class (BinaryTree) template that will create a binary tree that
can hold values of any data type. The class should provide functions to
insert a node, a function to delete a node, functions to display the tree
In Order, Pre Order and Post Order.  It should also provide a member function
to search the tree for a value. The class should provide a function that
counts the number of nodes in the tree, a function to count the number leaf
nodes in the tree, and a function that determines the height of the tree.
The height of a tree is the number of levels the tree has. Write a program
that shows all these functions work.
*/

/*
many of these came from the book but they work well so i used them mainly to study how they work.
*/


template <class T>
class BinaryTree
{
private:
	struct TreeNode
	{
		T value;           // The value in the node
		TreeNode *left;    // Pointer to left child node
		TreeNode *right;   // Pointer to right child node
	};

	TreeNode *root;       // Pointer to the root node

	int nodeCount;
	// Private member functions
	void insert(TreeNode *&, TreeNode *&);
	void destroySubTree(TreeNode *);
	void deleteNode(T, TreeNode *&);
	void makeDeletion(TreeNode *&);
	void displayInOrder(TreeNode *) const;
	void countNodes(TreeNode *, int);
	void displayPreOrder(TreeNode *) const;
	void displayPostOrder(TreeNode *) const;
	int countLeaves(TreeNode *);
	int countLevels(TreeNode *);

public:
	// Constructor
	BinaryTree()
	{
		root = nullptr;
	}

	// Destructor
	~BinaryTree()
	{
		destroySubTree(root);
	}

	// Binary tree operations
	void insertNode(T);
	bool searchNode(T item);
	bool searchNodeResponse(T item);
	void remove(T);

	void displayInOrder() const
	{displayInOrder(root);}
	int countNodes() 
	{
		nodeCount = -1;//sets nodecount to -1 to adjust for over count.
		countNodes(root,nodeCount);
		return nodeCount/2;//for some reason when i count the number of nodes it comes up double the total possible nodes so i divided by 2
	}
	void displayPreOrder() const
	{displayPreOrder(root);}

	void displayPostOrder() const
	{displayPostOrder(root);}
	
	int leaves() 
	{return countLeaves(root);}

	int levels()
	{return countLevels(root);}
		
};

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************
template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == nullptr)
		nodePtr = newNode;                  // Insert the node.
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode);     // Search the left branch
	else
		insert(nodePtr->right, newNode);    // Search the right branch
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************
template <class T>
void BinaryTree<T>::insertNode(T item)
{
	TreeNode *newNode = nullptr;	// Pointer to a new node.

									// Create a new node and store num in it.
	newNode = new TreeNode;
	newNode->value = item;
	newNode->left = newNode->right = nullptr;

	// Insert the node.
	insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************
template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************
template <class T>
bool BinaryTree<T>::searchNode(T item)
{
	TreeNode *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->value == item)
			return true;
		else if (item < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}
/*
The program
should then allow the user to search for Employee by the Employee ID. If the employee
is found in the tree, its name and ID should be displayed. If not, a message should be
displayed indicating that it was not found.
*/
template <class T>
bool BinaryTree<T>::searchNodeResponse(T item)
{
	TreeNode *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->value == item)
		{
			cout << "Employee Found! " << endl;
			cout << nodePtr->value << endl;
			return 1;
		}
		else if (item < nodePtr->value)
			nodePtr = nodePtr->left;
		else 
			nodePtr = nodePtr->right;
	}
	cout << "Employee Not Found!!!" << endl;
	return 0;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************
template <class T>
void BinaryTree<T>::remove(T item)
{
	deleteNode(item, root);
}

//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************
template <class T>
void BinaryTree<T>::deleteNode(T item, TreeNode *&nodePtr)
{
	if (item < nodePtr->value)
		deleteNode(item, nodePtr->left);
	else if (item > nodePtr->value)
		deleteNode(item, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************
template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)
{
	// Define a temporary pointer to use in reattaching
	// the left subtree.
	TreeNode *tempNodePtr = nullptr;

	if (nodePtr == nullptr)
		cout << "Cannot delete empty node.\n";
	else if (nodePtr->right == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;   // Reattach the left child
		delete tempNodePtr;
	}
	else if (nodePtr->left == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;  // Reattach the right child
		delete tempNodePtr;
	}
	// If the node has two children.
	else
	{
		// Move one node the right.
		tempNodePtr = nodePtr->right;
		// Go to the end left node.
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		// Reattach the left subtree.
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		// Reattach the right subtree.
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
}

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************
template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}

/**********************************************************************
following function displays the total number of nodes in the binary
tree.
***********************************************************************/
template <class T>
void BinaryTree<T>::countNodes(TreeNode *nodePtr, int c) 
{
	if (nodePtr)
		{
			countNodes(nodePtr->left, c + 1);
			countNodes(nodePtr->right, c + 1);
		}
	nodeCount++;
	
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************
template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************
template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}

/**********************************************************
The following function counts the number of leaves on each 
side(s) of the tree
***********************************************************/
template <class T>
int BinaryTree<T>::countLeaves(TreeNode * nodePtr) {
	if (nodePtr == nullptr)
		return 0;
	if (nodePtr->left == nullptr && nodePtr->right == nullptr) {
		return 1;
	}
	else {
		return countLeaves(nodePtr->left) + countLeaves(nodePtr->right);
	}
}
/*******************************************************
the following counts the levels of the tree on each side and
returns the value of the side that is the highest number of 
levels.
*********************************************************/
template <class T>
int BinaryTree<T>::countLevels(TreeNode * nodePtr)
{
	if (!nodePtr)
		return 0;
	int left_height = countLevels(nodePtr->left);
	int right_height = countLevels(nodePtr->right);
	return (left_height > right_height) ? left_height + 1 : right_height + 1;
}
#endif


