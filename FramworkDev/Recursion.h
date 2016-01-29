#pragma once

//IO library
#include <iostream>

//Compute the factorial using recursion
int ComputeFactorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * ComputeFactorial(n -1);
}

//Reverse an input stream using recursion
void Reverse(char *a,int currentIndex,int size)
{	
	if (currentIndex > size - 1)
		return;

	Reverse(a,currentIndex + 1,size);
	cout.put(a[currentIndex]);
}