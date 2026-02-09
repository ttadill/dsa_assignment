# Program 5: Graph Traversal (BFS and DFS)

## Overview
This program implements an undirected graph using an adjacency matrix and provides both Breadth-First Search (BFS) and Depth-First Search (DFS) traversal algorithms.

## Data Structures

### Graph Structure
```c
typedef struct {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;
```
- **numVertices**: Total number of vertices in the graph
- **adjMatrix**: 2D array representing edges
  - adjMatrix[i][j] = 1 means edge exists between vertex i and j
  - adjMatrix[i][j] = 0 means no edge
- **MAX_VERTICES**: Maximum capacity (20 vertices)

### Queue Structure (for BFS)
```c
typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;
```
- Used for level-order traversal in BFS
- FIFO (First In First Out) principle

### Stack Structure (for DFS Iterative)
```c
typedef struct {
    int items[MAX_VERTICES];
    int top;
} Stack;
```
- Used for iterative DFS implementation
- LIFO (Last In First Out) principle

## Functions Implemented

### Graph Operations

1. **`void initGraph(Graph *g, int vertices)`**
   - Initializes graph with given number of vertices
   - Sets all adjacency matrix values to 0
   - Time Complexity: O(V²)

2. **`void addEdge(Graph *g, int src, int dest)`**
   - Adds an edge between two vertices
   - For undirected graph, adds edge in both directions
   - Time Complexity: O(1)

3. **`void displayGraph(Graph *g)`**
   - Displays adjacency matrix representation
   - Time Complexity: O(V²)

### Queue Operations

4. **`void initQueue(Queue *q)`**
   - Initializes empty queue

5. **`bool isQueueEmpty(Queue *q)`**
   - Checks if queue is empty

6. **`void enqueue(Queue *q, int value)`**
   - Adds element to rear
   - Time Complexity: O(1)

7. **`int dequeue(Queue *q)`**
   - Removes and returns element from front
   - Time Complexity: O(1)

### Stack Operations

8. **`void initStack(Stack *s)`**
   - Initializes empty stack

9. **`bool isStackEmpty(Stack *s)`**
   - Checks if stack is empty

10. **`void push(Stack *s, int value)`**
    - Adds element to top
    - Time Complexity: O(1)

11. **`int pop(Stack *s)`**
    - Removes and returns element from top
    - Time Complexity: O(1)

### Traversal Algorithms

12. **`void BFS(Graph *g, int startVertex)`**
    - **Algorithm**:
      1. Create visited array and queue
      2. Mark start vertex as visited, enqueue it
      3. While queue is not empty:
         - Dequeue a vertex
         - Print it
         - Enqueue all unvisited adjacent vertices
    - **Time Complexity**: O(V + E) where V = vertices, E = edges
    - **Space Complexity**: O(V) for queue and visited array
    - **Properties**:
      - Level-order traversal
      - Finds shortest path in unweighted graph
      - Uses more memory than DFS

13. **`void DFSRecursive(Graph *g, int vertex, bool visited[])`**
    - Recursive helper function for DFS
    - Visits vertex, then recursively visits unvisited neighbors

14. **`void DFS(Graph *g, int startVertex)`**
    - **Algorithm** (Recursive):
      1. Mark current vertex as visited
      2. Print it
      3. Recursively visit all unvisited adjacent vertices
    - **Time Complexity**: O(V + E)
    - **Space Complexity**: O(V) for recursion stack and visited array
    - **Properties**:
      - Goes deep before exploring siblings
      - Uses less memory than BFS (usually)
      - Better for detecting cycles

15. **`void DFSIterative(Graph *g, int startVertex)`**
    - **Algorithm** (Iterative using Stack):
      1. Create visited array and stack
      2. Push start vertex
      3. While stack is not empty:
         - Pop a vertex
         - If not visited, mark and print
         - Push all unvisited adjacent vertices
    - **Time Complexity**: O(V + E)
    - **Space Complexity**: O(V)
    - Avoids recursion overhead

