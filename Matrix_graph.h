#pragma once
#include "stdlib.h"
#include "stdio.h"

typedef struct Graph
{
    int** matrix;
    int size;
}graph;

int** matrix(int size);
void generate_matrix(Graph* graph, int ver);

Graph* init_graph(int size);
void free_graph(Graph* graph);
void print_graph(Graph* graph);
