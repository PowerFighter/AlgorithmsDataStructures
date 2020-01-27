/* Structure for a one way linked list node*/

template <class datType>
struct lNode
{
	//Data held (Note) This can be anything other than int
	datType data;
	lNode<datType>* nextlNode;
};