/* A linked list with the ability to traverse both ways
Uses the dlNode which basically has two pointers to the start and end node
*/
#include "dlNode.h"

template<class datType>
class DoubleLinkedList
{

public:
	DoubleLinkedList();

	//Appending functions
	void appendToTail(datType data);
	void appendToHead(datType data);
	void appendToPosition(datType data, int position);
	
	//Deleting functions
	void deleteFromTail();
	void deleteFromHead();
	void deleteAtPosition(int position);

	//Display functions
	void printListForward();
	void printListBackward();

	int getSize();
private:
	//The size of the list (actual number of elements)
	int _size;

	dlNode<datType> *head;
	dlNode<datType> *tail;
};