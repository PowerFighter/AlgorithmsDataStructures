#pragma once
/* The List class is a one way linked list with functions that can be implemented for higher level data-structures*/
/* Uses the lNode structure which has the one-way link to the next node*/
#include <iostream>
#include "lNode.h"
using namespace std;

template <class datType>
class List
{
  public:
  //Initialize the root
  List();

  //Function declarations
  void appendToTail(int data);
  void appendToHead(int data);
  void appendToPosition(int data , int position);
  void deleteFromTail();
  void deleteFromHead();
  void deleteFromPosition(int position);
  void iterateAndPrint();
  int getSize();
  lNode<datType>* GetTail();
  void clear();

  //Specifics for queue
  lNode<datType>* appendToTailAndReturn(int data);
  datType deleteFromHeadAndReturn();

  private:
  //Specifics for current count / size
  int _size;
  //The root of the list
  lNode<datType> *root;

  //The tail of the list (or the end)
  lNode<datType> *tail;
};

