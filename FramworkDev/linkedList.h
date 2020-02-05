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
  void appendToTail(datType data);
  void appendToHead(datType data);
  void appendToPosition(datType data , int position);
  void deleteFromTail();
  void deleteFromHead();
  void deleteFromPosition(int position);
  void printList();
  int getSize();
  lNode<datType>* GetTail();
  void clear();
  bool IsEmpty();

  bool Find(datType data);

  //Specifics for queue
  lNode<datType>* appendToTailAndReturn(datType data);
  datType deleteFromHeadAndReturn();

  private:
  //Specifics for current count / size
  int _size;
  //The root of the list
  lNode<datType> *root;

  //The tail of the list (or the end)
  lNode<datType> *tail;
};

