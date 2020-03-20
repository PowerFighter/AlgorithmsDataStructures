#pragma once
#include <string>
#include <vector>

class TrieNode
{
public:

	TrieNode(int Size);
	TrieNode** children;
	bool bIsEndNode;
};

class Trie
{
public:
	
	Trie(int InSize);
	int Size;
	TrieNode* root;

	void Insert(std::string val);
	void AutoCompleteChoices(std::string inVal,std::vector<std::string>& possibleOutStrings);

private:
	void RecurAutoComp(TrieNode* CurrNode, std::string& possibleVal, std::vector<std::string>& possibleOutStrings);
};