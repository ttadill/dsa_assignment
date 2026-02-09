#include <stdio.h>
#include <stdlib.h>

// Node structure for doubly linked list
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the beginning
void insertAtBeginning(Node **head, int data) {
    Node *newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}

// Function to insert at the end
void insertAtEnd(Node **head, int data) {
    Node *newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to find a node with given data
Node* findNode(Node *head, int data) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to insert after a given node
void insertAfterNode(Node **head, int targetData, int newData) {
    // Find the target node
    Node *targetNode = findNode(*head, targetData);
    
    if (targetNode == NULL) {
        printf("Node with data %d not found!\n", targetData);
        return;
    }
    
    Node *newNode = createNode(newData);
    
    // Update links
    newNode->next = targetNode->next;
    newNode->prev = targetNode;
    
    if (targetNode->next != NULL) {
        targetNode->next->prev = newNode;
    }
    
    targetNode->next = newNode;
    
    printf("Inserted %d after node with value %d\n", newData, targetData);
}

// Function to insert before a given node
void insertBeforeNode(Node **head, int targetData, int newData) {
    Node *targetNode = findNode(*head, targetData);
    
    if (targetNode == NULL) {
        printf("Node with data %d not found!\n", targetData);
        return;
    }
    
    Node *newNode = createNode(newData);
    
    newNode->prev = targetNode->prev;
    newNode->next = targetNode;
    
    if (targetNode->prev != NULL) {
        targetNode->prev->next = newNode;
    } else {
        *head = newNode;  // New node becomes head
    }
    
    targetNode->prev = newNode;
    
    printf("Inserted %d before node with value %d\n", newData, targetData);
}

// Function to delete a specific node
void deleteNode(Node **head, int data) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    Node *targetNode = findNode(*head, data);
    
    if (targetNode == NULL) {
        printf("Node with data %d not found!\n", data);
        return;
    }
    
    // If node to be deleted is head
    if (targetNode == *head) {
        *head = targetNode->next;
    }
    
    // Update previous node's next pointer
    if (targetNode->prev != NULL) {
        targetNode->prev->next = targetNode->next;
    }
    
    // Update next node's prev pointer
    if (targetNode->next != NULL) {
        targetNode->next->prev = targetNode->prev;
    }
    
    printf("Deleted node with value %d\n", data);
    free(targetNode);
}

// Function to display list forward
void displayForward(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    printf("Forward: NULL <-> ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf(" <-> NULL\n");
}

// Function to display list backward
void displayBackward(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    // Go to last node
    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    printf("Backward: NULL <-> ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->prev != NULL) {
            printf(" <-> ");
        }
        temp = temp->prev;
    }
    printf(" <-> NULL\n");
}

// Function to count nodes
int countNodes(Node *head) {
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to free the list
void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;
    
    printf("=========================================\n");
    printf("  DOUBLY LINKED LIST IMPLEMENTATION\n");
    printf("=========================================\n\n");
    
    // Create initial list
    printf("Creating doubly linked list with values: 10, 20, 30, 40, 50\n\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    printf("Initial List:\n");
    displayForward(head);
    displayBackward(head);
    printf("Number of nodes: %d\n\n", countNodes(head));
    
    // Demonstrate insert after node
    printf("-------------------------------------------\n");
    printf("Insert Operations:\n");
    printf("-------------------------------------------\n");
    insertAfterNode(&head, 30, 35);
    displayForward(head);
    printf("\n");
    
    insertAfterNode(&head, 50, 60);
    displayForward(head);
    printf("\n");
    
    insertBeforeNode(&head, 10, 5);
    displayForward(head);
    printf("\n");
    
    // Demonstrate delete operations
    printf("-------------------------------------------\n");
    printf("Delete Operations:\n");
    printf("-------------------------------------------\n");
    deleteNode(&head, 35);
    displayForward(head);
    printf("\n");
    
    deleteNode(&head, 5);
    displayForward(head);
    printf("\n");
    
    deleteNode(&head, 60);
    displayForward(head);
    displayBackward(head);
    printf("\n");
    
    // Interactive menu
    printf("-------------------------------------------\n");
    printf("Interactive Menu:\n");
    printf("-------------------------------------------\n");
    
    int choice, value, target;
    
    do {
        printf("\n1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert after node\n");
        printf("4. Insert before node\n");
        printf("5. Delete node\n");
        printf("6. Display forward\n");
        printf("7. Display backward\n");
        printf("8. Count nodes\n");
        printf("9. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                printf("Inserted %d at beginning\n", value);
                displayForward(head);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                printf("Inserted %d at end\n", value);
                displayForward(head);
                break;
            case 3:
                printf("Enter target node value: ");
                scanf("%d", &target);
                printf("Enter new value: ");
                scanf("%d", &value);
                insertAfterNode(&head, target, value);
                displayForward(head);
                break;
            case 4:
                printf("Enter target node value: ");
                scanf("%d", &target);
                printf("Enter new value: ");
                scanf("%d", &value);
                insertBeforeNode(&head, target, value);
                displayForward(head);
                break;
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                displayForward(head);
                break;
            case 6:
                displayForward(head);
                break;
            case 7:
                displayBackward(head);
                break;
            case 8:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 9:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 9);
    
    // Clean up
    freeList(head);
    
    return 0;
}