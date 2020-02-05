#pragma once
#include "linkedList.h"

template<class datType>
struct GraphNode
{
	int idx;
	datType data;
	List<int> adjacentNodes;
	
	GraphNode()
	{

	}

	GraphNode(datType inData)
	{
		data = inData;
	}
};

template<class datType>
class Graph
{

public:
	Graph();
	Graph(int size);
	void UpdateVertexData(int id, datType data);
	void AddEdge(int sIdx, int eIdx);
	void Print();
private:
	int size;
	GraphNode<datType>* Nodes;

};