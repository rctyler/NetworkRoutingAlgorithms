/*************************************************************************
 * Developer: Raymond Tyler
 * File: VertexHeap.cpp
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the implementation file for the VertexHeap class.
 *				This class sorts the vertexes of a graph into a heap
 *				structure
 *************************************************************************/

#include "VertexHeap.h"

// use this constructor to min heapify an unordered Vertex array
VertexHeap::VertexHeap(int nV)
{
    heapSize = 0;
    Vertices = new Vertex[nV + 1];
}

VertexHeap::~VertexHeap()
{
	delete [] Vertices;
}

// return parent
int VertexHeap::parent(int i)
{
    return i/2;
}

// return left child
int VertexHeap::left(int i)
{
    return (2 * i);
}

int VertexHeap::right(int i)
{
    return (2 * i) + 1;
	
}

// extract the minimum from the ordered min-heap array
Vertex VertexHeap::heapExtractMin()
{
    Vertex min = Vertices[1]; 
	
    Vertices[1] = Vertices[heapSize];
    heapSize = heapSize - 1;
    minHeapify(1);
	
    return min;
}

// fix heap after inserting a new node
void VertexHeap::heapDecreaseKey(int i)
{
    Vertex temp;
    while (i > 1 && Vertices[parent(i)].getKey() > Vertices[i].getKey())
    {
        temp = Vertices[i]; 
        Vertices[i] = Vertices[parent(i)];
        Vertices[parent(i)] = temp;
        i = parent(i);
    }
}

// insert a new node into heap
void VertexHeap::minHeapInsert(int reference, int key, int parent)
{
    heapSize = heapSize + 1;
    Vertices[heapSize].setReference(reference);
    Vertices[heapSize].setKey(key);
    Vertices[heapSize].setParent(parent);
    heapDecreaseKey(heapSize);
}

// heapify the minheap
void VertexHeap::minHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest;
	
    if (l <= heapSize && Vertices[l].getKey() < Vertices[i].getKey())
        smallest = l;
    else
        smallest = i;
	
    if (r <= heapSize && Vertices[r].getKey() < Vertices[smallest].getKey())
        smallest = r;
	
    if (smallest != i && smallest <= heapSize)
    {
        Vertex temp = Vertices[i];
        Vertices[i] = Vertices[smallest];
        Vertices[smallest] = temp;
        minHeapify(smallest);
    }
}

Vertex VertexHeap::getVertex(int a)
{
	return Vertices[a];
}

int VertexHeap::length()
{
    return heapSize;
}

// print the Vertex array
void VertexHeap::print()
{
    cout << "Priority Queue:" << endl;
    for(int i = 1; i <= heapSize; i++)
        cout << Vertices[i].getReference() << " ";
    cout << endl;
}

// print the overall network layout
void VertexHeap::printNetworkOverview()
{
    for(int i = 1; i <= heapSize; i++)
        cout << Vertices[i].getReference() << "[" << Vertices[i].getParent() << "] ";
    cout << endl;
}
