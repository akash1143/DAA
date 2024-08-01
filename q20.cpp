#include <stdio.h>
#include <stdlib.h>

// A structure to represent an edge in the graph
typedef struct {
    int src, dest, weight;
} Edge;

// A structure to represent a subset for union-find
typedef struct {
    int parent;
    int rank;
} Subset;

// A structure to represent a graph
typedef struct {
    int V, E;
    Edge* edges;
} Graph;

// Function to create a graph with V vertices and E edges
Graph* create_graph(int V, int E) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (Edge*) malloc(E * sizeof(Edge));
    return graph;
}

// A function to find the subset of an element i (using path compression)
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// A function to union two subsets x and y (using union by rank)
void union_subsets(Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    // Attach smaller rank tree under root of high rank tree
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Compare two edges according to their weights (for qsort)
int compare_edges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Function to construct and print MST using Kruskal's algorithm
void kruskal_mst(Graph* graph) {
    int V = graph->V;
    Edge result[V]; // Store the resultant MST
    int e = 0; // Index variable, used for result[]
    int i = 0; // Index variable, used for sorted edges

    // Step 1: Sort all the edges in non-decreasing order of their weight
    qsort(graph->edges, graph->E, sizeof(Edge), compare_edges);

    // Allocate memory for creating V subsets
    Subset* subsets = (Subset*) malloc(V * sizeof(Subset));

    // Create V subsets with single elements
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E) {
        // Step 2: Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far
        Edge next_edge = graph->edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does not cause a cycle, include it in the result
        if (x != y) {
            result[e++] = next_edge;
            union_subsets(subsets, x, y);
        }
    }

    // Print the constructed MST
    printf("Following are the edges in the constructed MST:\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);

    // Free memory
    free(subsets);
}

int main() {
    int V = 4; // Number of vertices in graph
    int E = 5; // Number of edges in graph
    Graph* graph = create_graph(V, E);

    // Add edges
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;

    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 6;

    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;

    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 15;

    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 4;

    kruskal_mst(graph);

    // Free memory
    free(graph->edges);
    free(graph);

    return 0;
}

