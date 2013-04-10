/*************************************************************************
 * Developer: Raymond Tyler
 * File: main.h
 * Date: April 10, 2013
 *************************************************************************
 * Description: This is the header file for main.
 *************************************************************************/


#ifndef MAIN_HEADERS
#define MAIN_HEADERS

#include <stdlib.h>
#include <fstream>
#include <cstdio>
#include "Edge.h"
#include "EdgeHeap.h"
#include "KruskalsAlgorithm.h"
#include "PrimsAlgorithm.h"
#include "BellmanFordsAlgorithm.h"
#include "DijkstrasAlgorithm.h"

using namespace std;

const char *_InputFile = "InputFiles/input.txt";

void printGoodbyeMessage();
int main(int argc, char** argv);

#endif
