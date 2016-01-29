#include "BinarySearchTree.cpp"
#include "stackUsingLinkedList.cpp"
#include "doubleLinkedList.cpp"
#include "Sorting.h"

//Recursion tests
#include "Recursion.h"

//For performance query counter
#include <tchar.h>
#include <windows.h>

//For random number generator
#include <ctime> // Needed for the true randomization
#include <cstdlib>

//Data structure declarations
binaryTree<int> one;
DoubleLinkedList<int> dlList;

int main()
{
	Sorting* SortImpl;
	
	int xRan;
	int ArrayNo = 100;
	srand(time(0));

	SortImpl = new Sorting(ArrayNo);

	for (int i = 0; i < ArrayNo; i++)
	{
		 // This will ensure a really randomized number by help of time.
		xRan = rand() % ArrayNo + 1; // Randomizing the number between 1-15
		SortImpl->AddData(xRan);
	}

	SortImpl->PrintData();

	LARGE_INTEGER frequency;        // ticks per second
	LARGE_INTEGER t1, t2;           // ticks
	double elapsedTime;

	// get ticks per second
	QueryPerformanceFrequency(&frequency);

	// start timer
	QueryPerformanceCounter(&t1);

	//Call selection sort
	//SortImpl->SelectionSort(SORT_ORDER::descending);
	//SortImpl->InsertionSort(SORT_ORDER::ascending);
	SortImpl->MergeSort(SORT_ORDER::descending);

	// stop timer
	QueryPerformanceCounter(&t2);

	// compute and print the elapsed time in millisec
	elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
	
	cout << "Time Elapsed : " << elapsedTime << endl;

	SortImpl->PrintData();
	
	//Reverse using recursion
	//Reverse("ABC",0,3);

	/* one.insert(3);
	one.insert(1);
	one.insert(4);
	one.insert(2);
	one.printAllValues(preorder);
	one.printMaxValue();
	one.printMinValue();
	Node *test = one.search(50);
	if(test != NULL)
	{
	cout<<"Yup we found the value SUCCESS : "<<test->data << endl;
	}*/

	//Test 2
	/*one.insert(15);
	one.insert(6);
	one.insert(18);
	one.insert(20);
	one.insert(17);
	one.insert(7);
	one.insert(3);
	one.insert(13);
	one.insert(2);
	one.insert(4);
	one.insert(9);
	*/
	//cout<<"No of children of 18 "<<one.returnNoOfChildren(one.search(9))<<endl;
	/* Node *test2 = one.getPredecessor(7);
	if(test2 != NULL)
	{
	cout<<"Required predecessor is "<<test2->data<<endl;
	}
	else
	{
	Node *test = one.search(18);
	if(test == NULL)
	{
	cout<<"No such value in tree"<<endl;
	}
	else
	{
	cout<<"No predecessor"<<endl;
	}
	}*/
	//one.printAllValues(inorder);
	//one.deleteNode(6);
	//one.deleteNode(3);
	//Node *test2 = one.search(15);
	//cout<<"Value "<<test2->left->left->left->data<<endl;
	//one.printAllValues(inorder);
	//one.breadthFirstPrint();
	/*two.appendToTail(2);
	two.appendToHead(15);
	two.appendToTail(3);
	two.appendToHead(50);
	two.appendToTail(4);
	two.appendToPosition(35,2);
	two.iterateAndPrint();*/
	/* two.deleteFromTail();
	two.deleteFromTail();
	two.deleteFromTail();
	two.iterateAndPrint();
	two.deleteFromHead();
	two.deleteFromHead();
	two.iterateAndPrint();*/

	// two.deleteFromPosition(3);
	// two.iterateAndPrint();
	/*testQueue.push_from_back(5);
	cout<<"Is the queue empty : "<<testQueue.is_empty()<<endl;
	testQueue.push_from_back(6);
	cout<<"Printing queue size : "<<testQueue.count<<endl;
	testQueue.print_queue();
	cout<<"Taking value : "<<testQueue.take_from_front()<<endl;
	testQueue.print_queue();
	cout<<"Printing queue size : "<<testQueue.count<<endl;
	cout<<"Taking value again : "<<testQueue.take_from_front()<<endl;
	testQueue.print_queue();*/

	/*
	List test;

	test.appendToHead(1);
	test.iterateAndPrint();
	test.appendToHead(2);
	test.iterateAndPrint();
	//test.deleteFromHeadAndReturn();
	test.appendToPosition(4, 2);
	test.iterateAndPrint();
	test.deleteFromPosition(3);
	test.iterateAndPrint();
	test.deleteFromPosition(2);
	test.iterateAndPrint();
	test.deleteFromTail();
	test.iterateAndPrint();
	//test.deleteFromTail();
	//test.deleteFromHead();
	//test.iterateAndPrint();
	
	*/

	/*
	lStack<int> stack;

	stack.push(4);
	stack.push(12);
	stack.push(20);
	stack.top();
	stack.pop();
	stack.pop();
	stack.clear();
	stack.printStack();

	dlList.appendToHead(4);
	dlList.appendToHead(15);
	dlList.appendToHead(30);
	dlList.appendToTail(45);
	dlList.appendToPosition(20, 3);
	dlList.printListForward();
	dlList.printListBackward();
	dlList.deleteFromHead();
	dlList.printListForward();
	dlList.deleteFromHead();
	dlList.printListForward();
	dlList.deleteAtPosition(2);
	dlList.printListForward();
	dlList.deleteAtPosition(2);
	dlList.printListForward();
	dlList.appendToTail(30);
	dlList.appendToTail(40);
	dlList.printListForward();
	dlList.deleteAtPosition(1);
	dlList.printListForward();
	dlList.deleteAtPosition(2);
	dlList.printListForward();
	dlList.deleteAtPosition(1);
	dlList.printListForward();
	*/
	
	while (!getchar()) 
	{

	}
	
	return 0;
}
