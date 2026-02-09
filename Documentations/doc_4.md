# Program 4: Doubly Linked List Implementation

## Overview
This program implements a doubly linked list with operations to insert after/before a given node and delete nodes. It demonstrates bidirectional traversal and efficient operations.

## Data Structures

### Node Structure
```c
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;
```
- **data**: Integer value stored in the node
- **prev**: Pointer to the previous node (NULL for head)
- **next**: Pointer to the next node (NULL for tail)

### Advantages of Doubly Linked List
- Bidirectional traversal (forward and backward)
- Efficient deletion (no need to traverse to find previous node)
- Easy insertion before a given node
- Can start traversal from either end

## Functions Implemented

### Basic Operations

1. **`Node* createNode(int data)`**
   - Allocates memory for new node
   - Initializes data, prev, and next pointers
   - Time Complexity: O(1)

2. **`void insertAtBeginning(Node **head, int data)`**
   - Inserts node at the start
   - Updates head pointer
   - Time Complexity: O(1)

3. **`void insertAtEnd(Node **head, int data)`**
   - Inserts node at the end
   - Requires traversal to find last node
   - Time Complexity: O(n)

4. **`Node* findNode(Node *head, int data)`**
   - Searches for a node with given data
   - Returns pointer to node or NULL
   - Time Complexity: O(n)

### Insert Operations (Required by Assignment)

5. **`void insertAfterNode(Node **head, int targetData, int newData)`**
   - **Algorithm**:
     1. Find the target node
     2. Create new node
     3. Set new node's next to target's next
     4. Set new node's prev to target
     5. Update target's next to new node
     6. If target wasn't last, update next node's prev
   - **Time Complexity**: O(n) for search + O(1) for insertion
   - **Handles edge cases**:
     - Target is last node
     - List is empty
     - Target not found

6. **`void insertBeforeNode(Node **head, int targetData, int newData)`**
   - **Algorithm**:
     1. Find the target node
     2. Create new node
     3. Set new node's prev to target's prev
     4. Set new node's next to target
     5. If target has previous, update its next
     6. Otherwise, update head pointer
     7. Update target's prev to new node
   - **Time Complexity**: O(n) for search + O(1) for insertion
   - **Handles edge cases**:
     - Target is head
     - List is empty
     - Target not found

### Delete Operation (Required by Assignment)

7. **`void deleteNode(Node **head, int data)`**
   - **Algorithm**:
     1. Find the node to delete
     2. If node is head, update head pointer
     3. Update previous node's next pointer
     4. Update next node's prev pointer
     5. Free the node
   - **Time Complexity**: O(n) for search + O(1) for deletion
   - **Handles edge cases**:
     - Deleting head node
     - Deleting tail node
     - Deleting middle node
     - Empty list
     - Node not found

### Display Operations

8. **`void displayForward(Node *head)`**
   - Traverses from head to tail
   - Shows bidirectional links
   - Time Complexity: O(n)

9. **`void displayBackward(Node *head)`**
   - First reaches tail, then traverses backward
   - Demonstrates backward traversal capability
   - Time Complexity: O(n)

10. **`int countNodes(Node *head)`**
    - Counts total nodes in list
    - Time Complexity: O(n)

11. **`void freeList(Node *head)`**
    - Deallocates all nodes
    - Time Complexity: O(n)

## Main Method Organization

The `main()` function is organized as follows:

1. **Initialization**:
   - Creates empty list
   - Inserts initial values: 10, 20, 30, 40, 50

2. **Insert Demonstrations**:
   - Insert 35 after node 30
   - Insert 60 after node 50 (last node)
   - Insert 5 before node 10 (head node)

3. **Delete Demonstrations**:
   - Delete node 35 (middle)
   - Delete node 5 (head)
   - Delete node 60 (tail)

4. **Interactive Menu**:
   - Insert at beginning/end
   - Insert after/before specific node
   - Delete specific node
   - Display in both directions
   - Count nodes
   - Exit

## Memory Structure Visualization

```
Initial List: 10 <-> 20 <-> 30 <-> 40 <-> 50

After insertAfterNode(30, 35):
10 <-> 20 <-> 30 <-> 35 <-> 40 <-> 50

After insertBeforeNode(10, 5):
5 <-> 10 <-> 20 <-> 30 <-> 35 <-> 40 <-> 50

After deleteNode(35):
5 <-> 10 <-> 20 <-> 30 <-> 40 <-> 50
```

## Sample Output

```
=========================================
  DOUBLY LINKED LIST IMPLEMENTATION
=========================================

Creating doubly linked list with values: 10, 20, 30, 40, 50

Initial List:
Forward: NULL <-> 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL
Backward: NULL <-> 50 <-> 40 <-> 30 <-> 20 <-> 10 <-> NULL
Number of nodes: 5

-------------------------------------------
Insert Operations:
-------------------------------------------
Inserted 35 after node with value 30
Forward: NULL <-> 10 <-> 20 <-> 30 <-> 35 <-> 40 <-> 50 <-> NULL

Inserted 60 after node with value 50
Forward: NULL <-> 10 <-> 20 <-> 30 <-> 35 <-> 40 <-> 50 <-> 60 <-> NULL

Inserted 5 before node with value 10
Forward: NULL <-> 5 <-> 10 <-> 20 <-> 30 <-> 35 <-> 40 <-> 50 <-> 60 <-> NULL

-------------------------------------------
Delete Operations:
-------------------------------------------
Deleted node with value 35
Forward: NULL <-> 5 <-> 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> 60 <-> NULL

Deleted node with value 5
Forward: NULL <-> 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> 60 <-> NULL

Deleted node with value 60
Forward: NULL <-> 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> NULL
Backward: NULL <-> 50 <-> 40 <-> 30 <-> 20 <-> 10 <-> NULL

-------------------------------------------
Interactive Menu:
-------------------------------------------

1. Insert at beginning
2. Insert at end
3. Insert after node
4. Insert before node
5. Delete node
6. Display forward
7. Display backward
8. Count nodes
9. Exit
Enter choice: 3
Enter target node value: 30
Enter new value: 35
Inserted 35 after node with value 30
Forward: NULL <-> 10 <-> 20 <-> 30 <-> 35 <-> 40 <-> 50 <-> NULL

Enter choice: 9
Exiting...
```

## Compilation and Execution

```bash
gcc prog_4.c -o prog_4
./prog_4
```

## Comparison: Singly vs Doubly Linked List

| Feature | Singly Linked List | Doubly Linked List |
|---------|-------------------|-------------------|
| Memory per node | 1 pointer | 2 pointers |
| Backward traversal | Not possible | Possible |
| Deletion (with node pointer) | O(n) | O(1) |
| Insert before node | O(n) | O(1) with node pointer |
| Space overhead | Less | More |

## Key Concepts
- Each node maintains links to both neighbors
- Easier deletion without needing previous node
- More memory overhead than singly linked list
- Better for scenarios requiring bidirectional traversal
- Efficient insert before operation