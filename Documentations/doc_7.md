# Program 7: Dijkstra's Shortest Path Algorithm

## Overview
This program implements Dijkstra's algorithm to find the shortest path from a source node to all other nodes in a weighted graph using an adjacency matrix representation.

## Data Structures

### WeightedGraph Structure
```c
typedef struct {
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} WeightedGraph;
```
- **numVertices**: Total number of vertices
- **adjMatrix**: 2D array storing edge weights
  - adjMatrix[i][j] = weight of edge from i to j
  - adjMatrix[i][j] = INF if no edge exists
  - adjMatrix[i][i] = 0 (distance to self)

### Supporting Data Structures
- **dist[]**: Stores shortest distance from source to each vertex
- **visited[]**: Tracks processed vertices
- **parent[]**: Stores the shortest path tree (for path reconstruction)

## Algorithm Overview

Dijkstra's algorithm finds shortest paths using a **greedy approach**:
1. Start with source vertex, mark distance as 0
2. Repeatedly select unvisited vertex with minimum distance
3. Update distances to its neighbors
4. Continue until all vertices are processed

**Key Property**: Works only with **non-negative edge weights**

## Functions Implemented

### Graph Operations

1. **`void initGraph(WeightedGraph *g, int vertices)`**
   - Initializes graph with given vertices
   - Sets all weights to INF except self-edges (0)
   - Time Complexity: O(V²)

2. **`void addEdge(WeightedGraph *g, int src, int dest, int weight)`**
   - Adds weighted edge between vertices
   - For undirected graph, adds in both directions
   - Warns if negative weight (invalid for Dijkstra)
   - Time Complexity: O(1)

3. **`void displayGraph(WeightedGraph *g)`**
   - Displays weighted adjacency matrix
   - Shows INF for non-existent edges
   - Time Complexity: O(V²)

### Dijkstra's Algorithm Functions

4. **`int findMinDistance(int dist[], bool visited[], int n)`**
   - Finds unvisited vertex with minimum distance
   - **Linear search** implementation
   - Time Complexity: O(V)
   - **Optimization possible**: Use min-heap for O(log V)

5. **`void printPath(int parent[], int vertex)`**
   - Recursively prints path from source to vertex
   - Uses parent array to backtrack
   - Time Complexity: O(V)

6. **`void dijkstra(WeightedGraph *g, int source)`**
   - **Main Algorithm Implementation**
   - **Algorithm Steps**:
     ```
     1. Initialize:
        - dist[source] = 0
        - dist[all others] = INF
        - All vertices unvisited
     
     2. Repeat V-1 times:
        a. Find unvisited vertex u with min dist[u]
        b. Mark u as visited
        c. For each unvisited neighbor v of u:
           if dist[u] + weight(u,v) < dist[v]:
              dist[v] = dist[u] + weight(u,v)
              parent[v] = u
     
     3. Output shortest paths and distances
     ```
   - **Time Complexity**: O(V²) with array
     - V iterations of findMinDistance: O(V²)
     - Edge relaxation: O(E)
     - Total: O(V²)
   - **Space Complexity**: O(V) for arrays
   - **With Min-Heap**: O((V + E) log V)

7. **`void displayAllPaths(WeightedGraph *g, int source)`**
   - Compact display of all shortest paths
   - Shows distance and path for each destination
   - Time Complexity: O(V²)

## Main Method Organization

The `main()` function:

1. **Example Graph Demonstration**:
   - Creates 6-vertex weighted graph
   - Adds weighted edges
   - Displays graph structure visually
   - Shows adjacency matrix

2. **Algorithm Execution**:
   - Runs Dijkstra from vertex 0
   - Shows step-by-step execution
   - Displays final paths and distances
   - Runs from another source (vertex 2)

3. **Interactive Mode**:
   - User creates custom weighted graph
   - Inputs vertices and edges with weights
   - Select source vertex
   - View shortest paths

## Algorithm Execution Example

**Graph**:
```
       1
   (4)/ \(2)
     /   \
    0     2
   (1)\  /(3)
       3
      / \(1)
   (2)/   \
     4     5
      \(1)/
```

**Dijkstra from vertex 0**:

