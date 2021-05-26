#include <fstream>
#include <iostream>
#include <string>
#include "list.h"
#include "BellmanFord.h"

using namespace std;

const int INF = 1e9;

int main()
{
	setlocale(LC_ALL, "rus");
	ifstream fin;
	fin.open("input.txt", ios::in);
	LinkedList<string>* list = new LinkedList<string>;

	citySearch(list, fin);

	fin.clear();
	fin.seekg(0);
	size_t n = list->get_size();

	int** adjacencyMatrix = new int* [n];
	for (int i = 0; i < n; i++) {
		adjacencyMatrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			adjacencyMatrix[i][j] = 0;
		}
	}

	matrixFilling(list, fin, adjacencyMatrix);

	int** shortestPathMatrix = new int* [n];
	for (int i = 0; i < n; i++) {
		shortestPathMatrix[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			shortestPathMatrix[i][j] = INF;
		}
	}

	list->print_to_console();
	cout << "Выберете город отправления: " << endl;
	int start;
	cin >> start;

	BellmanFordAlgorithm(adjacencyMatrix, shortestPathMatrix, n, start - 1);

	cout << "Выберете город прибития: " << endl;
	int end;
	cin >> end;
	cout << "Кратчайшее расстояние между " << list->at(start - 1)->data << " и " << list->at(end - 1)->data << " равно " << shortestPathMatrix[n - 1][end - 1] << endl;

	cout << endl << "Матрица кратчайших путей: " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (shortestPathMatrix[i][j] == INF) {
				cout << "IN" << " ";
			}
			else {
				cout << shortestPathMatrix[i][j] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}