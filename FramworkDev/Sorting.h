#pragma once

#include "queueUsingLinkedList.cpp"

enum SORT_ORDER
{
	ascending,
	descending,
};

class Sorting
{
	//Array pointer
	int* a;

	//Count of the array
	int count;

	//Allocated size
	int AllocSize;

	public:
	
	Sorting(int size);
	
	//Add data to the array
	void AddData(int data);

	//Insertion Sort implementation
	void InsertionSort(SORT_ORDER type);
	
	//Selection Sort implementation
	void SelectionSort(SORT_ORDER type);

	//Bubble Sort implementation
	void BubbleSort(SORT_ORDER type);
	
	//Merge Sort implementation
	void MergeSort(SORT_ORDER type);
	void DividePreMerge(int start, int end,SORT_ORDER type);
	void Merge(int Arr1Start, int Arr1End, int Arr2Start, int Arr2End,SORT_ORDER type);

	/*Quick Sort implementation*/

	//Entry point for quicksort
	void QuickSort(SORT_ORDER type);

	//Partition the array and return the index of the pivot	
	int PartitionArray(int start, int end, SORT_ORDER type);

	//Divide the array based on the partition index
	void DividePrePartition(int start, int end, SORT_ORDER type);
	
	/*End Quick Sort implementation*/
	
	/* Radix Sort*/
	//Linked list queues
	lqueue<int> *radixQueues;
	
	//Radix sort
	void RadixSort(SORT_ORDER type);
	void RadixSortPass(SORT_ORDER type,int currentDivisor);

	/* End Radix Sort Implementation*/

	/*Utility functions*/
	//Swap the elements at indexA and indexB
	void Swap(int indexA, int indexB);
		
	//Get max element
	int GetMax();

	//Print the data
	void PrintData();
};