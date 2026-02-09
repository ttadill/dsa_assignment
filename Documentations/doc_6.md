# Program 6: Min and Max Heap Implementation

## Overview
This program builds minimum and maximum heaps from unsorted arrays using the heapify algorithm and provides insertion operations while maintaining heap properties.

## Data Structures

### MinHeap Structure
```c
typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;
```
- **data**: Array storing heap elements
- **size**: Current number of elements
- **Property**: Parent ≤ Children (minimum at root)

### MaxHeap Structure
```c
typedef struct {
    int data[MAX_SIZE];
    int size;
} MaxHeap;
```
- **data**: Array storing heap elements
- **size**: Current number of elements
- **Property**: Parent ≥ Children (maximum at root)

## Heap Representation
Heaps use **array-based complete binary tree** representation:
- **Parent of node i**: `(i-1)/2`
- **Left child of node i**: `2*i + 1`
- **Right child of node i**: `2*i + 2`

## Functions Implemented

### Utility Functions

1. **`int getParent(int i)`**
   - Returns parent index
   - Time Complexity: O(1)

2. **`int getLeftChild(int i)`**
   - Returns left child index
   - Time Complexity: O(1)

3. **`int getRightChild(int i)`**
   - Returns right child index
   - Time Complexity: O(1)

4. **`void swap(int *a, int *b)`**
   - Swaps two integers
   - Time Complexity: O(1)

### Min Heap Functions

5. **`void initMinHeap(MinHeap *h)`**
   - Initializes empty heap
   - Time Complexity: O(1)

6. **`void minHeapifyUp(MinHeap *h, int index)`**
   - **Used after**: Insertion
   - **Algorithm**:
     - Compare node with parent
     - If node < parent, swap
     - Move up and repeat
   - **Time Complexity**: O(log n)
   - Maintains min heap property upward

7. **`void minHeapifyDown(MinHeap *h, int index)`**
   - **Used after**: Deletion or during build
   - **Algorithm**:
     - Find smallest among node and children
     - If node is not smallest, swap with smallest child
     - Move down and repeat
   - **Time Complexity**: O(log n)
   - Maintains min heap property downward

8. **`void insertMinHeap(MinHeap *h, int value)`**
   - **Algorithm**:
     1. Add element at end
     2. Call heapifyUp to restore property
   - **Time Complexity**: O(log n)

9. **`void buildMinHeap(MinHeap *h, int arr[], int n)`**
   - **Algorithm** (Bottom-Up Heapification):
     1. Copy array to heap
     2. Start from last non-leaf node: `(n/2) - 1`
     3. Call heapifyDown for each node moving toward root
   - **Time Complexity**: O(n) [Not O(n log n)!]
   - **Why O(n)?**: Most nodes are near bottom with short heapify paths

### Max Heap Functions

10. **`void initMaxHeap(MaxHeap *h)`**
    - Initializes empty heap

11. **`void maxHeapifyUp(MaxHeap *h, int index)`**
    - Similar to minHeapifyUp but maintains max property
    - Swaps if node > parent
    - Time Complexity: O(log n)

12. **`void maxHeapifyDown(MaxHeap *h, int index)`**
    - Similar to minHeapifyDown but maintains max property
    - Swaps with larger child
    - Time Complexity: O(log n)

13. **`void insertMaxHeap(MaxHeap *h, int value)`**
    - Inserts value maintaining max heap property
    - Time Complexity: O(log n)

14. **`void buildMaxHeap(MaxHeap *h, int arr[], int n)`**
    - Builds max heap from array
    - Time Complexity: O(n)

### Display Functions

15. **`void displayMinHeap(MinHeap *h)`**
    - Displays heap as array

16. **`void displayMaxHeap(MaxHeap *h)`**
    - Displays heap as array

17. **`void displayHeapTree(int heap[], int size, char *type)`**
    - Displays heap in level-order tree format
    - Shows tree structure visually

### Verification Functions

18. **`bool verifyMinHeap(MinHeap *h)`**
    - Validates min heap property
    - Checks all parent-child relationships
    - Time Complexity: O(n)

19. **`bool verifyMaxHeap(MaxHeap *h)`**
    - Validates max heap property
    - Time Complexity: O(n)

## Main Method Organization

