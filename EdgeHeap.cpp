/*************************************************************************
 * Developer: Raymond Tyler
 * File: EdgeHeap.cpp
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the implementation file for the EdgeHeap class.
 *				Basically, this creates a sorted heap structure to contain
 *				the edges of a graph
 *************************************************************************/


#include "EdgeHeap.h"

// use this constructor to min heapify an unordered Edge array
EdgeHeap::EdgeHeap(int numEdges)
{
    nE = numEdges;
    heapSize = 0;
    Edges = new Edge[nE + 1];
}

EdgeHeap::~EdgeHeap()
{
    delete [] Edges;
}

// return parent
int EdgeHeap::parent(int i)
{
    return i/2;
}

// return left child
int EdgeHeap::left(int i)
{
    return (2 * i);
}

// return right child
int EdgeHeap::right(int i)
{ 
	return (2 * i) + 1;
}

// extract the minimum from the ordered min-heap array
Edge EdgeHeap::heapExtractMin()
{
    Edge min = Edges[1]; 
	
    Edges[1] = Edges[heapSize];
    heapSize = heapSize - 1;
    minHeapify(1);
	
    return min;
}

// fix heap after inserting a new node
void EdgeHeap::heapDecreaseKey(int i)
{
    Edge temp;
    while (i > 1 && Edges[parent(i)].getCost() > Edges[i].getCost())
    {
        temp = Edges[i]; 
        Edges[i] = Edges[parent(i)];
        Edges[parent(i)] = temp;
        i = parent(i);
    }
}

// insert a new node into heap
void EdgeHeap::minHeapInsert(int cost, int u, int v)
{
    heapSize = heapSize + 1;
    Edges[heapSize].setU(u);
    Edges[heapSize].setV(v);
    Edges[heapSize].setCost(cost);
    heapDecreaseKey(heapSize);
}

// heapify the minheap
void EdgeHeap::minHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest;
	
    if (l <= heapSize && Edges[l].getCost() < Edges[i].getCost())
        smallest = l;
    else
        smallest = i;
	
    if (r <= heapSize && Edges[r].getCost() < Edges[smallest].getCost())
        smallest = r;
	
    if (smallest != i && smallest <= heapSize)
    {
        Edge temp = Edges[i];
        Edges[i] = Edges[smallest];
        Edges[smallest] = temp;
        minHeapify(smallest);
    }
}

// find the cost of the link which connects the two specified nodes
int EdgeHeap::findCost(int u, int v)
{
    int a = 1234567;
    for (int i = 1; i <= nE; i++)
    {
        if (((Edges[i].getU() == u) && (Edges[i].getV() == v)) || ((Edges[i].getU() == v) && (Edges[i].getV() == u)))
			a = Edges[i].getCost();
    }
	
    return a;
}

Edge *EdgeHeap::getEdges()
{
    return Edges;
}

Edge EdgeHeap::findEdge(int u, int v)
{
	Edge noEdgeFound;
	
    for (int i = 1; i <= nE; i++)
    {
        if ((Edges[i].getU() == u) && (Edges[i].getV() == v))
			return Edges[i];
    }
	
	return noEdgeFound;
} 

// print the Edge array
void EdgeHeap::print()
{
    cout << "Heap Structure:" << endl;
    for(int i = 1; i <= heapSize; i++)
        cout << Edges[i].getCost() << " ";
    cout << endl;
}

// print the overall network layout
void EdgeHeap::printOverview()
{
    for(int i = 1; i <= heapSize; i++)
        cout << Edges[i].getCost() << "[" << Edges[i].getU()<< ", " << Edges[i].getV() << "] ";
    cout << endl;
}
