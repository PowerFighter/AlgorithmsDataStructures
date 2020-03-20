#pragma once
#include "linkedList.h"
#include "assert.h"

template<class datType>
List<datType>::List()
{
	root = NULL;
	_size = 0;
	tail = NULL;
}

// Appends a node to the tail and returns the pointer to the appended node
template<class datType>
lNode<datType>* List<datType>::appendToTailAndReturn(datType data)
{
	lNode<datType> *newlNode;
	newlNode = new lNode<datType>();
	newlNode->data = data;
	newlNode->nextlNode = NULL;

	//If the only node is the head node
	if (root == NULL)
	{
		//Make the root point to the new node
		root = newlNode;
	}
	else
	{
		//Initialize the iterator
		lNode<datType> *iterator;
		iterator = root;

		//Iterate through the list
		while (iterator->nextlNode != NULL)
			iterator = iterator->nextlNode;

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
	if (root == NULL)
	{
		cout << "No lNodes to delete from head" << endl;
		return -1;
	}
	
	datType retVal = root->data;

	//The node after the first
	lNode<datType>* temp = root;
	root = temp->nextlNode;

	_size--;

	if (_size == 0) 
	{
		root = NULL;
		tail = NULL;
	}

	delete temp;
	return retVal;
}

//Remove a node from the position
template<class datType>
void List<datType>::deleteFromPosition(int position)
{
	if (position < 0 || position >= _size)
	{
		cout << "Error invalid position : " << position << endl;
		return;
	}
	
	cout << "Deleting From position " << position << endl;

	if (position == 0)
	{
		deleteFromHead();
		return;
	}

	//Valid Position so iterator till position - 1 and add the node there
	lNode<datType> *iterator;
	iterator = root;

	//Current Position
	int currentPosition = 0;

	//cout<<"Position - 1 " << position-1;
	while (iterator->nextlNode != NULL && (currentPosition + 1) != position)
	{
		currentPosition++;
		iterator = iterator->nextlNode;
	}

	if (iterator == tail)
	{
		cout << "Deleting from tail " << endl;
		deleteFromTail();
		return;
	}

	//here nextlNode cannot be null
	assert(iterator->nextlNode != NULL);

	lNode<datType> *toDelete = iterator->nextlNode;
	iterator->nextlNode = toDelete->nextlNode;

	_size--;

	if (_size == 0)
	{
		tail = NULL;
		root = NULL;
	}

	delete toDelete;
}

//Delete node from head
template<class datType>
void List<datType>::deleteFromHead()
{
	if (root == NULL)
	{
		cout << "No lNodes to delete from head" << endl;
		return;
	}

	cout << " Deleting from Head " << endl;

	//The node after the first
	lNode<datType> *temp = root;
	root = temp->nextlNode;
	
	_size--;

	if (_size == 0) {
		//cout << "Nullifying the tail" << endl;
		tail = NULL;
		root = NULL;
	}

	delete temp;
}

//Delete node from tail
template<class datType>
void List<datType>::deleteFromTail()
{
	if (tail == NULL)
	{
		cout << "No more lNodes to delete " << endl;
		return;
	}

	cout << "Deleting From Tail " << endl;

	//Iterator
	lNode<datType> *iterator;
	iterator = root;

	//tracking the previous node
	lNode<datType> *previouslNode = NULL;

	while (iterator->nextlNode != NULL)
	{
		previouslNode = iterator;
		iterator = iterator->nextlNode;
	}

	if (iterator == root)
	{
		deleteFromHead();
		return;
	}

	previouslNode->nextlNode = NULL;
	_size--;

	tail = previouslNode;

	if (_size == 0)
	{
		tail = NULL;
		root = NULL;
	}

	delete iterator;
}

//Append a new lNode to the given position within the current size i.e position should be always < size
template<class datType>
void List<datType>::appendToPosition(datType data, int position)
{
	if (position < 0)
	{
		cout << "Error invalid position : " << position << endl;
		return;
	}
	
	if (position >= _size)
	{
		cout << "Position greater than the size of the linked list" << endl;
		return;
	}

	lNode<datType> *newlNode;
	newlNode = new lNode<datType>();
	newlNode->data = data;
	newlNode->nextlNode = NULL;

	cout << " Appending " << data << " To position " << position << endl;

	//Append to head if the position is zero
	if (position == 0)
	{
		appendToHead(data);
		return;
	}

	//Valid Position so iterator till position - 1 and add the node there
	lNode<datType> *iterator;
	iterator = root;

	//Current Position
	int currentPosition = 0;

	//cout<<"Position - 1 " << position-1;
	while (iterator->nextlNode != NULL && currentPosition != position)
	{
		currentPosition++;
		iterator = iterator->nextlNode;

	}

	newlNode->nextlNode = iterator->nextlNode;
	iterator->nextlNode = newlNode;

	_size++;
}

//Append a new lNode to the head
template<class datType>
void List<datType>::appendToHead(datType data)
{
	lNode<datType> *newlNode;
	newlNode = new lNode<datType>();
	newlNode->data = data;
	
	cout << "Appending " << data << " To Head " << endl;

	if (root == NULL)
	{
		cout << "Adding to an empty list hence updating both root and tail" << endl;
		root = newlNode;
		tail = newlNode;
	}
	else
	{
		newlNode->nextlNode = root;
		root = newlNode;
	}

	_size++;

}

//Append a new lNode to the Tail
template<class datType>
void List<datType>::appendToTail(datType data)
{
	lNode<datType> *newlNode;
	newlNode = new lNode<datType>();
	newlNode->data = data;
	newlNode->nextlNode = NULL;

	cout << "Appending " << data << "To Tail " << endl;

	//If the only node is the head node
	if (root == NULL)
	{
		//Make the root point to the new node
		root = newlNode;
	}
	else
	{
		tail->nextlNode = newlNode;
		tail = newlNode;
	}

	//Assign tail to the end of the list
	tail = newlNode;
	_size++;
}

//Iterate through the list and print all the values
template<class datType>
void List<datType>::printList()
{
	lNode<datType> *iterator;
	iterator = root;

	if (iterator == NULL)
	{
		cout << "No lNodes Present " << endl;
		return;
	}
	//cout << "Values (Total : " << _size << ") : ";
	while (iterator != NULL)
	{
		cout << iterator->data;
		
		if (iterator->nextlNode != NULL)
			cout << "->";

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

template<class datType>
lNode<datType>* List<datType>::GetHead()
{
	return root;
}

//Clear the whole list until we reach the root
template<class datType>
void List<datType>::clear()
{
	while (root != NULL) 
	{
		deleteFromTail();
	}
}

template<class datType>
bool List<datType>::IsEmpty()
{
	return root == NULL;
}

template<class datType>
bool List<datType>::Find(datType data)
{
	lNode<datType>* iterator;
	iterator = root;

	if (iterator == NULL)
		return false;

	//cout << "Values (Total : " << _size << ") : ";
	while (iterator != NULL)
	{
		if (iterator->data == data)
			return true;

		iterator = iterator->nextlNode;

	}

	return false;
}