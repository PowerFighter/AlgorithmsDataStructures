#include "Graph.h"

template<class datType>
Graph<datType>::Graph()
{

}

template<class datType>
void AddVertex(int id, datType data)
{
	linkedList.appendToHead(data);
}