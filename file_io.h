#ifndef FILE_IO_H
#define FILE_IO_H

#include "graph.h"
#include <stdbool.h>

/**
 * Loads vertices (cities) from a file into the graph
 * Expected format: one city name per line
 * Parameters:
 *   graph: pointer to the graph
 *   filename: path to the vertices file
 * Returns: true if successful, false otherwise
 */
bool load_vertices(Graph* graph, const char* filename);

/**
 * Loads edges (distances) from a file into the graph
 * Expected format: city1 city2 distance
 * Skips invalid lines (empty or incorrectly formatted)
 * Parameters:
 *   graph: pointer to the graph
 *   filename: path to the distances file
 * Returns: true if successful, false otherwise
 */
bool load_distances(Graph* graph, const char* filename);

#endif