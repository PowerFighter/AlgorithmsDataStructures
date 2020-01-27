#pragma once
#include "linkedList.h"

template<class datType>
struct GraphNode
{
	int idx;
	datType data;
	List<GraphNode<datType>> adjacentNodes;
	
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
	void AddVertex(int id, datType data);

private:
	int size;
	List<GraphNode<datType>> linkedList;
};