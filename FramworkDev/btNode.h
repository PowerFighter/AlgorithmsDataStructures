/* The structure for a binary tree node*/
template <class datType>
struct Node
{
	Node *left;
	Node *right;
	datType data;
	Node *parent;
};