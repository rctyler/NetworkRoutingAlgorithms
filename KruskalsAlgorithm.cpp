#include "KruskalsAlgorithm.h"

KruskalsAlgorithm::KruskalsAlgorithm(char const*inputFile)
{
    //read from file
    ifstream file_in(inputFile);
	
    int u, v, cost = 0;     
    file_in >> nV >> nE;
	
    edgeHeap = new EdgeHeap(nE); 
	
    for (int i = 1; i <= nE; i++)
    {
        file_in >> u >> v >> cost;
		edgeHeap->minHeapInsert(cost, u, v);
    }   
	
    MSTindex = 0;
	
    //initialize disjointSet array
    DisjointS = new disjointSet(nV);
	
    MSTedges = new Edge[nE];
	
    file_in.close();
}

KruskalsAlgorithm::~KruskalsAlgorithm()
{
    delete edgeHeap;
    delete [] MSTedges;
    delete DisjointS;
}

void KruskalsAlgorithm::findMinimumSpanningTree()
{  
    cout << "Kruskal's Algorithm Initial Data Structures" << endl << "-------------------------------" << endl;
    print();
    cout << "-------------------------------" << endl << endl << endl;
	
    char choice;
    bool jumpToEnd = false;
	
    for (int i = 1; i <= nE; i++)
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
		
		// extract minimum from the Edge arry
		Edge w = edgeHeap->heapExtractMin();
		
		//Find representative of u and v from each edge and Union them together
		if (DisjointS->FindSet_withoutPathCompression(w.getU()) != DisjointS->FindSet_withoutPathCompression(w.getV()))
		{
			MSTedges[MSTindex] = w; 
			MSTindex ++;
			DisjointS->Union_withoutPathCompression(w.getU(), w.getV());
		}
		
		cout << "Kruskal's Algorithm Iteration " << i << endl << "-------------------------------" << endl;
		print();
		cout << "-------------------------------" << endl << endl << endl;
	}
}

void KruskalsAlgorithm::print()
{
    edgeHeap->print();
    cout << endl;
    DisjointS->printSet();
}

void KruskalsAlgorithm::printMST()
{
    cout << "Minumum Spanning Tree:" << endl;
    for (int i = 0; i < MSTindex; i++)
    {
		cout << MSTedges[i].getCost() << "[" << MSTedges[i].getU() << ", " << MSTedges[i].getV() << "] ";
    }
    cout << endl << endl << endl;   
}
