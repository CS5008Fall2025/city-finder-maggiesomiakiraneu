#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>

#define MAX_CITIES 100
#define MAX_NAME_LENGTH 50
#define INFINITY_DIST 999999

/**
 * Graph structure using adjacency matrix
 * - cities: array of city names
 * - num_cities: number of cities in the graph
 * - adjacency_matrix: 2D array storing distances between cities
 */
typedef struct {
    char cities[MAX_CITIES][MAX_NAME_LENGTH];
    int num_cities;
    int adjacency_matrix[MAX_CITIES][MAX_CITIES];
} Graph;

/**
 * Creates and initializes a new graph
 * Returns: pointer to newly created graph
 */
Graph* create_graph();

/**
 * Adds a vertex (city) to the graph
 * Parameters:
 *   graph: pointer to the graph
 *   city: name of the city to add
 * Returns: index of the city in the graph, or -1 if graph is full
 */
int add_vertex(Graph* graph, const char* city);

/**
 * Adds an edge (distance) between two cities
 * Since this is an undirected graph, adds edge in both directions
 * Parameters:
 *   graph: pointer to the graph
 *   city1: first city name
 *   city2: second city name
 *   distance: distance between the cities
 */
void add_edge(Graph* graph, const char* city1, const char* city2, int distance);

/**
 * Finds the index of a city in the graph
 * Parameters:
 *   graph: pointer to the graph
 *   city: name of the city to find
 * Returns: index of the city, or -1 if not found
 */
int find_city_index(const Graph* graph, const char* city);

/**
 * Checks if a city exists in the graph
 * Parameters:
 *   graph: pointer to the graph
 *   city: name of the city to check
 * Returns: true if city exists, false otherwise
 */
bool city_exists(const Graph* graph, const char* city);

/**
 * Prints all cities in the graph (for list command)
 * Parameters:
 *   graph: pointer to the graph
 */
void print_cities(const Graph* graph);

/**
 * Frees memory allocated for the graph
 * Parameters:
 *   graph: pointer to the graph to free
 */
void free_graph(Graph* graph);

#endif