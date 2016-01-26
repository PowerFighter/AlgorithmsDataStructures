#pragma once
#include "linkedList.h"

template<class datType>
List<datType>::List()
{
	root = new lNode<datType>();
	root->data = -1;
	root->nextlNode = NULL;
	_size = 0;

	tail = NULL;
}

// Appends a node to the tail and returns the pointer to the appended node
template<class datType>
lNode<datType>* List<datType>::appendToTailAndReturn(int data)
{
	lNode<datType> *newlNode;
	newlNode = new lNode<datType>();
	newlNode->data = data;
	newlNode->nextlNode = NULL;

	//If the only node is the head node
	if (root->nextlNode == NULL)
	{
		//Make the root point to the new node
		root->nextlNode = newlNode;
	}
	else
	{
		//Initialize the iterator
		lNode<datType> *iterator;
		iterator = root;

		//Iterate through the list
		while (iterator->nextlNode != NULL)
		{
			iterator = iterator->nextlNode;

		}

		iterator->nextlNode = newlNode;
	}

	_size++;
	tail = newlNode;

	return newlNode;

}

//Deletes a node from the head and returns the value held by that node
template<class datType>
datType List<datType>::deleteFromHeadAndReturn()
{
	datType retVal = root->data;
	if (root->nextlNode == NULL)
	{
		cout << "No lNodes to delete from head" << endl;
		return retVal;
	}
	//The node after the first
	lNode<datType> *temp = root->nextlNode;
	retVal = temp->data;
	root->nextlNode = temp->nextlNode;
	delete temp;
	_size--;

	if (_size == 0) {
		cout << "Nullifying the tail" << endl;
		tail = NULL;
	}

	return retVal;
}

//Remove a node from the position
template<class datType>
void List<datType>::deleteFromPosition(int position)
{

	if (position <= 0)
	{
		cout << "Error invalid position : " << position << endl;
		return;
	}

	//Valid Position so iterator till position - 1 and add the node there

	lNode<datType> *iterator;
	iterator = root;

	//Current Position
	int currentPosition = 0;

	//cout<<"Position - 1 " << position-1;
	while (iterator->nextlNode != NULL && (position - 1) != currentPosition)
	{
		currentPosition++;
		iterator = iterator->nextlNode;

	}

	if (iterator->nextlNode == NULL)
	{
		cout << "Invalid Position " << endl;
		return;
	}

	lNode<datType> *temp = (iterator->nextlNode)->nextlNode;
	delete iterator->nextlNode;
	iterator->nextlNode = temp;

	_size--;

	if (temp == NULL) {

		if (_size > 0) {
			cout << "Deleting the last node" << endl;
			tail = iterator;
		}
		else {
			cout << "Nullifying the tail" << endl;
			tail = NULL;
		}
	}
}

//Delete node from head
template<class datType>
void List<datType>::deleteFromHead()
{
	if (root->nextlNode == NULL)
	{
		cout << "No lNodes to delete from head" << endl;
		return;
	}
	//The node after the first
	lNode<datType> *temp = root->nextlNode;
	root->nextlNode = temp->nextlNode;
	delete temp;
	_size--;

	if (_size == 0) {
		cout << "Nullifying the tail" << endl;
		tail = NULL;
	}
}

//Delete node from tail
template<class datType>
void List<datType>::deleteFromTail()
{
	//Iterator
	lNode<datType> *iterator;
	iterator = root;

	if (iterator->nextlNode == NULL)
	{
		cout << "No more lNodes to delete " << endl;
		return;
	}
	//tracking the previous node
	lNode<datType> *previouslNode = NULL;

	while (iterator->nextlNode != NULL)
	{
		previouslNode = iterator;
		iterator = iterator->nextlNode;
	}

	delete previouslNode->nextlNode;
	previouslNode->nextlNode = NULL;

	_size--;

	if (_size > 0)
	{
		//Reassign the tail to previous node since thats the end of the list now
		tail = previouslNode;
	}
	else 
	{
		cout << "Nullifying the tail" << endl;
		tail = NULL;
	}
}

//Append a new lNode to the given position within the current size i.e position should be always <= size
template<class datType>
void List<datType>::appendToPosition(int data, int position)
{
	lNode<datType> *newlNode;
	newlNode = new lNode();
 	newlNode->data = data;
	newlNode->nextlNode = NULL;

	if (position <= 0)
	{
		cout << "Error invalid position : " << position << endl;
		return;
	}

	//Valid Position so iterator till position - 1 and add the node there

	lNode<datType> *iterator;
	iterator = root;

	//Current Position
	int currentPosition = 0;

	//cout<<"Position - 1 " << position-1;
	while (iterator->nextlNode != NULL && (position - 1) != currentPosition)
	{
		currentPosition++;
		iterator = iterator->nextlNode;

	}

	if (iterator->nextlNode == NULL)
	{
		cout << "Invalid Position " << endl;
		return;
	}
	newlNode->nextlNode = iterator->nextlNode;
	iterator->nextlNode = newlNode;

	_size++;
}

//Append a new lNode to the head
template<class datType>
void List<datType>::appendToHead(int data)
{
	lNode<datType> *newlNode;
	newlNode = new lNode();
	newlNode->data = data;
	newlNode->nextlNode = root->nextlNode;
	
	//If we are appending to an empty list
	if (_size == 0) {
		cout << "Assigning A new tail" << endl;
		tail = newlNode;
	}
	//make the root point to this node
	root->nextlNode = newlNode;

	_size++;

}

//Append a new lNode to the Tail
template<class datType>
void List<datType>::appendToTail(int data)
{
	lNode<datType> *newlNode;
	newlNode = new lNode();
	newlNode->data = data;
	newlNode->nextlNode = NULL;

	//If the only node is the head node
	if (root->nextlNode == NULL)
	{
		//Make the root point to the new node
		root->nextlNode = newlNode;
	}
	else
	{
		//Initialize the iterator
		lNode *iterator;
		iterator = root;

		//Iterate through the list
		while (iterator->nextlNode != NULL)
		{
			iterator = iterator->nextlNode;

		}

		iterator->nextlNode = newlNode;
	}

	//Assign tail to the end of the list
	tail = newlNode;
	_size++;

}

//Iterate through the list and print all the values
template<class datType>
void List<datType>::iterateAndPrint()
{
	lNode<datType> *iterator;
	iterator = root;

	if (iterator->nextlNode == NULL)
	{
		cout << "No lNodes Present " << endl;
		return;
	}
	cout << "Values (Total : "<<_size <<") : ";
	while (iterator != NULL)
	{
		cout << "\t" << iterator->data;
		iterator = iterator->nextlNode;

	}
	cout << endl;

}

//Get the actual size of the list
template<class datType>
int List<datType>::getSize()
{
	return _size;
}

//Get pointer to the end of the list
template<class datType>
lNode<datType>* List<datType>::GetTail()
{
	return tail;
}

//Clear the whole list until we reach the root
template<class datType>
void List<datType>::clear()
{
	while (root->nextlNode != NULL) 
	{
		deleteFromTail();
	}
}