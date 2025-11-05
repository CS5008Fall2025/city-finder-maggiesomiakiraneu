#include "dijkstra.h"
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

/**
 * this is the helper function to find the vertex with minimum distance
 * that hasn't been visited yet
 */
static int find_min_distance_vertex(const int* distances, const bool* visited, int num_cities) {
    int min_distance = INFINITY_DIST;
    int min_index = -1;
    
    for (int i = 0; i < num_cities; i++) {
        if (!visited[i] && distances[i] < min_distance) {
            min_distance = distances[i];
            min_index = i;
        }
    }
    
    return min_index;
}

/**
 * this is the Helper function to reconstruct the path from start to end
 * using the parent array
 */
static int reconstruct_path(int* path, const int* parent, int start, int end) {
    int path_length = 0;
    int current = end;
    
    while (current != -1) {
        path[path_length++] = current;
        current = parent[current];
    }
    
    for (int i = 0; i < path_length / 2; i++) {
        int temp = path[i];
        path[i] = path[path_length - 1 - i];
        path[path_length - 1 - i] = temp;
    }
    
    return path_length;
}

PathResult find_shortest_path(const Graph* graph, const char* start_city, const char* end_city) {
    PathResult result;
    result.found = false;
    result.path_length = 0;
    result.total_distance = 0;
    
    if (graph == NULL || start_city == NULL || end_city == NULL) {
        return result;
    }
    
    int start_index = find_city_index(graph, start_city);
    int end_index = find_city_index(graph, end_city);
    
    if (start_index == -1 || end_index == -1) {
        return result;
    }
    
    int num_cities = graph->num_cities;
    
    int distances[MAX_CITIES];
    bool visited[MAX_CITIES];
    int parent[MAX_CITIES];
    
    for (int i = 0; i < num_cities; i++) {
        distances[i] = INFINITY_DIST;
        visited[i] = false;
        parent[i] = -1;
    }
    
    distances[start_index] = 0;
    
    for (int count = 0; count < num_cities - 1; count++) {
        int u = find_min_distance_vertex(distances, visited, num_cities);
        
        if (u == -1) {
            break;
        }
        
        visited[u] = true;
        
        if (u == end_index) {
            break;
        }
        
        for (int v = 0; v < num_cities; v++) {
            if (!visited[v] && 
                graph->adjacency_matrix[u][v] != INFINITY_DIST &&
                distances[u] != INFINITY_DIST &&
                distances[u] + graph->adjacency_matrix[u][v] < distances[v]) {
                
                distances[v] = distances[u] + graph->adjacency_matrix[u][v];
                parent[v] = u;
            }
        }
    }
    
    if (distances[end_index] == INFINITY_DIST) {
        return result;
    }
    result.path_length = reconstruct_path(result.path, parent, start_index, end_index);
    result.total_distance = distances[end_index];
    result.found = true;
    
    return result;
}

void print_path_result(const Graph* graph, const PathResult* result) {
    if (graph == NULL || result == NULL) {
        return;
    }
    
    if (!result->found) {
        printf("Path Not Found...\n");
        return;
    }
    
    printf("Path Found...\n");
    
    for (int i = 0; i < result->path_length; i++) {
        printf("\t%s\n", graph->cities[result->path[i]]);
    }
    
    printf("Total Distance: %d\n", result->total_distance);
}