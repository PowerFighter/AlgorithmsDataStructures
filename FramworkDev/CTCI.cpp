#include "CTCI.h"
#include <iostream>
using namespace std;

//Utility function to return the length of the cstring
int Length(char testString[])
{
	int length = 0;
	for (length = 0; testString[length] != NULL; ++length);

	return length;
}

float absolute(float val)
{
	return (val < 0.0f ? val * -1.0f : val);
}

int numberOfDigits(int val)
{
	int currVal = val;
	int numberDigits = 0;

	while (currVal != 0)
	{
		currVal = (int) (currVal / 10);
		numberDigits++;
	}

	return numberDigits;
}

char* int2Char(int val)
{
	int numberDigits = numberOfDigits(val);

	//cout << "Int 2 Char : " << val <<  ", Number of digits " << numberDigits << endl;
	char* outChar = new char[numberDigits + 1];
	outChar[numberDigits] = '\0';

	if (numberDigits == 1)
	{
		outChar[0] = (char)(48 + val);
	}
	else
	{
		int currVal = val;
		int digitIndex = numberDigits - 1;

		while (digitIndex >= 0)
		{
			outChar[digitIndex] = (char)(48 + currVal % 10);
			currVal = (int)(currVal / 10);
			digitIndex--;
		}
	}

	return outChar;
}
/*
CTCI 1.1

Is Unique: Implement an algorithm to determine if a string has all unique characters. What if you cannot use additional data structures ?

Input : string (Assume ASCII) (Assume length > 0)
Output : True if all characters are unique, False if duplicate characters exist.


*/

bool IsUnique(char string[],int length)
{
	bool exists[256];
	bool result = true;

	for (int i = 0; i < 256; i++)
		exists[i] = false;

	for (int i = 0; i < length; i++)
	{
		int asciiVal = (int)(string[i]);

		if (exists[asciiVal])
		{
			result = false;
			break;
		}
		else
		{
			exists[asciiVal] = true;
		}
	}

	return result;
}

/*
CTCI 1.2

Check Permutation : Given two strings, write a method to decide if one is a permutation of the other

Input : strings s1 and s2 (Assume lengths > 0)
Output : True if both strings are permutations of one another else False

//Possible solutions
-> Sort s1 and s2 and compare sorted s1 & s2 (O(nlogn + n))
-> Create a map of 256 size (ints), iterate through s1 and increment the index corressponding to the character in s1 ( O(n)) size O(256))
	->Iterate through to s2, decrement the index corressponding to the character in s1
	->If the value decreases below zero return false
	->If successfully finished the loop then loop through the map and see if all the 256 values are zero.
*/

bool CheckPermutation(char* s1, int length1, char* s2, int length2)
{
	int counts[256];
	
	for (int i = 0; i < 256; i++)
		counts[i] = 0;

	//Loop through s1
	for (int i = 0; i < length1; i++)
	{
		counts[(int)(s1[i])]++;
	}

	for (int i = 0; i < length1; i++)
	{
		int asciiVal = (int)(s2[i]);

		counts[asciiVal]--;

		if (counts[asciiVal] < 0)
			return false;
	}

	for (int i = 0; i < 256; i++)
	{
		if (counts[i] > 0)
			return false;
	}

	return true;
}

/*
CTCI 1.3

URLify : Write a method to replace all spaces in a string with '%20', You may assume that the string has sufficient space at the end to hold the additional characters,
and that you are given the 'true' length of the string. 
			Example
			Input : "Mr John Smith      "
			Output : "Mr%20John%20Smith"

Input : String s1 (Assume enough space for storing the extra characters)
Output : String s1 with '%20' appended

Possible solutions
->Maintain two locations,
	-> (Scan) starting at the last character
	-> (Actual) the other to the location (After adding %20)
		-> Actual => Scan + (number of spaces) * length of (%20) - 1
->loop from Scan to zero
	-> If the scanned location holds a character other than whitespace apply the character to the "actual" location
	-> If the scanned location holds add %20 using actual (actual gets decremented thrice here)

Possible extensions
-> Make the '%20' string dynamic

*/

