#pragma once
#include <cmath>

enum HeapType
{
	MaxHeap,
	MinHeap,
};

//Heap is a tree data structure which is allocated with some rules
//There are two types of Heaps
//Max Heap - every parent is >= its children
//Min Heap - every parent is < its children
//The interesting usecase of the heap is the root always is the 
//Max element or min element
//Preserving the heap property is done through operations Sift up 
//And Sift down
class Heap
{
	//Size is the current number of elements in the heap
	int size;

	//MaxSize is the max allocation that can be done on this heap
	//This is the size of the internal array
	int maxSize;

	//The actual storage
	int* Arr;

	//Type of the heap
	HeapType type;

	//Tree access methods
	inline int Parent(int i) { return floor((i + 1) / 2) - 1; }
	inline int LeftChild(int i) { return 2* i + 1; }
	inline int RightChild(int i) { return 2 * i + 2; }

	//Heap property maintaining functions
	void SiftUp(int i);
	void SiftDown(int i);
public:
	
	Heap(int maxSize,HeapType heapType);

	//Get the type of the current heap
	HeapType GetTypeOfHeap();

	//Extract the root
	//Max heap -> Max element
	//Min heap -> Min element
	int ExtractRoot();

	//Print the array in this heap
	//For debug purposes
	void PrintHeap();

	//Insert a value into this heap
	//Returns if operation was a success or not
	bool Insert(int val);
};