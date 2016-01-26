#include "stackUsingLinkedList.h"

template<class datType>
lStack<datType> :: lStack() 
{
	//Initialize Top
	topPointer = NULL;

}

//Push an element onto the stack
template<class datType>
void lStack<datType>::push(int data) 
{
	topPointer = _internalList.appendToTailAndReturn(data);
	cout << "(LStack) Pushing the value " << topPointer->data << endl;
	printStack();
}

//Pop the top element and remove it from the stack
template<class datType>
datType lStack<datType>::pop()
{
	if (isEmpty())
	{
		cout << "(LStack) The Stack is empty" << endl;
		return -1;
	}

	datType returnDat;
	returnDat = topPointer->data;
	_internalList.deleteFromTail();
	topPointer = _internalList.GetTail();
	cout << "(LStack) Popping " << returnDat << endl;
	printStack();
	return returnDat;
}

//Is the stack empty or not
template<class datType>
bool lStack<datType>::isEmpty()
{
	if (_internalList.getSize() == 0)
		return true;
	else
		return false;
}

//Get the top of the stack without popping it
template<class datType>
datType lStack<datType>::top()
{
	if (isEmpty())
	{
		cout << "(LStack) The Stack is empty" << endl;
		return -1;
	}

	datType returnDat;
	returnDat = topPointer->data;
	return returnDat;
}

//Clear the stack
template<class datType>
void lStack<datType>::clear()
{
	_internalList.clear();
	topPointer = NULL;
}

//Print the whole stack
template<class datType>
void lStack<datType>::printStack()
{
	if (_internalList.getSize() == 0) 
	{
		cout << "Stack is empty" << endl;
		return;
	}
	_internalList.iterateAndPrint();

}

