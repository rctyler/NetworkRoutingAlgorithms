/*************************************************************************
 * Developer: Raymond Tyler
 * File: ShortestPathAlgorithm.cpp
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the implementation file for the ShortestPathAlgorithm 
 *				abstract class. It defines the constructor for the abstract class 
 *				that initializes both the Edge Heap,and Adjacency List
 *				representations of an undirected, weightedgraph that includes 
 *				edges, vertices, and cost
 *************************************************************************/

#include "ShortestPathAlgorithm.h"

ShortestPathAlgorithm::ShortestPathAlgorithm(int src, int dest, char const*inputFile)
{
	strcpy(InputFile, inputFile);
	
	source = src;
    destination = dest;
	
    //read from file
    ifstream file_in(inputFile);
	
	nV = 0;
	nE = 0;
	u = 0;
	v = 0;
    cost = 0;
	
	file_in >> nV >> nE;
	
	adjacencyList = new AdjacencyList(nV);
	edgeHeap = new EdgeHeap(nE);
	
    if (src < dest)
    {
    	for (int i = 1; i <= nE; i++)
    	{
            file_in >> u >> v >> cost;
			
            if (u < v)
				edgeHeap->minHeapInsert(cost, u, v);
			else if (u > v)
				edgeHeap->minHeapInsert(cost, v, u);
			
			adjacencyList->addVertex(u, v);
			adjacencyList->addVertex(v, u);
    	}
    }
    else if (src > dest)
    {
        for (int i = 1; i <= nE; i++)
        {
            file_in >> u >> v >> cost;
			
            if (u < v)
                edgeHeap->minHeapInsert(cost, v, u);
			else if (u > v)
                edgeHeap->minHeapInsert(cost, u, v);
			
			adjacencyList->addVertex(u, v);
			adjacencyList->addVertex(v, u);
        }
		
    }
    
    file_in.close();
}

bool ShortestPathAlgorithm::checkForNegativeEdges()
{
	int x, y, z;
	bool negEdgeFound = false;
	
    ifstream file_in(InputFile);
	file_in >> x >> y;
    if (source < destination)
    {
    	for (int i = 1; i <= nE; i++)
    	{
            file_in >> x >> y >> z;
            
            if (z < 0)
			{
				negEdgeFound = true;
			} 
		}
	}
	file_in.close();
	
	return negEdgeFound;
}
