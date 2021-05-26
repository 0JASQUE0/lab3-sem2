#include <fstream>
#include <iostream>
#include <string>
#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Прога 4 сем лабы\лаба 3\лаба 3\BellmanFord.h"
#include "D:\Прога 4 сем лабы\лаба 3\лаба 3\BellmanFord.cpp"

const int INF = 1e9;

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(citySearchTest)
		{
			ifstream fin;
			fin.open("D:\\Прога 4 сем лабы\\лаба 3\\UnitTest1\\test.txt", ios::in);
			LinkedList<string>* list = new LinkedList<string>;
			LinkedList<string>* test = new LinkedList<string>;
			citySearch(list, fin);
			test->push_back("Санкт-Петербург");
			test->push_back("Москва");
			test->push_back("Орел");

			for (size_t i = 0; i < list->get_size(); i++) {
				Assert::IsTrue(test->at(i)->data == list->at(i)->data);
			}
		}

		TEST_METHOD(matrixFillingTest)
		{
			ifstream fin;
			fin.open("D:\\Прога 4 сем лабы\\лаба 3\\UnitTest1\\test.txt", ios::in);
			LinkedList<string>* list = new LinkedList<string>;
			citySearch(list, fin);
			size_t n = list->get_size();
			int** adjacencyMatrix = new int* [n];
			for (size_t i = 0; i < n; i++) {
				adjacencyMatrix[i] = new int[n];
			}
			for (size_t i = 0; i < n; i++) {
				for (size_t j = 0; j < n; j++) {
					adjacencyMatrix[i][j] = 0;
				}
			}

			int checkMatrix[3][3] = { {0, 10, 0}, {20, 0, 40}, {0, 0, 0} };
			fin.clear();
			fin.seekg(0);
			matrixFilling(list, fin, adjacencyMatrix);

			for (size_t i = 0; i < n; i++) {
				for (size_t j = 0; j < n; j++) {
					Assert::IsTrue(adjacencyMatrix[i][j] == checkMatrix[i][j]);
				}
			}
		}

		TEST_METHOD(BellmanFordAlgorithmTest)
		{
			ifstream fin;
			fin.open("D:\\Прога 4 сем лабы\\лаба 3\\UnitTest1\\test.txt", ios::in);
			LinkedList<string>* list = new LinkedList<string>;
			citySearch(list, fin);
			size_t n = list->get_size();
			int** adjacencyMatrix = new int* [n];
			for (size_t i = 0; i < n; i++) {
				adjacencyMatrix[i] = new int[n];
			}
			for (size_t i = 0; i < n; i++) {
				for (size_t j = 0; j < n; j++) {
					adjacencyMatrix[i][j] = 0;
				}
			}
			fin.clear();
			fin.seekg(0);
			matrixFilling(list, fin, adjacencyMatrix);

			int** shortestPathMatrix = new int* [n];
			for (size_t i = 0; i < n; i++) {
				shortestPathMatrix[i] = new int[n];
			}
			for (size_t i = 0; i < n; i++) {
				for (size_t j = 0; j < n; j++) {
					shortestPathMatrix[i][j] = INF;
				}
			}

			BellmanFordAlgorithm(adjacencyMatrix, shortestPathMatrix, n, 0);

			Assert::IsTrue(shortestPathMatrix[n - 1][0] == 0);
			Assert::IsTrue(shortestPathMatrix[n - 1][1] == 10);
			Assert::IsTrue(shortestPathMatrix[n - 1][2] == 50);
		}
	};
}
