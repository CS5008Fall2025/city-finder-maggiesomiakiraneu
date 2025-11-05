#include "file_io.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

bool load_vertices(Graph* graph, const char* filename) {
    if (graph == NULL || filename == NULL) {
        return false;
    }
    
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return false;
    }
    
    char line[MAX_LINE_LENGTH];
    
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        
        if (strlen(line) == 0) {
            continue;
        }
        
        if (add_vertex(graph, line) == -1) {
            fprintf(stderr, "Warning: Could not add vertex %s\n", line);
        }
    }
    
    fclose(file);
    return true;
}

bool load_distances(Graph* graph, const char* filename) {
    if (graph == NULL || filename == NULL) {
        return false;
    }
    
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Cannot open file %s\n", filename);
        return false;
    }
    
    char line[MAX_LINE_LENGTH];
    
    while (fgets(line, sizeof(line), file) != NULL) {
        line[strcspn(line, "\n")] = '\0';
        
        if (strlen(line) == 0) {
            continue;
        }
        
        char* city1 = strtok(line, " ");
        char* city2 = strtok(NULL, " ");
        char* distance_str = strtok(NULL, " ");
        
        if (city1 == NULL || city2 == NULL || distance_str == NULL) {
            continue;
        }
        
        int distance = atoi(distance_str);
        
        add_edge(graph, city1, city2, distance);
    }
    
    fclose(file);
    return true;
}