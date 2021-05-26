#pragma once
#include "list.h"

void citySearch(LinkedList<string>* listOfCities, ifstream& fin);
void matrixFilling(LinkedList<string>* listOfCities, ifstream& fin, int** adjacencyMatrix);
void BellmanFordAlgorithm(int** adjacencyMatrix, int** shortestPathMatrix, int n, int start);