/*************************************************************************
 * Developer: Raymond Tyler
 * File: AdjacencyList.cpp
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the implementation file for the Adjacency List
 *				class. It converts a graph into its adjacency list form
 *************************************************************************/


#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(int nV)
{
    adjacencyDepth = nV;
    for (int i = 0; i < adjacencyDepth; i++)
		adjacencyList.push_back(vector<int>());
}

AdjacencyList::~AdjacencyList()
{
    delete &adjacencyList;
}

void AdjacencyList::addVertex(int x, int y)
{
    adjacencyList[x].push_back(y);
}

void AdjacencyList::removeLastVertexAt(int x)
{ 
    adjacencyList[x].pop_back();
}

int AdjacencyList::getLastVertexAt(int x)
{
    int last = adjacencyList[x].size() - 1;
    int a = adjacencyList[x][last];  
    removeLastVertexAt(x);
    return a;
}

vector<int> AdjacencyList::getListAt(int x)
{
    return adjacencyList[x];
}

void AdjacencyList::print()
{
    int memoryUsed = 0;
    cout << "Adjacency List:  ";
	
    for (int i = 1; i <= adjacencyDepth; i++)
        memoryUsed += (adjacencyList[i].size() * sizeof(int));
	
    for (int i = 1; i <= adjacencyDepth; i++)
    {
    	cout << "[" << i << "]";
		for (int j = 0; j < adjacencyList[i].size(); j++)
			cout << " --> " << adjacencyList[i][j];
        
        cout << endl; 
    }
}

