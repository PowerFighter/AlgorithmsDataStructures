#include "doubleLinkedList.h"

template<class datType> 
DoubleLinkedList <datType>::DoubleLinkedList()
{
	head = NULL;
	tail = NULL;
	_size = 0;
}

template<class datType>
void DoubleLinkedList<datType>::appendToTail(datType data)
{
	//Allocate memory and initialize the dlNode
	dlNode<datType> *newNode;
	newNode = new dlNode<datType>();
	newNode->prevNode = NULL;
	newNode->data = data;
	newNode->nextNode = NULL;
	
	//Handle the initial case when there are no nodes
	if (_size == 0) {
		
		head = newNode;
		tail = newNode;
		_size++;
		return;
	}

	dlNode<datType> *iterator;
	iterator = head;

	while (iterator->nextNode != NULL) {
		iterator = iterator->nextNode;
	}

	iterator->nextNode = newNode;
	newNode->prevNode = iterator;
	tail = newNode;
	_size++;
}

template<class datType>
void DoubleLinkedList<datType>::appendToHead(datType data)
{
	dlNode<datType> *newNode;
	newNode = new dlNode<datType>();
	newNode->prevNode = NULL;
	newNode->data = data;
	newNode->nextNode = NULL;

	//Handle the initial case when there are no nodes
	if (_size == 0) {

		head = newNode;
		tail = newNode;
		_size++;
		return;
	}
	
	newNode->nextNode = head;
	head->prevNode = newNode;
	head = newNode;
	_size++;
}

//Add the node with data to position indexed from 1
template<class datType>
void DoubleLinkedList<datType>::appendToPosition(datType data, int position)
{
	if (position > _size && _size > 0)
	{
		cout << "(DoubleLinkedList) Invalid Position" << endl;
		return;
	}

	//Iterate till the position required
	dlNode<datType> *iterator;
	iterator = head;
	int currentPosition = 1;

	//Handle the edge cases
	//Adding position is the head position
	if (position == 1)
	{
		appendToHead(data);
		return;
	}

	dlNode<datType> *newNode;
	newNode = new dlNode<datType>();
	newNode->prevNode = NULL;
	newNode->data = data;
	newNode->nextNode = NULL;

	while (iterator->nextNode != NULL && currentPosition < position)
	{
		iterator = iterator->nextNode;
		currentPosition++;
	}

	//This means we reached the end of the list 
	if (iterator->nextNode == NULL)
	{
		//So we compare to see if this is the position wanted 
		if (currentPosition == position)
		{
			newNode->nextNode = iterator;
			newNode->prevNode = iterator->prevNode;
			(iterator->prevNode)->nextNode = newNode;
			iterator->prevNode = newNode;       
			_size++;
		}

		return;
	}

	newNode->nextNode = iterator;
	newNode->prevNode = iterator->prevNode;
	(iterator->prevNode)->nextNode = newNode;
	iterator->prevNode = newNode;
	_size++;

	return;

}

template<class datType>
void DoubleLinkedList<datType>::deleteFromTail()
{
	//Handle the initial case when there are no nodes
	if (_size == 0) {
		cout << "(DoubleLinkedList) No Nodes Present" << endl;
		return;
	}

	cout << "(DoubleLinkedList) Deleting From the tail " << endl;

	//If there is only one element do quick clean
	if (_size == 1)
	{
		delete tail;
		head = NULL;
		tail = NULL;
		_size--;
		return;
	}

	dlNode<datType> *temp = tail->prevNode;
	delete tail;
	tail = temp;
	tail->nextNode = NULL;
	_size--;

}

template<class datType>
void DoubleLinkedList<datType>::deleteFromHead()
{
	//Handle the initial case when there are no nodes
	if (_size == 0) 
	{
		cout << "(DoubleLinkedList) No Nodes Present" << endl;
		return;
	}

	cout << "(DoubleLinkedList) Deleting From the head " << endl;

	//If there is only one element do quick clean
	if (_size == 1)
	{
		delete head;
		head = NULL;
		tail = NULL;
		_size--;
		return;
	}

	dlNode<datType> *temp = head->nextNode;
	delete head;
	head = temp;
	head->prevNode = NULL;
	_size--;
}

template<class datType>
void DoubleLinkedList<datType>::deleteAtPosition(int position)
{
	if (_size == 0)
	{
		cout << "(DoubleLinkedList) List is Empty" << endl;
		return;
	}

	if (position > _size)
	{
		cout << "(DoubleLinkedList) Invalid Position " << endl;
		return;
	}

	//If position == size means delete at the tail
	if (position == _size) 
	{
		deleteFromTail();
		return;
	}
	
	//If the size is 1 and the position is also 1 just clear the list
	if (position == 1)
	{
		deleteFromHead();
		return;
	}

	int currentPosition = 1;
	
	dlNode<datType> *iterator = head;

	while (iterator->nextNode != NULL && currentPosition < position)
	{
		iterator = iterator->nextNode;
		currentPosition++;
	}

	//if we are here we found the position so delete and do assign
	dlNode<datType> *nodeToDelete = iterator;
		
	(iterator->prevNode)->nextNode = nodeToDelete->nextNode;
	(iterator->nextNode)->prevNode = nodeToDelete->prevNode;

	delete nodeToDelete;

	_size--;
}
 
template<class datType>
void DoubleLinkedList<datType>::printListForward()
{
	if (_size == 0) {
		cout << "(DoubleLinkedList) List is Empty"<<endl;
		return;
	}

	cout << "Printing the list forwards " << endl;
	dlNode<datType> *iterator = head;

	cout << "Values (Size : " << _size << ")";
	cout << " " << iterator->data;
	while (iterator->nextNode != NULL)
	{
		iterator = iterator->nextNode;
		cout << " " << iterator->data;
	}

	cout << endl;
	cout << "Head Value " << head->data << endl;
	cout << "Tail Value " << tail->data << endl;
}

template<class datType>
void DoubleLinkedList<datType>::printListBackward()
{
	if (_size == 0) {
		cout << "(DoubleLinkedList) List is Empty";
			return;
	}

	cout << "Printing the list backwards " << endl;
	dlNode<datType> *iterator = tail;
	//Print tail value first
	cout << "Values (Size : " << _size << ")";
	cout << " " << iterator->data;
	while (iterator->prevNode != NULL)
	{
		iterator = iterator->prevNode;
		cout << " " << iterator->data;
	}

	cout << endl;
	cout << "Head Value " << head->data << endl;
	cout << "Tail Value " << tail->data << endl;
}

template<class datType>
int DoubleLinkedList<datType>::getSize()
{
	return _size;
}