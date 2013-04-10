/*************************************************************************
 * Developer: Raymond Tyler
 * File: PrimsAlgorithm.cpp
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the implementation file for the Prims Algorithm 
 *				class. It finds the minimum spanning tree for a graph
 *************************************************************************/

#include "PrimsAlgorithm.h"

PrimsAlgorithm::PrimsAlgorithm(char const*inputFile)
{
    //read from file
    ifstream file_in(inputFile);
	
    this->closedIndex = 0; 
	this->nE = 0;
	this->nV = 0;
	this->u = 0;
	this->v = 0;
	this->cost = 0; 
	this->key = 0;
	
    file_in >> nV >> nE;
	
    queue = new VertexHeap(nV+1);
    referenceArray = new Vertex[nV+1];
    adjacencyList = new AdjacencyList(nV);
    edgeHeap = new EdgeHeap(nE);
    MSTedges = new EdgeHeap(nE);
    closedList = new int[nV + 1];
	
    for (int i = 1; i <= nE; i++)
    {
        file_in >> u >> v >> cost;
		edgeHeap->minHeapInsert(cost, u, v);
		adjacencyList->addVertex(u, v);
		adjacencyList->addVertex(v, u);
    }
    
    for (int i = 1; i <= nV; i++)
    {
        referenceArray[i].setReference(i);
        referenceArray[i].setKey(1234567);
        referenceArray[i].setParent(0);
    }
	
    queue->minHeapInsert(1, 0, 0);
    referenceArray[1].setKey(0);
	
    file_in.close();
}

PrimsAlgorithm::~PrimsAlgorithm()
{
    delete queue;
    delete [] referenceArray;
    delete edgeHeap;
    delete MSTedges;
    delete [] closedList;
}

void PrimsAlgorithm::findMinimumSpanningTree()
{
    bool nodeAlreadyProcessedFlag = false;
    int loopIndex = 1;
    int i = 0;
    int v = 0;
    int a = 0;
    int w = 0;
	
    cout << "Prim's Algorithm Initial Data Structures " << endl;
    cout << "-------------------------------" << endl;
    print();
    cout << "-------------------------------" << endl << endl << endl;
	
    char choice;
    bool jumpToEnd = false;
	
	
    while (queue->length() != 0)
    {
		nodeAlreadyProcessedFlag = false;
		Vertex u = queue->heapExtractMin();
		
        for (int i = 0; i <= closedIndex; i++)
        {
			if (closedList[i] == u.getReference())
			{
                nodeAlreadyProcessedFlag = true;
                break;
			}
			else
                nodeAlreadyProcessedFlag = false;
        }
		
        if (nodeAlreadyProcessedFlag == false)
			closedList[++closedIndex] = u.getReference();
		else
		{
			
			if (jumpToEnd == false)
       	    {
				cout << "(N)ext Iteration OR (G)o to the end of this Algorithm?  ";
				cin >> choice;
				cout << endl << endl;
				
				if (choice == 'N' or choice == 'n')
             	    jumpToEnd = false;
				else if (choice == 'G' or choice == 'g')
					jumpToEnd = true;
			}
			cout << "-------------------------------" << endl;
			cout << "Prim's Algorithm Iteration " << loopIndex++ << endl;
			cout << "-------------------------------" << endl;
			print();
			cout << "-------------------------------" << endl << endl << endl;     
		}
		
		while (adjacencyList->getListAt(u.getReference()).empty() != true)
		{ 
			if (jumpToEnd == false)
			{
			choice:
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
                    goto choice;
                }
       	    }
			
			a = adjacencyList->getLastVertexAt(u.getReference());
			
			Vertex v = referenceArray[a];
			w = edgeHeap->findCost(u.getReference(), a);
			
			for (int i = 0; i <= closedIndex; i++)
			{
				if (a == closedList[i])
				{
					nodeAlreadyProcessedFlag = true;
					break;
				}
				else
					nodeAlreadyProcessedFlag = false;
			}
			
			if ((w < v.getKey()) && (nodeAlreadyProcessedFlag == false))
			{
				queue->minHeapInsert(a, w, u.getReference());
				referenceArray[a].setKey(w);
				referenceArray[a].setParent(u.getReference());
			}
			
            cout << "Prim's Algorithm Iteration " << loopIndex++ << endl; 
			cout << "-------------------------------" << endl;
            print();
			cout << "-------------------------------" << endl << endl << endl;
		}
    }
	
    computeMST();
    printMST();
}

void PrimsAlgorithm::computeMST()
{
    bool StartNodeFlag = false;
    int c = 0;
	
    for (int i = 1; i <= nV; i++)
    {
        if (referenceArray[i].getParent() == 0)
            StartNodeFlag = true;
        else
            StartNodeFlag = false;
		
        if (StartNodeFlag == false)
        {
            c = edgeHeap->findCost(i, referenceArray[i].getParent());
            MSTedges->minHeapInsert(c, i, referenceArray[i].getParent());
        }
    }
	
}

void PrimsAlgorithm::print()
{
	cout << "Nodes Processed:" << endl;
	for (int i = 1; i <= closedIndex; i++)
		cout << closedList[i] << " ";
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
			cout << ",  key = \u221E" << endl;
		}
		else
		{
			cout << i << ": \u03C0 = " << referenceArray[i].getParent();
			cout << ",  key = " << referenceArray[i].getKey() << endl;
		}
	}
}

void PrimsAlgorithm::printMST()
{
	cout << "Minumum Spanning Tree:" << endl;
	MSTedges->printOverview();
	cout << endl << endl;
}

