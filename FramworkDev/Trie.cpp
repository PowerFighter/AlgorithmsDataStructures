#include "Trie.h"
#include <iostream>
TrieNode::TrieNode(int Size)
{
	children = new TrieNode*[Size];

	for (int i = 0; i < Size; i++)
	{
		children[i] = 0;
	}

	bIsEndNode = false;
}

bool IsUpper(char a)
{
	return a >= 65 && a <= 90;
}

void ToLower(char& a)
{
	a = (char)((a - 'A') + 'a');
}

bool IsAlphabet(const char& a)
{
	return  (a >= 65 && a <= 90) || (a >= 97 && a <= 122);
}

Trie::Trie(int InSize)
{
	Size = InSize;
	root = new TrieNode(Size);
}

void Trie::Insert(std::string val)
{
	TrieNode* CurrNode = root;

	if (!CurrNode)
		return;

	if (val.length() == 0)
		return;

	int idx = 0;

	for (int i = 0; i < val.length(); i++)
	{
		if (!IsAlphabet(val[i]))
			continue;

		if (IsUpper(val[i]))
			ToLower(val[i]);

		idx = val[i] - 'a';

		if (CurrNode->children[idx] == 0)
		{
			CurrNode->children[idx] = new TrieNode(Size);
			//std::cout << " Creating new node for : " << (char)(97 + idx) << std::endl;
		}
		else
		{
			//std::cout << " Node exists for : " << val[i] << std::endl;
		}
		CurrNode = CurrNode->children[idx];
	}

	//if(CurrNode != root)
	//	std::cout << " Setting : " << (char)(97 + idx) <<  " As End Node " << std::endl;

	CurrNode->bIsEndNode = true;
}


void Trie::AutoCompleteChoices(std::string inVal, std::vector<std::string>& possibleOutStrings)
{
	possibleOutStrings.clear();

	TrieNode* CurrNode = root;

	if (inVal.length() == 0)
		return;

	int idx = 0;
	for (int i = 0; i < inVal.length(); i++)
	{
		idx = inVal[i] - 'a';

		if (CurrNode->children[idx] == 0)
		{
			return;
		}

		CurrNode = CurrNode->children[idx];
	}

	if (!CurrNode)
		return;

	//std::cout << "Possible Val " << inVal << std::endl;
	RecurAutoComp(CurrNode, inVal, possibleOutStrings);

	return;
}

void Trie::RecurAutoComp(TrieNode* CurrNode, std::string& possibleVal, std::vector<std::string>& possibleOutStrings)
{
	if (!CurrNode)
		return;

	if (CurrNode->bIsEndNode)
		possibleOutStrings.push_back(possibleVal);

	for (int i = 0; i < Size; i++)
	{
		if (CurrNode->children[i])
		{
			RecurAutoComp(CurrNode->children[i], possibleVal + char(97 + i), possibleOutStrings);
		}
	}
}

