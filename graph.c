#include <stdio.h>
#include <string.h>
#include "graph.h"

void initGraph(Graph* g) {
    g->num_cities = 0;
    for (int i = 0; i < MAX_CITIES; i++) {
        g->visited[i] = 0;
        for (int j = 0; j < MAX_CITIES; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }
}

void addCity(Graph* g, const char* name) {
    if (g->num_cities < MAX_CITIES) {
        strcpy(g->city_names[g->num_cities], name);
        g->num_cities++;
    }
}

void addEdge(Graph* g, int city1, int city2, int distance) {
    if (city1 >= 0 && city1 < g->num_cities && city2 >= 0 && city2 < g->num_cities) {
        g->adj_matrix[city1][city2] = distance;
        g->adj_matrix[city2][city1] = distance; 
    }
}

void resetVisited(Graph* g) {
    for (int i = 0; i < MAX_CITIES; i++) {
        g->visited[i] = 0;
    }
}

// DFS Algoritmasi
void DFS(Graph* g, int start_vertex) {
    printf("%s -> ", g->city_names[start_vertex]);
    g->visited[start_vertex] = 1;

    for (int i = 0; i < g->num_cities; i++) {
        if (g->adj_matrix[start_vertex][i] != 0 && !g->visited[i]) {
            DFS(g, i);
        }
    }
}