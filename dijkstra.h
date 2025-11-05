#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"
#include <stdbool.h>

/**
 * Structure to store the result of shortest path computation
 * - path: array of city indices representing the path
 * - path_length: number of cities in the path
 * - total_distance: total distance of the path
 * - found: whether a path was found
 */
typedef struct {
    int path[MAX_CITIES];
    int path_length;
    int total_distance;
    bool found;
} PathResult;

/**
 * Finds the shortest path between two cities using Dijkstra's algorithm
 * Parameters:
 *   graph: pointer to the graph
 *   start_city: name of the starting city
 *   end_city: name of the destination city
 * Returns: PathResult structure containing the path and distance
 */
PathResult find_shortest_path(const Graph* graph, const char* start_city, const char* end_city);

/**
 * Prints the path result in the required format
 * Parameters:
 *   graph: pointer to the graph
 *   result: PathResult structure to print
 */
void print_path_result(const Graph* graph, const PathResult* result);

#endif