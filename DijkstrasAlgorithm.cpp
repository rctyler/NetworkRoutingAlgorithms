/*************************************************************************
 * Developer: Raymond Tyler
 * File: AdjacencyList.cpp
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the implementation file for the DijkstrasAlgorithm
 *				class. Dijkstra's algorithm is one way to find the
 *				shortest path over a graph
 *************************************************************************/

#include "DijkstrasAlgorithm.h"

DijkstrasAlgorithm::DijkstrasAlgorithm(int src, int dest, char const*inputFile)
	: ShortestPathAlgorithm(src, dest, inputFile)
{
	nodesProcessedIndex = 0;
	
    queue = new VertexHeap(nV);
    referenceArray = new Vertex[nV + 1];
    S = new int[nV];  
	
	if (checkForNegativeEdges() == true)
	{
		cout << "Cannot use Dijkstra's Algorithm for this network setup. Please make sure that" << endl;
		cout << "the network contains no links with negative costs." << endl << endl << endl;
		throw(1);
	} 

    for (int i = 1; i <= nV; i++)
    {
        referenceArray[i].setReference(i);
        referenceArray[i].setKey(1234567);
        referenceArray[i].setParent(0);
    }
}

DijkstrasAlgorithm::~DijkstrasAlgorithm()
{
    delete queue;
    delete [] referenceArray;
    delete [] S;
}

inline void DijkstrasAlgorithm::initializeSingleSource()
{
    queue->minHeapInsert(source, 0, 0);
    referenceArray[source].setKey(0);
}

void DijkstrasAlgorithm::relax(Vertex u, Vertex v, int w)
{
    if (v.getKey() > u.getKey() + w)
    {
		queue->minHeapInsert(v.getReference(), u.getKey() + w, u.getReference());
        referenceArray[v.getReference()].setKey(u.getKey() + w);
		referenceArray[v.getReference()].setParent(u.getReference());
    }
}

bool DijkstrasAlgorithm::findShortestPath()
{
    Vertex u;
    int v;
    int loopIndex = 1;
    char choice;
    bool jumpToEnd = false;
    bool nodeAlreadyProcessedFlag = false;
	
    initializeSingleSource();
	
    cout << "Dijkstra's Algorithm Initial Data Structures" << endl;
    cout << "-------------------------------" << endl;
    print();
    cout << "-------------------------------" << endl << endl << endl;
	
    while (queue->length() != 0)
    {
        nodeAlreadyProcessedFlag = false;
		u = queue->heapExtractMin();
        
        for (int i = 0; i < nodesProcessedIndex; i++)
        {
			if (S[i] == u.getReference())
			{
				nodeAlreadyProcessedFlag = true;
                break;
			}
			else 
				nodeAlreadyProcessedFlag = false;
        }
		
        if (nodeAlreadyProcessedFlag != true)  
		{	
			S[nodesProcessedIndex] = u.getReference();
			nodesProcessedIndex++;
        }
		
        while (adjacencyList->getListAt(u.getReference()).empty() != true)
		{
			v = adjacencyList->getLastVertexAt(u.getReference());
			relax(u, referenceArray[v], edgeHeap->findCost(u.getReference(), v));
			
			if (jumpToEnd == false)
       	    {
			choice1:
				cout << "(N)ext Iteration OR (G)o to the end of this Algorithm?  ";
				cin >> choice;
				cout << endl;
				
				if (choice == 'N' or choice == 'n')
             	    jumpToEnd = false;
				else if (choice == 'G' or choice == 'g')
				{
					jumpToEnd = true;
				}
				else
                {
                    cout << "Please type either N or G." << endl << endl;
                    goto choice1;
                }
			}	    
			
			if (jumpToEnd != true)
			{
				cout << "Dijkstra's Algorithm Iteration " << loopIndex << endl;
				cout << "-------------------------------" << endl;
				print();
				cout << "-------------------------------" << endl << endl << endl;
				
			}
			
			loopIndex++;
		}
    }
	printf("[%d]\n", nodesProcessedIndex);
	/*
    if (jumpToEnd == false)
    {
	choice2:
		cout << "(N)ext Iteration OR (G)o to the end of this Algorithm?  ";
        cin >> choice;
		cout << endl;
		
       	if (choice == 'N' or choice == 'n')
       	    jumpToEnd = false;
       	else if (choice == 'G' or choice == 'g')
            jumpToEnd = true;
		else
        {
            cout << "Please type either N or G." << endl << endl;
            goto choice2;
        }
    }*/
	
    cout << "Dijkstra's Algorithm Iteration " << loopIndex << endl;
    cout << "-------------------------------" << endl;
    print();
    cout << "-------------------------------" << endl << endl << endl; 
	
    printShortestPath();
	
	return true;
}

void DijkstrasAlgorithm::print()
{
    cout << "Nodes Processed:" << endl;   
    for (int i = 0; i < nodesProcessedIndex; i++)
    	cout << S[i] << " ";
    cout << endl << endl;
	
    queue->print();
	
    cout << endl;
	
    adjacencyList->print();
	
    cout << endl;
	
    cout << "Network Vertices:" << endl;
    for (int i = 1; i <= nV; i++)
    {
        if (referenceArray[i].getKey() == 1234567)
		{
            cout << i << ": \u03C0 = " << referenceArray[i].getParent();
			cout << ",  (" << source << ") --> (" << i << ") distance = \u221E" << endl;
        }
        else
        {
			cout << i << ": \u03C0 = " << referenceArray[i].getParent();
			cout << ",  (" << source << ") --> (" << i << ") distance = " << referenceArray[i].getKey() << endl;
        }
    }
}

void DijkstrasAlgorithm::printShortestPath()
{
    int i = 1;
    int parent = destination;
    int *shortestPathArray = new int[nV + 1];
	
    cout << "Shortest Path from Client Node " << source << " to Server Node " << destination << endl << endl;
	
    while (parent != 0) {
    	shortestPathArray[i] = parent;
        parent = referenceArray[parent].getParent();
        i++;
    }
	
    for (int j = i - 1; j > 1; j--)
        cout << shortestPathArray[j] << " --> ";
    cout << destination << endl << endl << endl;
}
