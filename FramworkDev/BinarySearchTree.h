/* This represents a binary tree is a tree which has bt nodes which can have a max of two children */
/* The binary tree is ordered as per the value held by the data*/
#include <iostream>
#include "queueUsingLinkedList.cpp"
#include "btNode.h"
using namespace std;

enum TYPE_OF_TRAVERSAL
{
	inorder,
	preorder,
	postorder
};

template <class datType>
class binaryTree
{
public:
	Node<datType> *root;

	binaryTree()
	{
		root = NULL;
	}

	void insert(datType data);
	void printAllValues(TYPE_OF_TRAVERSAL type);
	Node<datType>* search(datType data);
	void printMaxValue();
	void printMinValue();
	Node<datType>* getSuccessor(datType data);
	Node<datType>* getPredecessor(datType data);
	void deleteNode(datType data);
	void breadthFirstPrint();

private:
	void insert(datType data, Node<datType> *leaf);
	Node<datType>* search(datType data, Node<datType> *leaf);
	void inorder(Node<datType>  *leaf);
	void preorder(Node<datType>  *leaf);
	void postorder(Node<datType>  *leaf);
	void goLeft(Node<datType>  *leaf);
	void goRight(Node<datType>  *leaf);
	Node<datType>* returnLeftMostFromCurrent(Node<datType>  *leaf);
	Node<datType>* returnRightMostFromCurrent(Node<datType>  *leaf);
	bool isRightChild(Node<datType>  *leaf);
	bool isLeftChild(Node<datType>  *leaf);
	bool isRoot(Node<datType>  *leaf);
	bool isEmpty();
	int returnNoOfChildren(Node<datType>  *leaf);
};