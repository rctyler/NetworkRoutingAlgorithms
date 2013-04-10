/*************************************************************************
 * Developer: Raymond Tyler
 * File: BellmanFordsAlgorithm.cpp
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the implementation file for the Bellman Fords
 *				Algorithm class. This algorithm is one way to find a 
 *				shortest path through a graph
 *************************************************************************/

#include "BellmanFordsAlgorithm.h"

BellmanFordsAlgorithm::BellmanFordsAlgorithm(int s, int d, char const*inputFile)
{
    source = s;
    destination = d;
	
    //read from file
    ifstream file_in(inputFile);
	
    int cost, key = 0;
	
    file_in >> nV >> nE;
	
    Vertices = new Vertex[nV + 1];
    edgeHeap = new EdgeHeap(nE);
    shortestPathArray = new int[nV];
	
    if (s < d)
    {
    	for (int i = 1; i <= nE; i++)
    	{
            file_in >> u >> v >> cost;
			
            if (u < v)
				edgeHeap->minHeapInsert(cost, u, v);
			else if (u > v)
				edgeHeap->minHeapInsert(cost, v, u);
    	}
    }
    else if (s > d)
    {
        for (int i = 1; i <= nE; i++)
        {
            file_in >> u >> v >> cost;
			
            if (u < v)
                edgeHeap->minHeapInsert(cost, v, u);
			else if (u > v)
                edgeHeap->minHeapInsert(cost, u, v);
        }
		
    }
    
    file_in.close();
}

BellmanFordsAlgorithm::~BellmanFordsAlgorithm()
{
    delete edgeHeap;
    delete [] Vertices;
    delete [] shortestPathArray;
}

void BellmanFordsAlgorithm::initializeSingleSource()
{
    for (int i = 1; i<= nV; i++)
    {
    	Vertices[i].setKey(1234567);
		Vertices[i].setParent(0);
    }
    
    Vertices[source].setKey(0);
}

bool BellmanFordsAlgorithm::findShortestPath()
{
    char choice;
    bool jumpToEnd = false;
	
    initializeSingleSource();
	
    for (int i = 0; i <= nV; i++)
    {  
        if (i == 0)
		{
			cout << "Bellman Ford's Algorithm Initial Data Structures" << endl;
            cout << "-------------------------------" << endl; 
        }
        else
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
			
			cout << "Bellman Ford's Algorithm Iteration " << i << endl;
            cout << "-------------------------------" << endl;
        }
		
		for (int j = 1; j <= nE; j++)
		{
			a = (edgeHeap->getEdges())[j].getU();
			b = (edgeHeap->getEdges())[j].getV();
            v = Vertices[(edgeHeap->getEdges())[j].getV()].getKey();
            u = Vertices[(edgeHeap->getEdges())[j].getU()].getKey();
            w = (edgeHeap->getEdges())[j].getCost();
            
            if (j != 1)
                cout << endl << endl;  
			
			print();
		}
		
        cout << endl << endl << endl;
		cout << "Network Vertices:";
		for (int k = 1; k <= nV; k++) 
			cout << endl << k << ": \u03C0 = " << Vertices[k].getParent();
		
		cout << "\n-------------------------------" << endl << endl << endl;
		
        for (int j = 1; j <= nE; j++)
		{
			a = (edgeHeap->getEdges())[j].getU();
			b = (edgeHeap->getEdges())[j].getV();
            v = Vertices[(edgeHeap->getEdges())[j].getV()].getKey();
            u = Vertices[(edgeHeap->getEdges())[j].getU()].getKey();
            w = (edgeHeap->getEdges())[j].getCost();
			
            relax(j, u, v, w);
        }
    }
	
    printShortestPath();
	
    for (int i = 1 - 1; i <= nE; i++)
    {
        v = Vertices[(edgeHeap->getEdges())[i].getV()].getKey();
        u = Vertices[(edgeHeap->getEdges())[i].getU()].getKey();
        w = (edgeHeap->getEdges())[i].getCost(); 
		
    	if (v > u + w)
    	    return false;    
    }
	
    return true;
}

void BellmanFordsAlgorithm::relax(int i, int u, int v, int w)
{
    a = (edgeHeap->getEdges())[i].getV();
    b = (edgeHeap->getEdges())[i].getU();
    int c = (edgeHeap->getEdges())[i].getCost();
	
    if ((v > u + w) && (u != 1234567))
    {
		Vertices[a].setKey(u + w);
        Vertices[a].setParent(b);
    }
}

void BellmanFordsAlgorithm::print()
{
    cout << "Edge: " << w;
    cout << "[" << a;
    cout << ", "  << b << "]" << endl;
	
    if ((u != 1234567) && (v != 1234567))
    {
		cout << "u: (" << source << ") --> (" << a << ") distance = " << u << ",  ";
        cout << "v: (" << source << ") --> (" << b << ") distance = " << v;
    }
    else if ((u == 1234567) && (v != 1234567))
    {
        cout << "u: (" << source << ") --> (" << a << ") distance = " << "\u221E" << ",  ";
        cout << "v: (" << source << ") --> (" << b << ") distance = " << v;
    }
    else if ((u != 1234567) && (v == 1234567))
    {
        cout << "u: (" << source << ") --> (" << a << ") distance = " << u << ",  ";
        cout << "v: (" << source << ") --> (" << b << ") distance = " << "\u221E";
    }
    else
    {
        cout << "u: (" << source << ") --> (" << a << ") distance = " << "\u221E" << ",  ";
      	cout << "v: (" << source << ") --> (" << b << ") distance = " << "\u221E";
    }
}

void BellmanFordsAlgorithm::printShortestPath()
{
    int parent = destination;
    int i = 0;
	
    cout << "Shortest Path from Client Node " << source;
    cout << " to Server Node " << destination << ": " << endl;
    while (parent != 0)
    {
        parent = Vertices[parent].getParent();
        shortestPathArray[i] = parent;
        i++;
    }
    for (int j = i - 2; j >= 0; j--)
        cout << shortestPathArray[j] << " --> ";
    cout << destination << endl << endl << endl;
}

