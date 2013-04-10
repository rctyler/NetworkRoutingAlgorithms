/*************************************************************************
 * Developer: Raymond Tyler
 * File: Vertex.cpp
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the implementation file for the Vertex class. A 
 *				Vertex is a node in a graph
 *************************************************************************/


#include "Vertex.h"

Vertex::Vertex()
{
    reference = 0;
    key = 1234567;
    parent = 0;
}

int Vertex::getParent()
{
    return this->parent;
}

int Vertex::getKey()
{
    return this->key;
}

int Vertex::getReference()
{
    return this->reference;
}

void Vertex::setParent(int a)
{
    this->parent = a;
}

void Vertex::setKey(int a)
{
    this->key = a;
}

void Vertex::setReference(int a)
{
    this->reference = a;
}