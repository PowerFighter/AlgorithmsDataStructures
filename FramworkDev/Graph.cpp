#include "Graph.h"
#include <iostream>

template<class datType>
Graph<datType>::Graph(int size)
{
	//Initialize graph size to zero
	Nodes = new GraphNode<datType>[size];
	this->size = size;
}

template<class datType>
Graph<datType>::Graph()
{
	//Initialize graph size to zero
	//Nodes = new Graph<datType>[size];
}

template<class datType>
void Graph<datType>::UpdateVertexData(int id, datType data)
{
	if (id >= size)
	{
		std::cout << "No nodes with id : " << id << endl;
		return;
	}

	Nodes[id].data = data;
}

template<class datType>
void Graph<datType>::AddEdge(int sIdx, int eIdx)
{
	//Check if sIdx and eIdx exist before adding to the linked list
	if (sIdx >= size)
	{
		std::cout << "Invalid sIdx : " << sIdx << " since Graph size is : " << size << endl;
		return;
	}

	if (eIdx >= size)
	{
		std::cout << "Invalid eIdx : " << eIdx << " since Graph size is : " << size << endl;
		return;
	}

	//Loop through all the adjacent nodes and find out if eIdx exists

	if(!Nodes[sIdx].adjacentNodes.Find(eIdx))
		Nodes[sIdx].adjacentNodes.appendToHead(eIdx);
}

template<class datType>
void Graph<datType>::Print()
{
	for (int i = 0; i < size; i++)
	{
		cout << "Node " << i ;

		if (!Nodes[i].adjacentNodes.IsEmpty())
		{
			cout << " : ";
			Nodes[i].adjacentNodes.printList();
		}
		else
		{
			cout << endl;
		}
	}
}

template<class datType>
GraphNode<datType>* Graph<datType>::GetArray()
{
	return Nodes;
}