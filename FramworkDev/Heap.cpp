#include "Heap.h"
#include <cmath>
#include <iostream>
using namespace std;

Heap::Heap(int maxSize,HeapType heapType)
{
	Arr = new int[maxSize];
	this->maxSize = maxSize;
	size = 0;
	type = heapType;
}

//This constructor builds a heap from a passed in array
Heap::Heap(int* inArr, int maxSize, HeapType heapType)
{
	Arr = inArr;
	this->maxSize = maxSize;
	size = maxSize;
	type = heapType;

	//Enforce heap property
	for (int i = floor(size/2) - 1; i >= 0; i--)
	{
		SiftDown(i);
	}		
}

int Heap::ExtractRoot()
{
	if (size == 0)
	{
		cout << "Heap is Empty " << endl;
		return -1;
	}
	
	int retVal = Arr[0];
	//Swap root and Arr[size - 1]
	int temp = Arr[size - 1];
	Arr[size - 1] = Arr[0];
	Arr[0] = temp;
	size = size - 1;
	SiftDown(0);

	return retVal;
}

HeapType Heap::GetTypeOfHeap()
{
	return type;
}

void Heap::SiftUp(int i)
{
	int currPos = i;
	int val = Arr[i];

	if (type == HeapType::MaxHeap)
	{
		//cout << " Parent for " << val << " is " << Parent(currPos) << endl;
		while (i > 0 && Arr[Parent(i)] < Arr[i])
		{
			//Swap i and parent of i
			int temp = Arr[i];
			Arr[i] = Arr[Parent(i)];
			Arr[Parent(i)] = temp;
			i = Parent(i);
		}
		//cout << "Final Position for " << val << " Initial Position " << currPos << " Is : " << i << endl;
	}

	if (type == HeapType::MinHeap)
	{
		//cout << " Parent for " << val << " is " << Parent(currPos) << endl;
		while (i > 0 && Arr[Parent(i)] >= Arr[i])
		{
			//Swap i and parent of i
			int temp = Arr[i];
			Arr[i] = Arr[Parent(i)];
			Arr[Parent(i)] = temp;
			i = Parent(i);
		}
		//cout << "Final Position for " << val << " Initial Position " << currPos << " Is : " << i << endl;
	}

}

void Heap::SiftDown(int i)
{
	if (type == HeapType::MaxHeap)
	{
		while (i < size)
		{
			int maxIndex = i;
			int leftChild = LeftChild(i);
			int maxVal = Arr[i];

			if (leftChild < size && maxVal < Arr[leftChild])
			{
				maxVal = Arr[leftChild];
				maxIndex = leftChild;
			}

			int rightChild = RightChild(i);

			if (rightChild < size && maxVal < Arr[rightChild])
			{
				maxVal = Arr[rightChild];
				maxIndex = rightChild;
			}

			//If max index == i at this stage means we have heap property satisfied
			if (maxIndex != i)
			{
				//Swap max index and i
				int temp = Arr[maxIndex];
				Arr[maxIndex] = Arr[i];
				Arr[i] = temp;
				i = maxIndex;
			}
			else
				break;
		}
	}

	if (type == HeapType::MinHeap)
	{
		while (i < size)
		{
			int minIndex = i;
			int leftChild = LeftChild(i);
			int minVal = Arr[i];

			if (leftChild < size && minVal >= Arr[leftChild])
			{
				minVal = Arr[leftChild];
				minIndex = leftChild;
			}

			int rightChild = RightChild(i);

			if (rightChild < size && minVal >= Arr[rightChild])
			{
				minVal = Arr[rightChild];
				minIndex = rightChild;
			}

			//If max index == i at this stage means we have heap property satisfied
			if (minIndex != i)
			{
				//Swap max index and i
				int temp = Arr[minIndex];
				Arr[minIndex] = Arr[i];
				Arr[i] = temp;
				i = minIndex;
			}
			else
				break;
		}
	}
	
}

bool Heap::Insert(int val)
{
	if (size > maxSize)
	{
		cout << "Heap is out of space, MaxSize : " << maxSize << endl;
		return false;
	}
		
	Arr[size] = val;
	size++;
	SiftUp(size - 1);
	return true;
}

void Heap::PrintHeap()
{
	//cout << "Size of the heap" << size;
	for (int i = 0; i < size; i++)
	{
		cout << Arr[i] << " ";
		cout << endl;
	}
}

bool Heap::IsEmpty()
{
	return size == 0;
}