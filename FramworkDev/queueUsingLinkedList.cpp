#pragma once
#include "queueUsingLinkedList.h"

template <class datType>
lqueue<datType> :: lqueue()
{
	count = 0;
	front = NULL;
	back = NULL;
}

//Test whether the queue is empty or not
template <class datType>
bool lqueue<datType>::is_empty()
{
	if (count <= 0)
		return true;
	else
		return false;
}

//Push onto queue---enqueue
template <class datType>
void lqueue<datType>::push_from_back(int data)
{
	lNode<datType> *retNode;
	// cout<<"[QUEUE] Pushing back data "<<data<<endl;
	retNode = lList.appendToTailAndReturn(data);
	count++;
}

//Remove from top of the queue
template <class datType>
int lqueue<datType>::take_from_front()
{
	if (count > 0)
	{
		count--;
		return lList.deleteFromHeadAndReturn();
	}
	else
	{
		cout << "Queue Empty" << endl;
		return -1;
	}
}

//Print the queue 
template <class datType>
void lqueue<datType>::print_queue()
{
	if (count > 0)
		lList.iterateAndPrint();
	else
	{
		cout << "Queue Empty " << endl;
		return;
	}
}

