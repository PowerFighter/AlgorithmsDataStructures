/** Involves the Implementation of a stack datastructure using the linked list */

#include "linkedList.cpp"

template <class datType>
class lStack {

	public:
	lStack();
	void push(int data);
	datType pop();
	bool isEmpty();
	datType top();
	void clear();
	void printStack();

	private:
	List<datType> _internalList;
	lNode<datType> *topPointer;
};