#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Graph* create_graph() {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL) {
        return NULL;
    }
    
    graph->num_cities = 0;
    
    for (int i = 0; i < MAX_CITIES; i++) {
        for (int j = 0; j < MAX_CITIES; j++) {
            if (i == j) {
                graph->adjacency_matrix[i][j] = 0;
            } else {
                graph->adjacency_matrix[i][j] = INFINITY_DIST;
            }
        }
    }
    
    return graph;
}

int add_vertex(Graph* graph, const char* city) {
    if (graph == NULL || city == NULL) {
        return -1;
    }
    
    int existing_index = find_city_index(graph, city);
    if (existing_index != -1) {
        return existing_index;
    }
    
    if (graph->num_cities >= MAX_CITIES) {
        return -1;
    }
    
    strncpy(graph->cities[graph->num_cities], city, MAX_NAME_LENGTH - 1);
    graph->cities[graph->num_cities][MAX_NAME_LENGTH - 1] = '\0';
    
    return graph->num_cities++;
}

void add_edge(Graph* graph, const char* city1, const char* city2, int distance) {
    if (graph == NULL || city1 == NULL || city2 == NULL) {
        return;
    }
    
    int index1 = find_city_index(graph, city1);
    int index2 = find_city_index(graph, city2);
    
    if (index1 == -1 || index2 == -1) {
        return;
    }
    
    graph->adjacency_matrix[index1][index2] = distance;
    graph->adjacency_matrix[index2][index1] = distance;
}

int find_city_index(const Graph* graph, const char* city) {
    if (graph == NULL || city == NULL) {
        return -1;
    }
    
    for (int i = 0; i < graph->num_cities; i++) {
        if (strcmp(graph->cities[i], city) == 0) {
            return i;
        }
    }
    
    return -1;
}

bool city_exists(const Graph* graph, const char* city) {
    return find_city_index(graph, city) != -1;
}

void print_cities(const Graph* graph) {
    if (graph == NULL) {
        return;
    }
    
    for (int i = 0; i < graph->num_cities; i++) {
        printf("%s\n", graph->cities[i]);
    }
}

void free_graph(Graph* graph) {
    if (graph != NULL) {
        free(graph);
    }
}