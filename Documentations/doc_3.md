# Program 3: Reverse Traversal of Linked List

## Overview
This program implements reverse traversal algorithms for singly linked lists using both recursive and iterative approaches, and also demonstrates actual list reversal.

## Data Structures

### Node Structure
```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;
```
- **data**: Integer value stored in the node
- **next**: Pointer to the next node in the list

## Functions Implemented

### Basic Linked List Operations

1. **`Node* createNode(int data)`**
   - Allocates memory for a new node
   - Initializes data and next pointer
   - Returns pointer to new node
   - Time Complexity: O(1)

2. **`void insertAtEnd(Node **head, int data)`**
   - Inserts a new node at the end of the list
   - Updates head if list is empty
   - Time Complexity: O(n) where n is number of nodes

3. **`void displayForward(Node *head)`**
   - Displays list from head to tail
   - Time Complexity: O(n)

4. **`int countNodes(Node *head)`**
   - Counts total number of nodes
   - Time Complexity: O(n)

5. **`void freeList(Node *head)`**
   - Frees all allocated memory
   - Time Complexity: O(n)

### Reverse Traversal Functions

6. **`void displayReverseRecursive(Node *head)`**
   - **Algorithm**:
     1. Base case: if node is NULL, return
     2. Recursively call for next node
     3. Print current node data
   - Uses call stack for backtracking
   - Time Complexity: O(n)
   - Space Complexity: O(n) due to recursion stack

7. **`void displayReverse(Node *head)`**
   - Wrapper function for recursive reverse display
   - Handles NULL list case
   - Adds formatting

8. **`void displayReverseIterative(Node *head)`**
   - **Algorithm**:
     1. Count total nodes
     2. Store all values in array
     3. Print array in reverse order
   - Time Complexity: O(n)
   - Space Complexity: O(n) for array storage

### List Reversal Function

9. **`Node* reverseList(Node *head)`**
   - **Algorithm** (Iterative approach):
     1. Initialize three pointers: prev=NULL, current=head, next=NULL
     2. Traverse the list:
        - Save next node
        - Reverse current node's link
        - Move prev and current one step forward
     3. Return prev as new head
   - Time Complexity: O(n)
   - Space Complexity: O(1)
   - **This actually reverses the list, not just displays it in reverse**

## Main Method Organization

The `main()` function demonstrates:
1. **Initialization**:
   - Creates empty list
   - Inserts sample values: 10, 20, 30, 40, 50

2. **Display Operations**:
   - Shows original list
   - Displays count of nodes

3. **Reverse Traversal Demonstrations**:
   - Recursive method
   - Iterative method (using array)

4. **List Reversal**:
   - Reverses actual list structure
   - Displays reversed list
   - Reverses back to original

5. **Interactive Menu**:
   - Insert elements
   - Display in both directions
   - Reverse the list
   - Exit option

## Algorithm Comparison

### Recursive Reverse Traversal
**Advantages**:
- Clean, simple code
- No extra data structure needed

**Disadvantages**:
- Uses system call stack
- Risk of stack overflow for very large lists
- Overhead of function calls

### Iterative Reverse Traversal
**Advantages**:
- No recursion overhead
- More control over execution

**Disadvantages**:
- Requires extra array storage
- Two passes through list

### Actual List Reversal
**Advantages**:
- Changes list permanently
- O(1) space complexity
- Efficient for repeated reverse access

**Disadvantages**:
- Modifies original structure
- Requires reversal again to restore

## Sample Output

```
=========================================
  LINKED LIST REVERSE TRAVERSAL
=========================================

Creating linked list with values: 10, 20, 30, 40, 50

Original Linked List:
Forward: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
Number of nodes: 5

Reverse Traversal Methods:
-------------------------------------------
Reverse (Recursive): NULL <- 50 <- 40 <- 30 <- 20 <- 10
Reverse (Iterative): NULL <- 50 <- 40 <- 30 <- 20 <- 10

Reversing the actual linked list...
After reversal:
Forward: 50 -> 40 -> 30 -> 20 -> 10 -> NULL

Reversing back to original order...
After reversal:
Forward: 10 -> 20 -> 30 -> 40 -> 50 -> NULL

-------------------------------------------
Add your own elements:

1. Insert element
2. Display forward
3. Display reverse (Recursive)
4. Display reverse (Iterative)
5. Reverse the list
6. Exit
Enter choice: 1
Enter value to insert: 60
Inserted 60

Enter choice: 2
Forward: 10 -> 20 -> 30 -> 40 -> 50 -> 60 -> NULL

Enter choice: 3
Reverse (Recursive): NULL <- 60 <- 50 <- 40 <- 30 <- 20 <- 10

Enter choice: 6
Exiting...
```

## Compilation and Execution

```bash
gcc prog_3.c -o prog_3
./prog_3
```

## Key Concepts
- **Traversal**: Visiting nodes without modifying structure
- **Reversal**: Changing the actual links between nodes
- **Recursion**: Uses implicit stack (call stack)
- **Iteration**: Uses explicit data structure (array)
- Three different approaches to achieve reverse order display