char* URLify(char* TestString)
{
	int totalLength = Length(TestString);

	cout << "URLify Length : " << totalLength << endl;
	int Scan = 0;
	int Actual = 0;
	int Spaces = 0;
	bool bFoundScan = false;
	for (int i = totalLength - 1; i >= 0; i--)
	{
		if (bFoundScan)
		{
			if (TestString[i] == ' ')
			{
				Spaces++;
			}
		}
		else
		{
			if (TestString[i] != ' ')
			{
				Scan = i;
				bFoundScan = true;

			}
		}	
	}

	//cout << "Scan Start Location : " << Scan << endl;
	//cout << "Number of Spaces : " << Spaces << endl;

	Actual = Scan + Spaces * 2;

	if (Actual > totalLength)
	{
		cout << " Not enough spaces at the end " << endl;
		return TestString;
	}
		
	for (int i = Scan ; i >= 0; i--)
	{
		if (TestString[i] != ' ')
		{
			TestString[Actual] = TestString[i];
			Actual--;
		}
		else
		{
			TestString[Actual] = '0';
			TestString[Actual - 1] = '2';
			TestString[Actual - 2] = '%';

			Actual = Actual - 3;
		}
	}
	return TestString;
}

/*
CTCI 1.4

Palindrome Permutation : Given a string, write a function to check if its a permutation of a palindrome. A palindrome is a word or a phrase
that is the same forwards and backwards. A Permutation is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words.
	Example
		Input : "Tact Coa" (Assume the length > 0) (Assume : ignore spaces) (assume extended ASCII (256 characters))
		Output : True (permutations : "taco cat", "atco cta" etc are palindromes)

Input : String s1
Output : true if at least one of the permutations of s1 is a palindrome.

Possible solutions :
-Count the characters
-All characters can have even numbers but only one character can have odd number.
-Complexity analysis => O(256) + O(n) + O(256) (n => length of the string)
*/

bool PalinPerm(char* s1)
{
	bool result = false;

	int length = Length(s1);
	
	if (length < 2)
		return result;

	result = true;

	int charCount[256];

	//cout << "Length of String " << length << endl;
	//Intialization
	for (int i = 0; i <= 255; i++)
	{
		charCount[i] = 0;
	}

	for (int i = 0; i <= length - 1; i++)
	{
		if (s1[i] != ' ')
		{
			//cout << "Analysing " << s1[i] << endl;
			charCount[(int)s1[i]]++;
		}
			
	}

	bool bHasOddChar = false;
	for (int i = 0; i <= 255; i++)
	{
		if (charCount[i] % 2 != 0)
		{
			if (bHasOddChar)
			{
				result = false;
				break;
			}
			else
			{
				bHasOddChar = true;
			}
		}
	}

	return result;
}

/*
CTCI 1.5

One Away : There are three types of edits that can be performed on strings: insert a character,remove a character or replace a character.
Given two strings, write a function to check if they are one edit(or zero edits) away.

	Example
	Input : pale, ple
	Output : True 
	Input : pales, pale
	Output : True
	Input : pale, bale
	Output : True
	Input : pale, bake
	Output : False

Input : Strings s1,s2 (Assume length > 0)
Output : True if s1 and s2 are one edit away, False otherwise

Possible solutions :
Solution 1:
	-Compare lengths of two strings
	-if difference in length of two strings > 1 return false
	-if difference  == 1
		-Take the larger string and try removing the extra character
		-If resulting string == other string return true else return false
	-if difference == 0
		-Compare both strings and count the differences
		-if number of differences > 1 return false
		-else return true.

Complexity Analysis :
Worst case : 
	-Length Diff = 1 
		length calculation : O(n)
		internal loop : O(n)
	-length Diff = 0
		length calculation : O(n)
		internal loop : O(n)

	Space complexity : O(1)
*/

