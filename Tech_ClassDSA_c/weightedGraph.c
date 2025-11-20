#include<stdio.h>
#include<stdlib.h>
#define v 6 // Number of vertices in the graph

void insertDirectedEdge(int graph[v][v], int start, int end, int weight) {
    // Check if the vertices are within bounds
    /*if (start < 0 || start >= v || end < 0 || end >= v) {
    printf("Invalid vertices: %d and %d. Vertices must be between 0 and %d.\n", start, end, v - 1);
    return;
    }*/
    graph[start][end] = weight; // Add edge from start to end (for directed graph)
    printf("Edge inserted between %d and %d.\n", start, end);
}

void insertUndirectedEdge(int graph[v][v], int start, int end, int weight) {
    // Check if the vertices are within bounds
    /*if (start < 0 || start >= v || end < 0 || end >= v) {
    printf("Invalid vertices: %d and %d. Vertices must be between 0 and %d.\n", start, end, v - 1);
    return;
    }*/
    graph[start][end] = weight;
    graph[end][start] = weight; // Add edge from start to end (for directed graph)
    printf("Edge inserted between %d and %d.\n", start, end);
}

void display(int graph[v][v]) {
    printf("Graph adjacency matrix:\n");
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
void searchEdge(int graph[v][v], int start, int end) {
    // Check if the vertices are within bounds
    /*if (start < 0 || start >= v || end < 0 || end >= v) {
        printf("Invalid vertices: %d and %d. Vertices must be between 0 and %d.\n", start, end, v - 1);
        return;
    }*/
    if (graph[start][end] == 1) {
        printf("Edge exists between %d and %d.\n", start, end);
    } else {
        printf("No edge exists between %d and %d.\n", start, end);
    }
}
int main(){
    int graph[v][v]= {0}; // Declare a 2D array for the adjacency matrix
    // Initialize the graph with 0s (no edges)
    /*for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            graph[ i][j] = 0;
        }
    }*/

    insertUndirectedEdge(graph, 0, 1, 8);
    insertUndirectedEdge(graph, 4, 5, 3);
    insertUndirectedEdge(graph, 2, 3, 7);
    insertDirectedEdge(graph, 1, 2, 5);
    insertDirectedEdge(graph, 4, 2, 0);
    insertDirectedEdge(graph, 4, 0, 2);
    insertDirectedEdge(graph, 5, 3, 0);
    
    display(graph);
    
    searchEdge(graph, 0, 1);
    searchEdge(graph, 1, 4);

    return 0;
}