| Step | Selected | dist[0] | dist[1] | dist[2] | dist[3] | dist[4] | dist[5] |
|------|----------|---------|---------|---------|---------|---------|---------|
| 0    | -        | 0       | INF     | INF     | INF     | INF     | INF     |
| 1    | 0        | 0       | 4       | INF     | 1       | INF     | INF     |
| 2    | 3        | 0       | 4       | 4       | 1       | 3       | 2       |
| 3    | 5        | 0       | 4       | 4       | 1       | 3       | 2       |
| 4    | 4        | 0       | 4       | 4       | 1       | 3       | 2       |
| 5    | 1        | 0       | 4       | 4       | 1       | 3       | 2       |
| 6    | 2        | 0       | 4       | 4       | 1       | 3       | 2       |

## Sample Output

```
=========================================
  DIJKSTRA'S SHORTEST PATH ALGORITHM
=========================================

Example Graph with 6 vertices:

Graph Structure:
       1
   (4)/ \(2)
     /   \
    0     2
   (1)\  /(3)
       3
      / \(1)
   (2)/   \
     4     5
      \(1)/

Weighted Adjacency Matrix:
        0    1    2    3    4    5 
   0:    0    4  INF    1  INF  INF 
   1:    4    0    2  INF  INF  INF 
   2:  INF    2    0    3  INF  INF 
   3:    1  INF    3    0    2    1 
   4:  INF  INF  INF    2    0    1 
   5:  INF  INF  INF    1    1    0 

===========================================
Dijkstra's Algorithm - Step by Step
===========================================
Source Vertex: 0

Step 1: Selected vertex 0 (distance: 0)
  -> Updated vertex 1: INF to 4
  -> Updated vertex 3: INF to 1

Step 2: Selected vertex 3 (distance: 1)
  -> Updated vertex 2: INF to 4
  -> Updated vertex 4: INF to 3
  -> Updated vertex 5: INF to 2

Step 3: Selected vertex 5 (distance: 2)
  -> Updated vertex 4: 3 to 3

Step 4: Selected vertex 4 (distance: 3)

Step 5: Selected vertex 1 (distance: 4)

Step 6: Selected vertex 2 (distance: 4)

===========================================
Final Shortest Paths from Source 0:
===========================================
Vertex    Distance    Path
-------------------------------------------
   0         0       0
   1         4       0 -> 3 -> 5 -> 4 -> 1
   2         4       0 -> 3 -> 2
   3         1       0 -> 3
   4         3       0 -> 3 -> 4
   5         2       0 -> 3 -> 5
===========================================
```

## Compilation and Execution

```bash
gcc prog_7.c -o prog_7
./prog_7
```

## Time Complexity Analysis

### Current Implementation (Array-based)
- **findMinDistance**: O(V) per call
- **V iterations**: O(V²) total for finding minimum
- **Edge relaxation**: O(E) total
- **Overall**: O(V²)

### Optimized Implementation (Min-Heap)
- **Extract minimum**: O(log V)
- **V extractions**: O(V log V)
- **Decrease key**: O(log V)
- **E decrease keys**: O(E log V)
- **Overall**: O((V + E) log V)

For dense graphs (E ≈ V²), array is better: O(V²)
For sparse graphs (E << V²), heap is better: O(E log V)

## Comparison with Other Algorithms

| Algorithm | Graph Type | Time Complexity | Notes |
|-----------|-----------|-----------------|-------|
| Dijkstra | Non-negative weights | O(V²) or O((V+E)log V) | Greedy approach |
| Bellman-Ford | Any weights | O(VE) | Handles negative weights |
| Floyd-Warshall | All pairs | O(V³) | Finds all shortest paths |
| BFS | Unweighted | O(V+E) | Simple, fast for unweighted |

## Applications
- **GPS Navigation**: Finding shortest routes
- **Network Routing**: IP routing protocols (OSPF)
- **Social Networks**: Degrees of separation
- **Game AI**: Pathfinding for NPCs
- **Robotics**: Path planning

## Key Concepts
- **Greedy Algorithm**: Always picks locally optimal choice
- **Relaxation**: Updating distance if shorter path found
- **Non-negative Weights**: Critical requirement
- **Single-Source**: Finds paths from one source to all others
- **Optimal Substructure**: Shortest path contains shortest subpaths