bool OneAway(char* s1, char* s2)
{
	int s1Length = Length(s1);
	int s2Length = Length(s2);

	float absLengthDiff = absolute(s1Length - s2Length);

	if (absLengthDiff > 1)
		return false;

	//Second case abs length is 1
	if (absLengthDiff == 1)
	{
		int s1Index = 0;
		int s2Index = 0;
		int diffCount = 0;
		if (s1Length > s2Length)
		{	
			while (s1[s1Index] != NULL && s2[s2Index] != NULL)
			{
				if (s1[s1Index] != s2[s2Index])
				{
					diffCount++;

					if (diffCount > 1)
						return false;

					s1Index++;
				}
				else
				{
					s1Index++;
					s2Index++;
				}
			}
		}
		else
		{
			while (s1[s1Index] != NULL && s2[s2Index] != NULL)
			{
				if (s1[s1Index] != s2[s2Index])
				{
					diffCount++;

					if (diffCount > 1)
						return false;

					s2Index++;
				}
				else
				{
					s1Index++;
					s2Index++;
				}
			}
		}
	}
	else // Third case Equal strings (s1length == s2length)
	{
		int diffCount = 0;

		for (int i = 0; i < s1Length; i++)
		{
			if (s1[i] != s2[i])
			{
				diffCount++;

				if (diffCount > 1)
					return false;
			}
		}
	}

	return true;
}

/*
CTCI 1.6

String Compression : Implement a method to perform basic string compression using the counts of repeated characters.If the compressed string 
would not become smaller than the original string, your method should return the original string. Assume the string has only uppercase and
lowercase letters (a-z)
	
	Example:
	Input : aabcccccaaa
	Output : a2b1c5a3

Input : string s1
Output : new string s2 with the counted characters

Possible solutions:
-Loop through the string and start counting with character in "CurrentCharacter"
-If character is different from "CurrentCharacter" then update CurrentCharacter and append the count to new string.

TODO : Optimize code mostly in terms of readability.

*/
char* CompressString(char* s1)
{
	int length = Length(s1);
	int newLength = length * 2;

	char* s2 = new char[newLength];
	char currChar = '\0';
	int CurrCount = 0;
	int s2Index = 0;
	for (int i = 0; i < length; i++)
	{
		if (currChar == '\0')
		{
			currChar = s1[i];
			CurrCount++;
			s2[s2Index] = currChar;
			s2Index++;

			if (i == length - 1)
			{
				char* count = int2Char(CurrCount);
				int countLength = Length(count);

				for (int j = 0; j < countLength; j++)
				{
					s2[s2Index] = count[j];
					s2Index++;
				}
			}
		}
		else
		if(currChar != s1[i])
		{
			char* count = int2Char(CurrCount);
			int countLength = Length(count);

			for (int j = 0; j < countLength; j++)
			{
				s2[s2Index] = count[j];
				s2Index++;
			}

			s2[s2Index] = s1[i];
			s2Index++;
			currChar = s1[i];
			CurrCount = 1;

			if (i == length - 1)
			{
				char* count = int2Char(CurrCount);
				int countLength = Length(count);

				for (int j = 0; j < countLength; j++)
				{
					s2[s2Index] = count[j];
					s2Index++;
				}
			}
		}
		else
		if (i == length - 1)
		{
			CurrCount++;
			char* count = int2Char(CurrCount);
			int countLength = Length(count);

			for (int j = 0; j < countLength; j++)
			{
				s2[s2Index] = count[j];
				s2Index++;
			}
		}
		else
		{
			CurrCount++;
		}
	}

	//Terminate s2
	s2[s2Index] = '\0';

	int s2Length = Length(s2);

	if (s2Length >= length)
		return s1;

	return s2;

}

/*
CTCI 1.7

Rotate Matrix : Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes, write a method to rotate the image by 90 degrees, 
Can you do in place?

*/
