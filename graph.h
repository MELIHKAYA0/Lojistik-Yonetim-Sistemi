#ifndef GRAPH_H
#define GRAPH_H

#define MAX_CITIES 5

typedef struct {
    char city_names[MAX_CITIES][20]; 
    int adj_matrix[MAX_CITIES][MAX_CITIES]; 
    int visited[MAX_CITIES]; 
    int num_cities;
} Graph;

void initGraph(Graph* g);
void addCity(Graph* g, const char* name);
void addEdge(Graph* g, int city1, int city2, int distance);
void DFS(Graph* g, int start_vertex); 
void resetVisited(Graph* g);

#endif