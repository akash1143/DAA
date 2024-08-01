#include <stdio.h>
#include <limits.h>

#define V 5 // Number of vertices in the graph
#define INF INT_MAX

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int sptSet[]) {
    int min = INF, min_index;
    
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V]; // The output array dist[i] holds the shortest distance from src to i
    int sptSet[V]; // sptSet[i] will be 1 if vertex i is included in the shortest path tree
    
    // Initialize all distances as INFINITE and sptSet[] as 0
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
    }
    
    // Distance from source vertex to itself is always 0
    dist[src] = 0;
    
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance(dist, sptSet);
        
        // Mark the picked vertex as processed
        sptSet[u] = 1;
        
        // Update the distance value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    
    // Print the constructed distance array
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    // Example graph represented as an adjacency matrix
    int graph[V][V] = {
        {0, 10, 3, 0, 0},
        {10, 0, 1, 2, 0},
        {3, 1, 0, 8, 2},
        {0, 2, 8, 0, 7},
        {0, 0, 2, 7, 0}
    };
    
    int source = 0; // Starting vertex
    
    dijkstra(graph, source);
    
    return 0;
}

