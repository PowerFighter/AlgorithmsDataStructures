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
