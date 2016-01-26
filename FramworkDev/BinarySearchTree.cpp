#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

//Function which returns if the tree is empty 
template <class datType>
bool binaryTree<datType> :: isEmpty()
{
  if(root == NULL)
    return true;
  else
    return false;

}

//Function which prints the tree in BFS traversal
template <class datType>
void binaryTree<datType> :: breadthFirstPrint()
{
  if(isEmpty())
  {
    cout<<"Tree is Empty "<<endl;
    return;
  }

  cout<<"----------------Initializing Breadth First------------"<<endl;
  //Initialize the queues 
  lqueue<int> alphaQueue[2];
  int active = 0;
  int currentValToBePrinted;
  Node<datType> *tempNode;
  // cout<<"Root value "<<root->data;
  alphaQueue[active].push_from_back(root->data);
  //cout<<"Alpha queue root value "<<alphaQueue[active].lList.root->nextlNode->data<<endl;
  while( !alphaQueue[active].is_empty() || !alphaQueue[(active+1)%2].is_empty())
  {
    //cout<<"Am inside"<<active<<endl;
    //Switching active if current active is empty
    if( alphaQueue[active].is_empty() )
    {
      active = (active + 1) % 2;
      cout<<endl;
    }
    else
    {
      currentValToBePrinted = alphaQueue[active].take_from_front();
      cout<<currentValToBePrinted<<"\t";
      tempNode = search(currentValToBePrinted);
       if(tempNode == NULL)
			cout<<"Oops we should never be here "<<endl;
      else
      {
	//Add children to the deactivated queue
	if(tempNode->left != NULL)
	  alphaQueue[(active+1)%2].push_from_back(tempNode->left->data);
	if(tempNode->right != NULL)
	    alphaQueue[(active+1)%2].push_from_back(tempNode->right->data);
      }
      
      
    }
    
  }
  cout<<endl;
} 

//Function which returns the total number of the given node
template <class datType>
int binaryTree<datType> ::returnNoOfChildren(Node<datType> *node)
{
  if(node->right != NULL && node->left != NULL)
  {
    return 2;
  }
  else
  if((node->right == NULL && node->left != NULL) || (node->right != NULL && node->left == NULL))
  {
    return 1;
  }
  else
  {
    return 0;
  }

}

//Function which deletes the node containing the given data
template <class datType>
void binaryTree<datType> ::deleteNode(datType data)
{
  Node<datType> *node = search(data);

  if(node == NULL)
  {
    cout<<"No such value in the tree "<<endl;
    return;
  }

  int noOfChildren = returnNoOfChildren(node);
  Node<datType> *successor;
  int valOfSuccessor;

  switch(noOfChildren)
  {
   case 0 :
     if(isLeftChild(node))
     {
       node->parent->left = NULL;
     }
     else
     {
       node->parent->right = NULL;
     }
    
    break;

   case 1:
     if(isLeftChild(node))
     {
       if(node->left != NULL)
	 node->parent->left = node->left;
       else
	 if(node->right != NULL)
	   node->parent->left = node->right;

     }
     else
     {
      if(node->left != NULL)
	 node->parent->right = node->left;
       else
	 if(node->right != NULL)
	   node->parent->right = node->right; 
     }
     break;
   
   case 2:
    //Yeah Baby case
    //int noOfChildrenSuccessor;
    //noOfChildrenSuccessor = returnNoOfChildren(getSucessor(node));
    successor = getSuccessor(node->data);
    valOfSuccessor = successor->data;
    deleteNode(successor->data);
    node->data = valOfSuccessor;
    break;
  
  default:
    cout<<"No way u can come here"<<endl;
    break;
  }
}

//Function which returns the predecessor of the node with the given data
template <class datType>
Node<datType>* binaryTree<datType> ::getPredecessor(datType data)
{
  Node<datType>* node = search(data);
  
  if(node == NULL)
  {
    cout<<"No such value in the tree "<<endl;
    return NULL;
  }
  
  if(node->left != NULL)
  {
    return returnRightMostFromCurrent(node->left);
  }
  else
  {
    Node<datType>* currentNode = node;
    
    while(!isRightChild(currentNode) && !isRoot(currentNode))
    {
      currentNode = currentNode->parent;
    } 

    return currentNode->parent;
  }

}

//Function which checks if the given node is root or not
template <class datType>
bool binaryTree<datType>::isRoot(Node<datType> *node)
{
  if(node->parent == NULL)
    return true;
  else
    return false;
}

//Function which returns the rightmost node from current 
template <class datType>
Node<datType>* binaryTree<datType>::returnLeftMostFromCurrent(Node<datType> *node)
{
  if(node->left != NULL)
  {
    return returnLeftMostFromCurrent(node->left);
  }
  else
  {
    return node;
  }
}

//Function which returns the leftmost node from current
template <class datType>
Node<datType>* binaryTree<datType> ::returnRightMostFromCurrent(Node<datType> *node)
{
  if(node->right != NULL)
  {
    return returnRightMostFromCurrent(node->right);
  }
  else
  {
    return node;
  }
}

//Function which gets the successor
template <class datType>
Node<datType>* binaryTree<datType> ::getSuccessor(datType data)
{
  //Get the node first
  Node<datType>* node = search(data);
  
  if(node == NULL)
  {
    cout<<"No such value in the tree "<<endl;
    return NULL;
  }

  if(node->right !=NULL)
  {
    return returnLeftMostFromCurrent(node->right);
  }
  else
  {
    Node<datType>* currentNode = node;
    
    while(!isLeftChild(currentNode) && !isRoot(currentNode))
    {
      currentNode = currentNode->parent;
    } 

    return currentNode->parent;
  }
}

