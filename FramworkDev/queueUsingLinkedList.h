/*	Queue using a linked list
	Uses the linked list class defined in linkedList.h 
	Templated so can accept any generic datatype  */
#include "linkedList.cpp"

template<class datType>
class lqueue
{
  public:
  int count;

  lqueue();
  void push_from_back(int data);
  int  take_from_front();
  void print_queue();
  bool is_empty();

  private:
  lNode<datType> *front;
  lNode<datType> *back;
  List<datType> lList;
};

