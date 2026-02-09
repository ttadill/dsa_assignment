#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 20
#define INF INT_MAX

// Graph structure using adjacency matrix with weights
typedef struct {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} WeightedGraph;

// Initialize weighted graph
void initGraph(WeightedGraph *g, int vertices) {
    g->numVertices = vertices;
    
    // Initialize all weights to INF (no edge)
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (i == j) {
                g->adjMatrix[i][j] = 0;  // Distance to self is 0
            } else {
                g->adjMatrix[i][j] = INF;  // No edge initially
            }
        }
    }
}

// Add weighted edge
void addEdge(WeightedGraph *g, int src, int dest, int weight) {
    if (src >= g->numVertices || dest >= g->numVertices || src < 0 || dest < 0) {
        printf("Invalid vertices!\n");
        return;
    }
    
    if (weight < 0) {
        printf("Warning: Dijkstra's algorithm doesn't work with negative weights!\n");
    }
    
    // For undirected graph
    g->adjMatrix[src][dest] = weight;
    g->adjMatrix[dest][src] = weight;
}

// Display adjacency matrix
void displayGraph(WeightedGraph *g) {
    printf("\nWeighted Adjacency Matrix:\n");
    printf("     ");
    for (int i = 0; i < g->numVertices; i++) {
        printf("%4d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < g->numVertices; i++) {
        printf("%4d: ", i);
        for (int j = 0; j < g->numVertices; j++) {
            if (g->adjMatrix[i][j] == INF) {
                printf(" INF ");
            } else {
                printf("%4d ", g->adjMatrix[i][j]);
            }
        }
        printf("\n");
    }
}

// Find vertex with minimum distance not yet processed
int findMinDistance(int dist[], bool visited[], int n) {
    int min = INF;
    int minIndex = -1;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    
    return minIndex;
}

// Print path from source to destination
void printPath(int parent[], int vertex) {
    if (parent[vertex] == -1) {
        printf("%d", vertex);
        return;
    }
    
    printPath(parent, parent[vertex]);
    printf(" -> %d", vertex);
}

// Dijkstra's Algorithm
void dijkstra(WeightedGraph *g, int source) {
    int dist[MAX_VERTICES];       // Shortest distance from source
    bool visited[MAX_VERTICES];   // Visited vertices
    int parent[MAX_VERTICES];     // To store shortest path tree
    
    // Initialize distances and visited array
    for (int i = 0; i < g->numVertices; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    
    // Distance to source is 0
    dist[source] = 0;
    
    printf("\n===========================================\n");
    printf("Dijkstra's Algorithm - Step by Step\n");
    printf("===========================================\n");
    printf("Source Vertex: %d\n\n", source);
    
    // Find shortest path for all vertices
    for (int count = 0; count < g->numVertices - 1; count++) {
        // Find minimum distance vertex not yet processed
        int u = findMinDistance(dist, visited, g->numVertices);
        
        if (u == -1) break;  // No more reachable vertices
        
        visited[u] = true;
        
        printf("Step %d: Selected vertex %d (distance: %d)\n", count + 1, u, dist[u]);
        
        // Update distances of adjacent vertices
        for (int v = 0; v < g->numVertices; v++) {
            // Update dist[v] if:
            // 1. Not visited
            // 2. Edge exists from u to v
            // 3. Total weight through u is less than current dist[v]
            if (!visited[v] && 
                g->adjMatrix[u][v] != INF && 
                dist[u] != INF &&
                dist[u] + g->adjMatrix[u][v] < dist[v]) {
                
                int oldDist = dist[v];
                dist[v] = dist[u] + g->adjMatrix[u][v];
                parent[v] = u;
                
                if (oldDist == INF) {
                    printf("  -> Updated vertex %d: INF to %d\n", v, dist[v]);
                } else {
                    printf("  -> Updated vertex %d: %d to %d\n", v, oldDist, dist[v]);
                }
            }
        }
        printf("\n");
    }
    
    // Print results
    printf("===========================================\n");
    printf("Final Shortest Paths from Source %d:\n", source);
    printf("===========================================\n");
    printf("Vertex    Distance    Path\n");
    printf("-------------------------------------------\n");
    
    for (int i = 0; i < g->numVertices; i++) {
        printf("%4d      ", i);
        
        if (dist[i] == INF) {
            printf("INF        No path\n");
        } else {
            printf("%4d       ", dist[i]);
            printPath(parent, i);
            printf("\n");
        }
    }
    printf("===========================================\n");
}

// Display all shortest paths in a compact format
void displayAllPaths(WeightedGraph *g, int source) {
    int dist[MAX_VERTICES];
    bool visited[MAX_VERTICES];
    int parent[MAX_VERTICES];
    
    for (int i = 0; i < g->numVertices; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }
    
    dist[source] = 0;
    
    for (int count = 0; count < g->numVertices - 1; count++) {
        int u = findMinDistance(dist, visited, g->numVertices);
        if (u == -1) break;
        visited[u] = true;
        
        for (int v = 0; v < g->numVertices; v++) {
            if (!visited[v] && 
                g->adjMatrix[u][v] != INF && 
                dist[u] != INF &&
                dist[u] + g->adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + g->adjMatrix[u][v];
                parent[v] = u;
            }
        }
    }
    
    printf("\nShortest paths from vertex %d:\n", source);
    for (int i = 0; i < g->numVertices; i++) {
        if (i != source) {
            printf("To %d (distance %d): ", i, dist[i]);
            printPath(parent, i);
            printf("\n");
        }
    }
}

int main() {
    WeightedGraph g;
    int vertices;
    
    printf("=========================================\n");
    printf("  DIJKSTRA'S SHORTEST PATH ALGORITHM\n");
    printf("=========================================\n\n");
    
    // Example graph
    printf("Example Graph with 6 vertices:\n\n");
    vertices = 6;
    initGraph(&g, vertices);
    
    // Add weighted edges
    // Graph structure:
    //        1
    //    (4)/ \(2)
    //      /   \
    //     0     2
    //    (1)\  /(3)
    //        3 
    //       / \(1)
    //    (2)/   \
    //      4     5
    //       \(1)/
    //         
    
    addEdge(&g, 0, 1, 4);
    addEdge(&g, 0, 3, 1);
    addEdge(&g, 1, 2, 2);
    addEdge(&g, 2, 3, 3);
    addEdge(&g, 3, 4, 2);
    addEdge(&g, 3, 5, 1);
    addEdge(&g, 4, 5, 1);
    
    printf("Graph Structure:\n");
    printf("       1\n");
    printf("   (4)/ \\(2)\n");
    printf("     /   \\\n");
    printf("    0     2\n");
    printf("   (1)\\  /(3)\n");
    printf("       3\n");
    printf("      / \\(1)\n");
    printf("   (2)/   \\\n");
    printf("     4     5\n");
    printf("      \\(1)/\n");
    
    displayGraph(&g);
    
    // Run Dijkstra from vertex 0
    dijkstra(&g, 0);
    
    // Run from another vertex
    printf("\n\n");
    dijkstra(&g, 2);
    
    // Interactive mode
    printf("\n\n=========================================\n");
    printf("Create your own weighted graph:\n");
    printf("=========================================\n");
    
    printf("Enter number of vertices (1-%d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    
    if (vertices < 1 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices!\n");
        return 1;
    }
    
    WeightedGraph userGraph;
    initGraph(&userGraph, vertices);
    
    int edges;
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (source destination weight):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest, weight;
        printf("Edge %d: ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(&userGraph, src, dest, weight);
    }
    
    displayGraph(&userGraph);
    
    int choice, source;
    do {
        printf("\n1. Find shortest paths from a source\n");
        printf("2. Display graph\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter source vertex: ");
                scanf("%d", &source);
                if (source >= 0 && source < vertices) {
                    dijkstra(&userGraph, source);
                } else {
                    printf("Invalid vertex!\n");
                }
                break;
            case 2:
                displayGraph(&userGraph);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 3);
    
    return 0;
}