16. **`bool isConnected(Graph *g)`**
    - Checks if all vertices are reachable from vertex 0
    - Uses DFS to verify connectivity
    - Time Complexity: O(V + E)

## Main Method Organization

The `main()` function:

1. **Example Graph Creation**:
   - Creates a 6-vertex graph
   - Adds edges to form:
     ```
     0 --- 1 --- 2
     |     |     |
     3 --- 4 --- 5
     ```

2. **Demonstration**:
   - Displays adjacency matrix
   - Performs BFS from vertices 0 and 2
   - Performs DFS (recursive) from vertices 0 and 2
   - Performs DFS (iterative) from vertex 0
   - Checks graph connectivity

3. **Interactive Mode**:
   - User creates custom graph
   - Choose traversal method
   - Select starting vertex
   - Check connectivity
   - Display graph structure

## Algorithm Comparison

### BFS vs DFS

| Feature | BFS | DFS |
|---------|-----|-----|
| Data Structure | Queue | Stack/Recursion |
| Exploration | Level by level | Deep first |
| Path | Shortest path | Any path |
| Memory | Higher | Lower (usually) |
| Use Case | Shortest path, level-order | Cycle detection, topological sort |

## Sample Output

```
=========================================
  GRAPH TRAVERSAL (BFS & DFS)
  Using Adjacency Matrix
=========================================

Creating example graph with 6 vertices:

Graph Structure:
    0 --- 1 --- 2
    |     |     |
    3 --- 4 --- 5

Adjacency Matrix:
    0  1  2  3  4  5 
 0:  0  1  0  1  0  0 
 1:  1  0  1  0  1  0 
 2:  0  1  0  0  0  1 
 3:  1  0  0  0  1  0 
 4:  0  1  0  1  0  1 
 5:  0  0  1  0  1  0 

BFS Traversal starting from vertex 0:
0 1 3 2 4 5 

BFS Traversal starting from vertex 2:
2 1 5 0 4 3 

DFS Traversal (Recursive) starting from vertex 0:
0 1 2 5 4 3 

DFS Traversal (Recursive) starting from vertex 2:
2 1 0 3 4 5 

DFS Traversal (Iterative) starting from vertex 0:
0 1 2 5 4 3 

Graph is connected

=========================================
Create your own graph:
=========================================
Enter number of vertices (1-20): 4
Enter number of edges: 4
Enter edges (source destination):
Edge 1: 0 1
Edge 2: 1 2
Edge 3: 2 3
Edge 4: 3 0

Adjacency Matrix:
    0  1  2  3 
 0:  0  1  0  1 
 1:  1  0  1  0 
 2:  0  1  0  1 
 3:  1  0  1  0 

1. BFS Traversal
2. DFS Traversal (Recursive)
3. DFS Traversal (Iterative)
4. Check if connected
5. Display graph
6. Exit
Enter choice: 1
Enter starting vertex: 0

BFS Traversal starting from vertex 0:
0 1 3 2 

Enter choice: 2
Enter starting vertex: 0

DFS Traversal (Recursive) starting from vertex 0:
0 1 2 3 

Enter choice: 6
Exiting...
```

## Compilation and Execution

```bash
gcc prog_5.c -o prog_5
./prog_5
```

## Key Concepts

### Adjacency Matrix Representation
- **Space**: O(V²) - requires space for all possible edges
- **Edge lookup**: O(1) - direct array access
- **Good for**: Dense graphs, frequent edge queries
- **Bad for**: Sparse graphs (wastes space)

### Applications
- **BFS**: Shortest path, web crawling, social networks
- **DFS**: Maze solving, cycle detection, topological sorting
- **Connectivity**: Network analysis, cluster detection

### Graph Properties
- **Connected Graph**: All vertices are reachable from any vertex
- **Undirected Graph**: Edges have no direction
- **Degree**: Number of edges connected to a vertex