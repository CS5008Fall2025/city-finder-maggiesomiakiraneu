#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "file_io.h"
#include "dijkstra.h"

#define MAX_INPUT_LENGTH 256

/**
 * Prints the welcome message and help information
 */
void print_welcome() {
    printf("*****Welcome to the shortest path finder!******\n");
    printf("Commands:\n");
    printf("\tlist - list all cities\n");
    printf("\t<city1> <city2> - find the shortest path between two cities\n");
    printf("\thelp - print this help message\n");
    printf("\texit - exit the program\n");
    printf("*******************************************************\n");
}

/**
 * Prints the help message
 */
void print_help() {
    printf("Commands:\n");
    printf("\tlist - list all cities\n");
    printf("\t<city1> <city2> - find the shortest path between two cities\n");
    printf("\thelp - print this help message\n");
    printf("\texit - exit the program\n");
}

/**
 * Prints invalid command message
 */
void print_invalid_command() {
    printf("Invalid Command\n");
    print_help();
}

/**
 * Processes user commands in the interactive loop
 */
void process_command(Graph* graph, const char* input) {
    char input_copy[MAX_INPUT_LENGTH];
    strncpy(input_copy, input, MAX_INPUT_LENGTH - 1);
    input_copy[MAX_INPUT_LENGTH - 1] = '\0';
    
    char* token1 = strtok(input_copy, " ");
    
    if (token1 == NULL) {
        print_invalid_command();
        return;
    }
    
    if (strcmp(token1, "list") == 0) {
        print_cities(graph);
        return;
    }
    
    if (strcmp(token1, "help") == 0) {
        print_help();
        return;
    }
    
    if (strcmp(token1, "exit") == 0) {
        printf("Goodbye!\n");
        exit(0);
    }
    
    char* token2 = strtok(NULL, " ");
    
    if (token2 == NULL) {
        print_invalid_command();
        return;
    }
    
    char* token3 = strtok(NULL, " ");
    if (token3 != NULL) {
        print_invalid_command();
        return;
    }
    
    if (!city_exists(graph, token1) || !city_exists(graph, token2)) {
        print_invalid_command();
        return;
    }
    
    PathResult result = find_shortest_path(graph, token1, token2);
    print_path_result(graph, &result);
}

/**
 * Runs the interactive command loop
 */
void run_interactive_loop(Graph* graph) {
    char input[MAX_INPUT_LENGTH];
    
    while (1) {
        printf("Where do you want to go today? ");
        
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }
        
        input[strcspn(input, "\n")] = '\0';
        
        if (strlen(input) == 0) {
            continue;
        }
        
        process_command(graph, input);
    }
}

/**
 * Main function
 */
int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <vertices> <distances>\n", argv[0]);
        return 1;
    }
    
    Graph* graph = create_graph();
    if (graph == NULL) {
        fprintf(stderr, "Error: Could not create graph\n");
        return 1;
    }
    
    if (!load_vertices(graph, argv[1])) {
        fprintf(stderr, "Error: Could not load vertices from %s\n", argv[1]);
        free_graph(graph);
        return 1;
    }
    
    if (!load_distances(graph, argv[2])) {
        fprintf(stderr, "Error: Could not load distances from %s\n", argv[2]);
        free_graph(graph);
        return 1;
    }
    
    print_welcome();
    
    run_interactive_loop(graph);
    
    free_graph(graph);
    
    return 0;
}