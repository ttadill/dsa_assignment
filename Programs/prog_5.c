#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 20

// Graph structure using adjacency matrix
typedef struct {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Queue structure for BFS
typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// Stack structure for DFS (iterative)
typedef struct {
    int items[MAX_VERTICES];
    int top;
} Stack;

// Initialize graph
void initGraph(Graph *g, int vertices) {
    g->numVertices = vertices;
    
    // Initialize all edges to 0 (no edge)
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

// Add edge to undirected graph
void addEdge(Graph *g, int src, int dest) {
    if (src >= g->numVertices || dest >= g->numVertices || src < 0 || dest < 0) {
        printf("Invalid vertices!\n");
        return;
    }
    
    // For undirected graph, add edge in both directions
    g->adjMatrix[src][dest] = 1;
    g->adjMatrix[dest][src] = 1;
}

// Display adjacency matrix
void displayGraph(Graph *g) {
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    for (int i = 0; i < g->numVertices; i++) {
        printf("%2d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < g->numVertices; i++) {
        printf("%2d: ", i);
        for (int j = 0; j < g->numVertices; j++) {
            printf("%2d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// Queue operations for BFS
void initQueue(Queue *q) {
    q->front = -1;
    q->rear = -1;
}

bool isQueueEmpty(Queue *q) {
    return q->front == -1;
}

void enqueue(Queue *q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue is full!\n");
        return;
    }
    
    if (q->front == -1) {
        q->front = 0;
    }
    
    q->items[++(q->rear)] = value;
}

int dequeue(Queue *q) {
    if (isQueueEmpty(q)) {
        return -1;
    }
    
    int item = q->items[q->front];
    
    if (q->front >= q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    
    return item;
}

// Stack operations for DFS
void initStack(Stack *s) {
    s->top = -1;
}

bool isStackEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top == MAX_VERTICES - 1) {
        printf("Stack is full!\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(Stack *s) {
    if (isStackEmpty(s)) {
        return -1;
    }
    return s->items[(s->top)--];
}

// BFS traversal
void BFS(Graph *g, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    Queue q;
    initQueue(&q);
    
    printf("\nBFS Traversal starting from vertex %d:\n", startVertex);
    
    visited[startVertex] = true;
    enqueue(&q, startVertex);
    
    while (!isQueueEmpty(&q)) {
        int currentVertex = dequeue(&q);
        printf("%d ", currentVertex);
        
        // Visit all adjacent vertices
        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

// DFS traversal (recursive)
void DFSRecursive(Graph *g, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);
    
    // Visit all adjacent vertices
    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFSRecursive(g, i, visited);
        }
    }
}

// DFS wrapper function
void DFS(Graph *g, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    
    printf("\nDFS Traversal (Recursive) starting from vertex %d:\n", startVertex);
    DFSRecursive(g, startVertex, visited);
    printf("\n");
}

// DFS iterative using stack
void DFSIterative(Graph *g, int startVertex) {
    bool visited[MAX_VERTICES] = {false};
    Stack s;
    initStack(&s);
    
    printf("\nDFS Traversal (Iterative) starting from vertex %d:\n", startVertex);
    
    push(&s, startVertex);
    
    while (!isStackEmpty(&s)) {
        int currentVertex = pop(&s);
        
        if (!visited[currentVertex]) {
            printf("%d ", currentVertex);
            visited[currentVertex] = true;
        }
        
        // Push all adjacent vertices (in reverse order for consistency)
        for (int i = g->numVertices - 1; i >= 0; i--) {
            if (g->adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                push(&s, i);
            }
        }
    }
    printf("\n");
}

// Check if graph is connected
bool isConnected(Graph *g) {
    bool visited[MAX_VERTICES] = {false};
    
    // Perform DFS from vertex 0
    DFSRecursive(g, 0, visited);
    
    // Check if all vertices were visited
    for (int i = 0; i < g->numVertices; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    Graph g;
    int vertices, edges;
    
    printf("=========================================\n");
    printf("  GRAPH TRAVERSAL (BFS & DFS)\n");
    printf("  Using Adjacency Matrix\n");
    printf("=========================================\n\n");
    
    // Create example graph
    printf("Creating example graph with 6 vertices:\n\n");
    vertices = 6;
    initGraph(&g, vertices);
    
    // Add edges for example graph
    // Graph structure:
    //     0 --- 1 --- 2
    //     |     |     |
    //     3 --- 4 --- 5
    
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 3);
    addEdge(&g, 1, 2);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 5);
    addEdge(&g, 3, 4);
    addEdge(&g, 4, 5);
    
    printf("Graph Structure:\n");
    printf("    0 --- 1 --- 2\n");
    printf("    |     |     |\n");
    printf("    3 --- 4 --- 5\n");
    
    displayGraph(&g);
    
    // Perform BFS from different starting vertices
    BFS(&g, 0);
    BFS(&g, 2);
    
    // Perform DFS from different starting vertices
    DFS(&g, 0);
    DFS(&g, 2);
    
    // Perform iterative DFS
    DFSIterative(&g, 0);
    
    // Check connectivity
    printf("\nGraph is %s\n", isConnected(&g) ? "connected" : "not connected");
    
    // Interactive mode
    printf("\n=========================================\n");
    printf("Create your own graph:\n");
    printf("=========================================\n");
    
    printf("Enter number of vertices (1-%d): ", MAX_VERTICES);
    scanf("%d", &vertices);
    
    if (vertices < 1 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices!\n");
        return 1;
    }
    
    Graph userGraph;
    initGraph(&userGraph, vertices);
    
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    
    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(&userGraph, src, dest);
    }
    
    displayGraph(&userGraph);
    
    int choice, start;
    do {
        printf("\n1. BFS Traversal\n");
        printf("2. DFS Traversal (Recursive)\n");
        printf("3. DFS Traversal (Iterative)\n");
        printf("4. Check if connected\n");
        printf("5. Display graph\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                if (start >= 0 && start < vertices) {
                    BFS(&userGraph, start);
                } else {
                    printf("Invalid vertex!\n");
                }
                break;
            case 2:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                if (start >= 0 && start < vertices) {
                    DFS(&userGraph, start);
                } else {
                    printf("Invalid vertex!\n");
                }
                break;
            case 3:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                if (start >= 0 && start < vertices) {
                    DFSIterative(&userGraph, start);
                } else {
                    printf("Invalid vertex!\n");
                }
                break;
            case 4:
                printf("Graph is %s\n", isConnected(&userGraph) ? "connected" : "not connected");
                break;
            case 5:
                displayGraph(&userGraph);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 6);
    
    return 0;
}