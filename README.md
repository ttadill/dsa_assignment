# Data Structures and Algorithms Assignment

**Student Name**: Tadillata Bhandari  
**CS-I (II/I)**  
**Roll no.**: 12  
**Course**: COMP202 - Data Structures and Algorithms  
**Repository**: `dsa_assignment`

## Overview

This repository contains 8 comprehensive programs implementing various data structures and algorithms, including stacks, queues, linked lists, graphs, heaps, and sorting algorithms. Each program comes with detailed documentation and demonstrates best practices in C programming.

## Repository Structure

```
dsa_assignment/
│
├── Documentation/
│   ├── doc_1.md                 # Documentation for Program 1 (Balanced Parentheses)
│   ├── doc_2.md                 # Documentation for Program 2 (Infix to Postfix)
│   ├── doc_3.md                 # Documentation for Program 3 (List Reversal)
│   ├── doc_4.md                 # Documentation for Program 4 (Doubly Linked List)
│   ├── doc_5.md                 # Documentation for Program 5 (Graph Traversal)
│   ├── doc_6.md                 # Documentation for Program 6 (Heap Implementation)
│   ├── doc_7.md                 # Documentation for Program 7 (Dijkstra's Algorithm)
│   └── doc_8.md                 # Documentation for Program 8 (Sorting Algorithms)
│
├── Programs/
│   ├── prog_1.c                 # Balanced Parentheses Checker
│   ├── prog_2.c                 # Infix to Postfix Converter & Evaluator
│   ├── prog_3.c                 # Linked List Reverse Traversal
│   ├── prog_4.c                 # Doubly Linked List Implementation
│   ├── prog_5.c                 # Graph BFS and DFS Traversal
│   ├── prog_6.c                 # Min and Max Heap Implementation
│   ├── prog_7.c                 # Dijkstra's Shortest Path Algorithm
│   └── prog_8.c                 # Sorting Algorithms Comparison
│
└── README.md                    # Main project overview

```

## Documentation

Each program has a corresponding `doc_<q>.md` file containing:
- Data structure definitions
- Function descriptions and purposes
- Algorithm explanations
- Main method organization
- Sample outputs
- Compilation instructions
- Time and space complexity analysis

## Programs Overview

### Program 1: Balanced Parentheses Checker
**File**: `prog_1.c`  
**Topic**: Stack Data Structure  
**Features**:
- Checks if mathematical expressions have balanced parentheses
- Supports three types of brackets: (), [], {}
- Tests expressions from assignment
- Interactive mode for custom input

### Program 2: Infix to Postfix Converter and Evaluator
**File**: `prog_2.c`  
**Topic**: Stack, Expression Conversion  
**Features**:
- Converts infix expressions to postfix notation
- Evaluates postfix expressions
- Implements Shunting Yard Algorithm
- Handles operator precedence and associativity

### Program 3: Linked List Reverse Traversal
**File**: `prog_3.c`  
**Topic**: Singly Linked List  
**Features**:
- Three methods for reverse traversal:
  - Recursive approach
  - Iterative approach (using array)
  - Actual list reversal
- Interactive menu for operations
- Demonstrates recursion vs iteration

### Program 4: Doubly Linked List Implementation
**File**: `prog_4.c`  
**Topic**: Doubly Linked List  
**Features**:
- Insert after/before given node
- Delete specific node
- Forward and backward traversal
- Handles edge cases (head, tail, middle nodes)

### Program 5: Graph Traversal (BFS & DFS)
**File**: `prog_5.c`  
**Topic**: Graphs, Adjacency Matrix  
**Features**:
- Undirected graph implementation
- Breadth-First Search (BFS)
- Depth-First Search (DFS) - Recursive and Iterative
- Graph connectivity checking
- Interactive graph creation

### Program 6: Min and Max Heap
**File**: `prog_6.c`  
**Topic**: Heap Data Structure  
**Features**:
- Build min heap from unsorted array
- Build max heap from unsorted array
- Insert operations maintaining heap property
- Visual tree structure display
- Heap property verification

### Program 7: Dijkstra's Shortest Path Algorithm
**File**: `prog_7.c`  
**Topic**: Weighted Graphs, Shortest Path  
**Features**:
- Finds shortest path from source to all nodes
- Step-by-step algorithm execution display
- Path reconstruction
- Works with weighted undirected graphs
- Interactive graph creation

### Program 8: Sorting Algorithms Comparison
**File**: `prog_8.c`  
**Topic**: Sorting Algorithms, Algorithm Analysis  
**Features**:
- Four sorting algorithms:
  - Bubble Sort
  - Selection Sort
  - Insertion Sort
  - Merge Sort
- Performance statistics (comparisons, swaps, time)
- Random array generation
- Side-by-side comparison mode
- User-specified array size

## Key Features

### Code Quality
- ✅ Modular design with clear function separation
- ✅ Comprehensive error handling
- ✅ Memory leak prevention (proper allocation/deallocation)
- ✅ Input validation
- ✅ Meaningful variable and function names
- ✅ Consistent coding style

### Documentation Quality
- ✅ Detailed algorithm explanations
- ✅ Time and space complexity analysis
- ✅ Visual representations where applicable
- ✅ Sample outputs from actual program runs
- ✅ Use cases and applications
- ✅ Comparison with alternative approaches

### Educational Value
- ✅ Interactive modes for hands-on learning
- ✅ Step-by-step algorithm execution display
- ✅ Multiple approaches to same problem
- ✅ Performance comparison tools
- ✅ Verification and testing functions

## Data Structures Covered

1. **Stack** - Programs 1, 2
2. **Queue** - Program 5 (BFS)
3. **Singly Linked List** - Program 3
4. **Doubly Linked List** - Program 4
5. **Graph (Adjacency Matrix)** - Programs 5, 7
6. **Binary Heap** - Program 6
7. **Arrays** - Program 8

## Algorithms Covered

1. **Balanced Parentheses** - Stack-based validation
2. **Infix to Postfix** - Shunting Yard Algorithm
3. **Expression Evaluation** - Postfix evaluation
4. **List Reversal** - Recursive and iterative
5. **BFS** - Level-order graph traversal
6. **DFS** - Depth-first graph traversal (recursive and iterative)
7. **Heapify** - Building min/max heaps (O(n) bottom-up)
8. **Dijkstra's Algorithm** - Single-source shortest path
9. **Bubble Sort** - O(n²) comparison-based
10. **Selection Sort** - O(n²) with minimal swaps
11. **Insertion Sort** - O(n²) adaptive sorting
12. **Merge Sort** - O(n log n) divide-and-conquer

## Complexity Summary

| Program | Algorithm | Time Complexity | Space Complexity |
|---------|-----------|-----------------|------------------|
| 1 | Balanced Parentheses | O(n) | O(n) |
| 2 | Infix to Postfix | O(n) | O(n) |
| 2 | Postfix Evaluation | O(n) | O(n) |
| 3 | List Reversal | O(n) | O(n) or O(1) |
| 4 | DLL Insert/Delete | O(n) | O(1) |
| 5 | BFS/DFS | O(V + E) | O(V) |
| 6 | Build Heap | O(n) | O(1) |
| 7 | Dijkstra | O(V²) | O(V) |
| 8 | Merge Sort | O(n log n) | O(n) |
| 8 | Bubble/Selection/Insertion | O(n²) | O(1) |

## Additional Resources

For more information on:
- C programming: https://en.cppreference.com/
- Data structures: Course textbook and lecture notes
- Algorithm analysis: Course materials


**Note**: This README and all associated files represent the complete submission for DSA Assignment.