The `main()` function:

1. **Test Cases**:
   - Three different unsorted arrays
   - Builds both min and max heaps from each
   - Displays results and verifies properties

2. **Demonstrations**:
   - Shows original array
   - Builds and displays min heap
   - Shows tree structure
   - Verifies heap property
   - Repeats for max heap

3. **Interactive Mode**:
   - User provides array elements
   - Build min/max heap
   - Insert new elements
   - Display current state

## Algorithm Explanation

### Build Heap Algorithm
```
buildMinHeap(arr, n):
    1. Copy array to heap structure
    2. For i = (n/2 - 1) down to 0:
       minHeapifyDown(i)
```

**Why start from (n/2 - 1)?**
- Nodes from n/2 to n-1 are leaf nodes
- Leaf nodes are already valid heaps
- Start from last non-leaf node

### Time Complexity Analysis
- **Build Heap**: O(n)
  - NOT O(n log n) because most nodes have short paths
  - Mathematical proof: Σ(h * 2^h) where h = height
- **Insert**: O(log n)
- **Heapify**: O(log n)

## Sample Output

```
=========================================
  MIN HEAP AND MAX HEAP IMPLEMENTATION
=========================================

Test Case 1:
-------------------------------------------
Original Array: 15 10 20 8 12 25 6 

Min Heap: 6 8 16 10 12 25 20 

Min Heap Tree Structure:
-------------------------------------------
Level 0: 6 
Level 1: 8 16 
Level 2: 10 12 25 20 
-------------------------------------------
Min Heap Valid: YES

Max Heap: 25 12 20 8 10 15 6 

Max Heap Tree Structure:
-------------------------------------------
Level 0: 25 
Level 1: 12 20 
Level 2: 8 10 15 6 
-------------------------------------------
Max Heap Valid: YES

Test Case 2:
-------------------------------------------
Original Array: 4 10 3 5 1 

Min Heap: 1 4 3 5 10 

Min Heap Tree Structure:
-------------------------------------------
Level 0: 1 
Level 1: 4 3 
Level 2: 5 10 
-------------------------------------------

Max Heap: 10 5 3 4 1 

Max Heap Tree Structure:
-------------------------------------------
Level 0: 10 
Level 1: 5 3 
Level 2: 4 1 
-------------------------------------------

Test Case 3:
-------------------------------------------
Original Array: 50 30 20 15 10 8 16 

Min Heap: 8 10 16 15 30 20 50 
Max Heap: 50 30 20 15 10 8 16 

=========================================
Create your own heap:
=========================================
Enter number of elements: 5
Enter 5 elements:
9 5 3 7 1

1. Build Min Heap
2. Build Max Heap
3. Insert into Min Heap
4. Insert into Max Heap
5. Display heaps
6. Exit
Enter choice: 1
Min Heap built successfully!
Min Heap: 1 5 3 7 9 

Min Heap Tree Structure:
-------------------------------------------
Level 0: 1 
Level 1: 5 3 
Level 2: 7 9 
-------------------------------------------

Enter choice: 2
Max Heap built successfully!
Max Heap: 9 7 3 5 1 

Max Heap Tree Structure:
-------------------------------------------
Level 0: 9 
Level 1: 7 3 
Level 2: 5 1 
-------------------------------------------

Enter choice: 6
Exiting...
```

## Compilation and Execution

```bash
gcc prog_6.c -o prog_6
./prog_6
```

## Visual Example

**Array**: [15, 10, 20, 8, 12, 25, 6]

**Min Heap Tree**:
```
       6
      / \
     8   16
    / \ / \
   10 12 25 20
```

**Max Heap Tree**:
```
       25
      /  \
     12   20
    / \   / \
   8  10 15  6
```

## Applications
- **Min Heap**: 
  - Priority queue (minimum priority)
  - Dijkstra's shortest path
  - Heap sort (ascending)
  
- **Max Heap**:
  - Priority queue (maximum priority)
  - Heap sort (descending)
  - Finding k largest elements

## Key Concepts
- **Complete Binary Tree**: All levels filled except possibly last
- **Heap Property**: Relationship between parent and children
- **In-place Algorithm**: Builds heap without extra space
- **O(n) Build Time**: More efficient than repeated insertions