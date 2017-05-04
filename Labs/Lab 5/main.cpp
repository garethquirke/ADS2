#pragma once
#include <iostream>
#include <algorithm>
using namespace std;

// Declarations
// Define the total number of vertices - 8
const int V = 8;
char letters[V] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
void dijkstraSP(int matrix[V][V], int start, int end);
void dijkstraPathToAll(int matrix[V][V], int start);
int minDistance(int distances[], bool predecessors[]);
void print(int distances[], int start, int end);
void print(int distances[], int start);

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

	dijkstraSP(adjacencyMatrix, 0, 7);
	dijkstraSP(adjacencyMatrix, 3, 5);


	cout << "Shortest path to every other node for vertices A and D" << endl;
	dijkstraPathToAll(adjacencyMatrix, 0);
	dijkstraPathToAll(adjacencyMatrix, 3);

	system("pause");
	return 0;
}

/*
Source: Dijkstras shortest path algorithm on geeks for geeks site
Usage: Used
Availible from: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
*/
void dijkstraSP(int matrix[V][V], int start, int end) {
	// output array and an array of previous vertices
	int distances[V];
	bool predecessors[V];

	// declaring values for the array
	for (int i = 0; i < V; i++) {
		distances[i] = INT_MAX;
		predecessors[i] = false;
	}

	// distance from start node will always be 0
	distances[start] = 0;

	for (int i = 0; i < V - 1; i++) {
		// pick the closest neighbouring node
		int min = minDistance(distances, predecessors);
		// and now this node has been taken care of
		predecessors[min] = true;


		for (int j = 0; j < V; j++) {
			if (!predecessors[j] && matrix[min][j] && distances[min] != INT_MAX && distances[min] + matrix[min][j] < distances[j]) {
				distances[j] = distances[min] + matrix[min][j];
			}
		}
	}
	print(distances, start, end);
}

/*
Source: Dijkstras shortest path algorithm on geeks for geeks site
Usage: Used
Availible from: http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/
*/
void dijkstraPathToAll(int matrix[V][V], int start)
{
	// output array and an array of previous vertices
	int distances[V];
	bool predecessors[V];

	// declaring values for the array
	for (int i = 0; i < V; i++) {
		distances[i] = INT_MAX;
		predecessors[i] = false;
	}

	// distance from start node will always be 0
	distances[start] = 0;

	for (int i = 0; i < V - 1; i++) {
		// pick the closest neighbouring node
		int min = minDistance(distances, predecessors);
		// and now this node has been taken care of
		predecessors[min] = true;


		for (int j = 0; j < V; j++) {
			if (!predecessors[j] && matrix[min][j] && distances[min] != INT_MAX && distances[min] + matrix[min][j] < distances[j]) {
				distances[j] = distances[min] + matrix[min][j];
			}
		}
	}

	print(distances, start);

}

int minDistance(int distances[], bool predecessors[])
{
	int min = INT_MAX, min_index;

	for (int i = 0; i < V; i++) {
		if (predecessors[i] == false && distances[i] <= min) {
			min = distances[i];
			min_index = i;
		}
	}

	return min_index;
}

void print(int distances[], int start, int end)
{
	cout << "Shortest path between " << letters[start] << " and " << letters[end] << " is " << distances[end] << endl;
}


void print(int distances[], int start) {

	// now just print the entire array of distances rather than outputting the sp between two points

	cout << "Vertex: " << letters[start] << endl;
	for (int i = 0; i < V; i++) {
		if (i != 0) {
			// omit the actual node thats being checked
			if (i == start) {
				i++;
			}
			cout << "Distance to " << letters[i] << " is " << distances[i] << endl;
		}
	}
}