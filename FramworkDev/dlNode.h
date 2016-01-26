/* A node with two pointers to the previous node and the next one */

template<class type>
struct dlNode 
{
	dlNode *prevNode;
	type data;
	dlNode *nextNode;

	dlNode()
	{
		prevNode = NULL;
		nextNode = NULL;
	}
};