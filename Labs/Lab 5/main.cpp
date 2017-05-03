#pragma once
#include <iostream>
using namespace std;

// Declarations
// Define the total number of vertices - 8
#define INFINITY 9999
#define MAX 8
void dijkstra(int matrix[MAX][MAX], int vertices, int start);


int main() {

	/*
	Each node has a collumn for the other nodes -> 8 x 8 2d array

		   A | B | C | D | E | F | G | H |
		A| * | 6 | - | 8 | 4 | - | - | - |
		B| 6 | * | 6 | - | 2 | 4 | - | 1 |
		C| - | 6 | * | - | - | - | 3 | - |
		D| 8 | - | - | * | - | - | 7 | - |
		E| 4 | 2 | - | - | * | - | - | - |
		F| - | 4 | - | - | - | * | 5 | 3 |
		G| - | - | 3 | 7 | - | 5 | * | - |
		H| - | 1 | - | - | - | 3 | - | * |
	*/
	int adjacencyMatrix[8][8] = {
		{0, 6, 0, 8, 4, 0, 0, 0},
		{6, 0, 6, 0, 2, 4, 0, 1},
		{0, 6, 0, 0, 0, 0, 3, 0},
		{8, 0, 0, 0, 0, 0, 7, 0},
		{4, 2, 0, 0, 0, 0, 0, 0},
		{0, 4, 0, 0, 0, 0, 5, 3},
		{0, 0, 3, 7, 0, 5, 0, 0},
		{0, 1, 0, 0, 0, 3, 0, 0},
	};

	char letters[MAX] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };


	dijkstra(adjacencyMatrix, 8, 0);

	system("pause");
	return 0;
}

void dijkstra(int matrix[MAX][MAX], int vertices, int start)
{
	int cost[MAX][MAX];
	int distance[MAX];
	int predecessor[MAX];
	int visited[MAX];
	int count, mindistance, next;


	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < vertices; j++) {
			if (matrix[i][j] == 0) {
				cost[i][j] = INFINITY;
			}
			else {
				cost[i][j] = matrix[i][j];
			}
		}
	}

	for (int i = 0; i < vertices; i++) {
		distance[i] = cost[start][i];
		predecessor[i] = start;
		visited[i] = 0;
	}

	distance[start] = 0;
	visited[start] = 0;
	count = 1;

	while (count < vertices - 1) {
		mindistance = INFINITY;

		for (int i = 0; i < vertices; i++) {
			if (distance[i] < mindistance && !visited[i]) {
				mindistance = distance[i];
				next = i;
			}

			visited[next] = 1;
			for (int i = 0; i < vertices; i++) {
				if (!visited[i]) {
					if (mindistance + cost[next][i] < distance[i]) {
						distance[i] = mindistance + cost[next][i];
						predecessor[i] = next;
					}
				}
			}
			count++;
		}
	}

	for (int i = 0; i < vertices; i++) {
		if (i != start) {
			cout << "Node: " << i << " Distance: " << distance[i] << endl;
			cout << "Path: " << i << endl;
			int j = i;
			do 
			{
				j = predecessor[j];
				cout << j << endl;
			} while (j != start);
		}
	}


}