//Function which checks whether the given child is a right child 
template <class datType>
bool binaryTree<datType> ::isRightChild(Node<datType>  *node)
{
  if(isRoot(node))
    return false;
  if(node->parent->right == node)
    return true;
  else
    return false;
}

//Function which checks whether the given child is a left child
template <class datType>
bool binaryTree<datType> ::isLeftChild(Node<datType>  *node)
{
  if(isRoot(node))
    return false;
  if(node->parent->left == node)
    return true;
  else
    return false;
}

//Function to print the max value in a tree
template <class datType>
void binaryTree<datType> ::  printMaxValue()
{
  if(root != NULL)
    goLeft(root);
  else
    cout<<"Oops Empty Tree "<<endl;
}

//Function to print the min value in a tree
template <class datType>
void binaryTree<datType> :: printMinValue()
{
  if(root != NULL)
    goRight(root);
  else
    cout<<"Oops Empty Tree "<<endl;
}

//Private Function which keeps going left until we reach the leaf
template <class datType>
void binaryTree<datType>::goLeft(Node<datType>  *left)
{
  if(left->left != NULL)
  {
    goLeft(left->left);
  }
  else
  {
    //We got the min value 
    cout<<"And the Min Value is : "<<left->data<<endl;
  }
}

//Private Function which keeps going right until we reach the rightmost leaf
template <class datType>
void binaryTree<datType>::goRight(Node<datType>  *right)
{
  if(right->right != NULL)
  {
    goRight(right->right);
  }
  else
  {
    //We got the max value 
    cout<<"And the Max Value is : "<<right->data<<endl;
  }
}

//Function to print out the values inorder
template <class datType>
void binaryTree<datType>::inorder(Node<datType>  *leaf)
{
  if(leaf != NULL)
  {
    inorder(leaf->left);
    cout<<leaf->data<<"\t";
    inorder(leaf->right);
  }
  
}

//Function to print out the values preorder
template <class datType>
void binaryTree <datType>::preorder(Node<datType>  *leaf)
{
  if(leaf != NULL)
  {
    cout<<leaf->data<<"\t";
    preorder(leaf->left);
    preorder(leaf->right);
  }

}

//Function to print out the values postorder
template <class datType>
void binaryTree<datType>::postorder(Node<datType>  *leaf)
{
  if(leaf != NULL)
  {
    postorder(leaf->left);
    postorder(leaf->right);
    cout<<leaf->data<<"\t";
  }
}

//Function for searching for a particular value in the tree
//Returns a pointer to the node containing the value
template <class datType>
Node<datType>*  binaryTree<datType>::search(datType data)
{
  if(root == NULL)
  {
    cout<<"Tree is Empty "<<endl;
    return NULL;
  }
  else
  {
    return search(data, root);
  }
}
 
//Private recursive function to go down a tree and find the given value
template <class datType>
Node<datType>* binaryTree<datType>::search(datType data, Node<datType> * lNode)
{
  if(data < lNode->data)
  {
    if(lNode->left == NULL)
    {
      //If the code comes here it means that we dont have that value in the tree
      cout<<"No Such value in the tree "<<endl;
      return NULL;
    }
    else
    {
      return search(data,lNode->left);
    }
  }
  else
  if(data > lNode->data)
  {
    if(lNode->right == NULL)
    {
      cout<<"No such value in the tree " << endl;
      return NULL;
    }
    else
    {
      return search(data,lNode->right);
    }
  }
  else
  {
    //Yeah we found the value 
    // cout<<"We found the value "<<endl;
    return lNode;
  }
    
}

//Function for inserting values into the tree
template <class datType>
void binaryTree<datType>:: insert(datType data)
{
  //Check if root is NULL or not
  if(root == NULL)
  {
    //Create the root
	root = new Node<datType>();
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
  }
  else
  {
    insert(data, root);
  }
  
  
}

//Private Function to recursively traverse the tree and insert the node at the appropriate spot
template <class datType>
void binaryTree<datType>::insert(datType data, Node<datType>  *leaf)
{
    if(data <= leaf->data)
    {
      if(leaf->left == NULL)
      {
	//Create a new node 
	leaf->left = new Node<datType>;
	leaf->left->left = NULL;
	leaf->left->right = NULL;
	leaf->left->parent = leaf;
	leaf->left->data = data;
      }
      else
      {
	//cout<<"Inserting to the left"<<endl;
	insert(data,leaf->left);
      }
    }
    else
    {
      if(leaf->right == NULL)
      {
	//Create a new node 
	leaf->right = new Node<datType>;
	leaf->right->left = NULL;
	leaf->right->right = NULL;
	leaf->right->parent = leaf;
	leaf->right->data = data;
      }
      else
      {
	//cout<<"Inserting to the right"<<endl;
	insert(data,leaf->right);
      }

    }
}

//Print the values of the tree at the time of the call
template <class datType>
void binaryTree<datType> :: printAllValues( TYPE_OF_TRAVERSAL type)
{
  cout<<"The type i am getting here is "<<type << endl;
  switch(type)
    {
      case 0 :
		cout<<"Inorder "<<endl;
		inorder(root);
		cout<<endl;
		break;

      case 2 :
		cout<<"Preorder "<<endl;
		preorder(root);
		cout<<endl;
		break;

      case 1 :
		cout<<"Postorder "<<endl;
		postorder(root);
		cout<<endl;
		break;

      default:
		cout<<"You shouldnt be here...Check your printAllValues function call "<<endl;
		break;
      }
}

