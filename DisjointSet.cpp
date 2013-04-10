/*************************************************************************
 * Developer: Raymond Tyler
 * File: DisjointSet.cpp
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the implementation file for the DisjointSet class.
 *************************************************************************/

#include "DisjointSet.h"

// use this constructor to initialize the disjoint set and perform make-set on each element in it
disjointSet::disjointSet(int nV)
{
    DisjointSet = new int[nV + 1];
    len = nV;
    for (int i = 1; i <= nV; i ++)
        MakeSet(i);
}

// this is the destructor for the Disjoint Set class
disjointSet::~disjointSet()
{
    delete [] DisjointSet;
}

// perform MakeSet on given array index
void disjointSet::MakeSet(int x)
{
    DisjointSet[x] = 0;
}

// Union two representatives of the disjoint set together with Path compression
void disjointSet::Union_withPathCompression(int x, int y)
{
    Link(FindSet_withPathCompression(x), FindSet_withPathCompression(y));
}

// Union two representatives of the disjoint set together without Path Compression
void disjointSet::Union_withoutPathCompression(int x, int y)
{
    Link(FindSet_withoutPathCompression(x), FindSet_withoutPathCompression(y));
}

// Find the representative of an element in the disjoint set using path compression
int disjointSet::FindSet_withPathCompression(int x)
{
    if (DisjointSet[x] <= 0)
        return x;
    else
    {
        DisjointSet[x] = FindSet_withPathCompression(DisjointSet[x]);
        return DisjointSet[x];
    }
}

// Find the representative of an element in the disjoint set using path compression
int disjointSet::FindSet_withoutPathCompression(int x)
{
    if (DisjointSet[x] <= 0)
        return x;
    else
        return FindSet_withoutPathCompression(DisjointSet[x]);
}

// Link two elements of the disjoint set together
void disjointSet::Link(int x, int y)
{
    if (-DisjointSet[x] > -DisjointSet[y])
        DisjointSet[y] = x;
    else
    {
        if (-DisjointSet[x] == -DisjointSet[y])
            DisjointSet[y] = DisjointSet[y] - 1;
        DisjointSet[x] = y;
    }
}

//print out the disjoint set array
void disjointSet::printSet()
{
    cout << "Disjoint Set Structure: " <<  endl;
    for (int i = 1; i <= len; i++)
		cout << DisjointSet[i] << " ";
	
    cout << endl;
}

