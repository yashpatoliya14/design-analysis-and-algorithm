#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5

// Graph representation as adjacency matrix
int graph[V][V] = {
    {0, 2, 0, 6, 0},
    {2, 0, 3, 8, 5},
    {0, 3, 0, 0, 7},
    {6, 8, 0, 0, 9},
    {0, 5, 7, 9, 0}
};

/**
 * Function to find the vertex with minimum distance value
 * that has not yet been included in the shortest path tree
 */
int minDistance(int dist[], bool sptSet[]) {
    // Initialize min value
    int min = INT_MAX, min_index;
    
    // Check all vertices to find the minimum distance
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
            
    return min_index;
}

/**
 * Function to print the constructed distance array
 */
void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

/**
 * Function that implements Dijkstra's single source shortest path algorithm
 * for a graph represented using adjacency matrix representation
 */
void dijkstra(int src) {
    // Array to store the shortest distance from source to each vertex
    int dist[V];
    
    // sptSet[i] will be true if vertex i is included in shortest path tree
    // or shortest distance from src to i is finalized
    bool sptSet[V];
    
    // Step 1: Initialize all distances as INFINITE and sptSet[] as false
    // Distance from source to itself is always 0
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
        
    dist[src] = 0;
    
    // Step 2: Find shortest path for all vertices
    // The algorithm processes V-1 vertices (source is already processed)
    for (int count = 0; count < V - 1; count++) {
        // Step 3: Pick the minimum distance vertex from the set of vertices
        // not yet processed. u is always equal to src in first iteration.
        int u = minDistance(dist, sptSet);
        
        // Step 4: Mark the picked vertex as processed
        sptSet[u] = true;
        
        // Step 5: Update distance value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++)
            // Update dist[v] only if:
            // 1. It is not in sptSet
            // 2. There is an edge from u to v (graph[u][v] is not 0)
            // 3. Total weight of path from src to v through u is smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    
    // Step 6: Print the constructed distance array
    printSolution(dist);
}

/**
 * Main function to test the Dijkstra algorithm
 */
int main() {
    // Run Dijkstra's algorithm with vertex 0 as source
    dijkstra(0);
    return 0;
}
