#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include <queue>
#include <iostream>
#include "Matrix_Graph.h"
#pragma warning (disable : 4996)

int first_false(bool* arr, int size) {
	for (size_t i = 0; i < size; i++) {
		if (!arr[i]) { return i; };
	}
	return -1;
}

void BFS(graph* g,int v, bool* visited) {
	std::queue <int> qu;
	qu.push(v);
	visited[v] = 1;
	while (!qu.empty()) {
		v = qu.front();
		printf(" %d  ", v + 1);		
		qu.pop();
		for (int i = 0; i < g->size; i++) {
			if ((g->matrix[v][i] == 1) && (visited[i] == 0)) {
				qu.push(i);
				visited[i] = 1;			
			}
		}
	}
}
void component(graph* g) {
	bool* visited = (bool*)calloc(g->size, 1);

	int next_vertex = 0;

	while (next_vertex != -1) {
		BFS(g, next_vertex, visited);
		printf("\n");
		next_vertex = first_false(visited, g->size);
	}

	free(visited);
}
void main()
{
	int ver;
	int size;
	
	printf("\nEnter the probability from 0 to 100: ");
	scanf_s("%d", &ver);
	
	printf("Eneter size of graph:");
	scanf("%d", &size);
	graph* g = init_graph(size);
	srand(time(NULL));
	generate_matrix(g,ver);
	print_graph(g);

	printf("\nComponents:\n");
	component(g);
	
}




