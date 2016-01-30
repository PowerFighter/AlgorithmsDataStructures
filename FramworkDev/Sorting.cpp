#include "Sorting.h"
#include <iostream>
using namespace std;


Sorting::Sorting(int size)
{
	a = new int[size];

	for (int i = 0; i < size; i++)
	{
		a[i] = 0;
	}
	cout << "Initializing Data " << endl;
	
	AllocSize = size;
	count = 0;
} 

void Sorting::AddData(int data)
{
	if (count >= AllocSize)
	{
		cout << "Not enough space " << endl;
		return;
	}

	a[count] = data;
	count++;
}

//Insertion Sort impl
void Sorting::InsertionSort(SORT_ORDER type)
{
	if (count == 0)
	{
		cout << "No elements in array " << endl;
		return;
	}

	int j = 0;
	for (int i = 0; i < count; i++)
	{
		int tmp = a[i];
		for (j = i; j > 0; j--)
		{
			if (type == SORT_ORDER::ascending)
			{
				if (a[j - 1] < tmp)
				{
					break;
				}
			}
			else
			{
				if (a[j - 1] > tmp)
				{
					break;
				}
			}

			//here push a[j-1] to one place
			a[j] = a[j - 1];
		}

		//Insert at correct location
		a[j] = tmp;
	}
}

//Selection Sort
void Sorting::SelectionSort(SORT_ORDER type)
{
	if (count == 0)
	{
		cout << "No elements in array " << endl; 
		return;
	}

	int least = 0;
	for (int i = 0; i < count - 1; i++)
	{
		least = i;
		for (int j = i + 1; j < count; j++)
		{
			if (type == SORT_ORDER::ascending)
			{
				if (a[j] < a[least])
					least = j;
			}
			else
			{
				if (a[j] > a[least])
					least = j;
			}
			
		}

		int tmp;
		tmp = a[i];
		a[i] = a[least];
		a[least] = tmp;
	}
}

//Bubble Sort
void Sorting::BubbleSort(SORT_ORDER type)
{
	if (count == 0)
	{
		cout << "No elements in array " << endl;
		return;
	}

	for (int i = 0; i < count - 1; i++)
	{
		for (int j = count - 1; j > i; j--)
		{
			int tmp;
			if (type == SORT_ORDER::descending)
			{
				if (a[j] > a[j - 1])
				{
					tmp = a[j];
					a[j] = a[j - 1];
					a[j - 1] = tmp;
				}
			}
			else
			{
				if (a[j] < a[j - 1])
				{
					tmp = a[j];
					a[j] = a[j - 1];
					a[j - 1] = tmp;
				}
			}
		}
	}
}

//Entry point for merge sort
void Sorting::MergeSort(SORT_ORDER type)
{
	DividePreMerge(0, count - 1,type);
}

//Implementation of Merge Sort
void Sorting::DividePreMerge(int start, int end, SORT_ORDER type)
{
	int pivot = 0;
	if (start < end)
	{
		pivot = (start + end) / 2;
		//First half at pivot
		DividePreMerge(start, pivot,type);
		//Second half from pivot to end
		DividePreMerge(pivot + 1, end , type);

		//Now merge divided arr
		Merge(start, pivot, pivot + 1, end,type);
	}
	
}


void Sorting::Merge(int Arr1Start, int Arr1End, int Arr2Start, int Arr2End, SORT_ORDER type)
{
	int lengthArr1 = Arr1End - Arr1Start + 1;
	int lengthArr2 = Arr2End - Arr2Start + 1;

	int arr1Count = Arr1Start;
	int arr2Count = Arr2Start;

	//Create a temp array to accomodate merging
	int *temp = new int[lengthArr1 + lengthArr2];
	int tempArrCount = 0;

	//Loop through both the arrays
	//Performing merge into temp
	while (arr1Count < Arr1Start + lengthArr1 &&  arr2Count < Arr2Start + lengthArr2)
	{
		if (a[arr1Count] <= a[arr2Count])
		{
			if (type == SORT_ORDER::ascending)
			{
				temp[tempArrCount] = a[arr1Count];
				arr1Count++;
			}
			else
			{
				temp[tempArrCount] = a[arr2Count];
				arr2Count++;
			}
		}
		else
		{
			if (type == SORT_ORDER::ascending)
			{
				temp[tempArrCount] = a[arr2Count];
				arr2Count++;
			}
			else
			{
				temp[tempArrCount] = a[arr1Count];
				arr1Count++;
			}

		}
		tempArrCount++;
	}

	//Now at this point we will have left overs
	//Cleanup arr1 leftovers
	while (arr1Count < Arr1Start + lengthArr1)
	{
		temp[tempArrCount] = a[arr1Count];
		arr1Count++;
		tempArrCount++;
	}

	//Cleanup arr2 leftovers
	while (arr2Count < Arr2Start + lengthArr2)
	{
		temp[tempArrCount] = a[arr2Count];
		arr2Count++;
		tempArrCount++;
	}

	//Copy back the temp array into inp
	int mainIndex = Arr1Start;
	for (int j = 0; j < tempArrCount; j++)
	{
		a[mainIndex] = temp[j];
		mainIndex++;
	}

	//Cleanup temp
	delete temp;
}

//Entry point for quick sort
void Sorting::QuickSort(SORT_ORDER type)
{
	DividePrePartition(0, count - 1, type);
}

//Partition the Array and find the index of the partition
int Sorting::PartitionArray(int start,int end,SORT_ORDER type)
{
	//get the mid point
	int midIndex = (start + end) / 2;
	
	//Move the mid point to end
	Swap(midIndex, end);

	int pIndex = start;

	for (int i = start; i < end; i++)
	{
		if (type == SORT_ORDER::ascending)
		{
			if (a[i] <= a[end])
			{
				Swap(i, pIndex);
				pIndex++;
			}
		}
		else
		{
			if (a[i] > a[end])
			{
				Swap(i, pIndex);
				pIndex++;
			}
		}
		
	}
	
	//Now swap back the pivot to pIndex
	Swap(pIndex, end);

	return pIndex;
}

//Find the Partition index and recursively go down the tree till we hit illegal range or single element
void Sorting::DividePrePartition(int start, int end, SORT_ORDER type)
{
	if (start < end)
	{
		int partitionIndex = PartitionArray(start, end, type);
		DividePrePartition(start, partitionIndex - 1, type);
		DividePrePartition(partitionIndex + 1, end, type);
	}
}

//Swap two indices in the array
void Sorting::Swap(int indexA, int indexB)
{
	if (indexA >= count || indexB >= count || indexA == indexB)
		return;

	int tmp = a[indexA];
	a[indexA] = a[indexB];
	a[indexB] = tmp;

}

//Print the data
void Sorting::PrintData()
{
	cout << "Array Data " << endl;
	for (int i = 0; i < count; i++)
	{
		cout << a[i];
		if (i != count - 1)
			cout << ",";
	}
	cout << endl;
	cout << "Count of Array " << count << endl;
}

