#include <iostream>
#include <fstream>
#include "list.h"
#include <string>
#include "BellmanFord.h"

using namespace std;

void citySearch(LinkedList<string>* listOfCities, ifstream& fin) {
	string str;
	string tempStr;
	int counter, index;
	while (!fin.eof()) {
		getline(fin, str);
		counter = 0;
		for (size_t i = 0; i < str.size(); i++) {
			tempStr = "";
			while (str[i] != ';' && i != str.size()) {
				tempStr += str[i++];
			}
			index = listOfCities->find(tempStr);
			if (index == -1) {
				listOfCities->push_back(tempStr);
			}
			counter++;
			if (counter == 2) {
				break;
			}
		}
	}
}

void matrixFilling(LinkedList<string>* listOfCities, ifstream& fin, int** adjacencyMatrix)
{
	string str;
	string tempStr;
	int indexI, indexJ;
	int counter;
	while (!fin.eof()) {
		getline(fin, str);
		counter = 0;
		for (size_t i = 0; i < str.size(); i++) {
			tempStr = "";
			while (str[i] != ';' && i != str.size()) {
				tempStr += str[i++];
			}
			if (counter == 0) {
				indexI = listOfCities->find(tempStr);
			}
			if (counter == 1) {
				indexJ = listOfCities->find(tempStr);
			}
			if (counter == 2 && tempStr != "N/A") {
				adjacencyMatrix[indexI][indexJ] = atoi(tempStr.c_str());
			}
			if (counter == 3 && tempStr != "N/A") {
				adjacencyMatrix[indexJ][indexI] = atoi(tempStr.c_str());
			}
			counter++;
		}
	}
}

void BellmanFordAlgorithm(int** adjacencyMatrix, int** shortestPathMatrix, int n, int start)
{
	for (int i = 0; i < n; i++) {
		shortestPathMatrix[i][start] = 0;
	}
	for (int k = 1; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (shortestPathMatrix[k-1][j] + adjacencyMatrix[j][i] < shortestPathMatrix[k][i] && adjacencyMatrix[j][i] != 0) {
					shortestPathMatrix[k][i] = shortestPathMatrix[k-1][j] + adjacencyMatrix[j][i];
				}
			}
		}
	}
}