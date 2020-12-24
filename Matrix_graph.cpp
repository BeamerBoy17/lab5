#include "Matrix_Graph.h"

int** matrix(int size)
{
	int** matrix = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		matrix[i] = (int*)malloc(size * sizeof(int));
	}
	return matrix;
}

void generate_matrix(Graph* graph, int ver)
{
	int tmp;

	for (int i = 0; i < graph->size; i++) {
		for (int j = 0; j < graph->size; j++) {
			if (j != i) {
				tmp = rand() % 100;

				if (tmp < ver) {
					graph->matrix[i][j] = 1;
				}
				else {
					graph->matrix[i][j] = 0;
				}
				graph->matrix[j][i] = graph->matrix[i][j];

			}
			else if (i == j) graph->matrix[i][j] = 0;
		}
	}
}


Graph* init_graph(int size)
{
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	graph->matrix = matrix(size);
	graph->size = size;
	return graph;
};

void free_graph(Graph* graph)
{
	for (int i = 0; i < graph->size; i++)
	{
		free(graph->matrix[i]);
	}
	free(graph->matrix);
	free(graph);
}

void print_graph(Graph* graph)
{
	printf(" ");
	for (int k = 1; k <= graph->size; k++) printf(" %d", k);
	printf("\n   -----------\n");

	for (int i = 0; i < graph->size; i++) {
		printf("%d |", i + 1);

		for (int j = 0; j < graph->size; j++) {
			printf("%d ", graph->matrix[i][j]);
		}

		printf("\n");
	}

}