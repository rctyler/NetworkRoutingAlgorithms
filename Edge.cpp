/*************************************************************************
 * Developer: Raymond Tyler
 * File: Edge.cpp
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the implementation file for the Edge class. An
 *				edge is a connection between two nodes in a graph.
 *************************************************************************/


#include "Edge.h"

Edge::Edge()
{
    this->cost = 0;
    this->u = 0;
    this->v = 0;
}

//set cost of edge
void Edge::setCost(int a)
{
    this->cost = a;
}

// set u value of edge
void Edge::setU(int a)
{
    this->u = a;
}

// set u value of edge
void Edge::setV(int a)
{
    this->v = a;
}

// set key value of edge
void Edge::setKey(int a)
{
    this->key = a;
}

// get the cost of the edge
int Edge::getCost()
{
    return this->cost;
}

// get the u value of the edge
int Edge::getU()
{
    return this->u;
}

//get the v value of the edge
int Edge::getV()
{
    return this->v;
}

// get the key value of the edge
int Edge::getKey()
{
    return this->key;
}
