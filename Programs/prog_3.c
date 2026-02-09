#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
typedef struct Node {
    int data;
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
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at the end
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
}

// Function to display linked list in forward direction
void displayForward(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    Node *temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" -> ");
        }
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

// Recursive function to display linked list in reverse
void displayReverseRecursive(Node *head) {
    if (head == NULL) {
        return;
    }
    
    // Recursively call for next node first
    displayReverseRecursive(head->next);
    
    // Then print current node
    printf("%d", head->data);
    if (head->next != NULL) {
        printf(" <- ");
    }
}

// Wrapper function for reverse display (recursive method)
void displayReverse(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    printf("Reverse (Recursive): NULL <- ");
    displayReverseRecursive(head);
    printf("\n");
}

// Iterative function to display in reverse using array
void displayReverseIterative(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    // Count nodes
    int count = 0;
    Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    // Store values in array
    int *arr = (int*)malloc(count * sizeof(int));
    temp = head;
    for (int i = 0; i < count; i++) {
        arr[i] = temp->data;
        temp = temp->next;
    }
    
    // Print in reverse
    printf("Reverse (Iterative): NULL <- ");
    for (int i = count - 1; i >= 0; i--) {
        printf("%d", arr[i]);
        if (i > 0) {
            printf(" <- ");
        }
    }
    printf("\n");
    
    free(arr);
}

// Function to reverse the linked list itself
Node* reverseList(Node *head) {
    Node *prev = NULL;
    Node *current = head;
    Node *next = NULL;
    
    while (current != NULL) {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse the link
        prev = current;        // Move prev forward
        current = next;        // Move current forward
    }
    
    return prev;  // New head
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

// Function to free the linked list
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
    printf("  LINKED LIST REVERSE TRAVERSAL\n");
    printf("=========================================\n\n");
    
    // Create a sample linked list
    printf("Creating linked list with values: 10, 20, 30, 40, 50\n\n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    
    // Display original list
    printf("Original Linked List:\n");
    displayForward(head);
    printf("Number of nodes: %d\n\n", countNodes(head));
    
    // Display in reverse using recursive method
    printf("Reverse Traversal Methods:\n");
    printf("-------------------------------------------\n");
    displayReverse(head);
    
    // Display in reverse using iterative method
    displayReverseIterative(head);
    
    printf("\n");
    
    // Demonstrate actual list reversal
    printf("Reversing the actual linked list...\n");
    head = reverseList(head);
    printf("After reversal:\n");
    displayForward(head);
    
    printf("\n");
    
    // Reverse back to original
    printf("Reversing back to original order...\n");
    head = reverseList(head);
    printf("After reversal:\n");
    displayForward(head);
    
    printf("\n");
    
    // Interactive section
    printf("-------------------------------------------\n");
    printf("Add your own elements:\n");
    int choice, value;
    
    do {
        printf("\n1. Insert element\n");
        printf("2. Display forward\n");
        printf("3. Display reverse (Recursive)\n");
        printf("4. Display reverse (Iterative)\n");
        printf("5. Reverse the list\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                printf("Inserted %d\n", value);
                break;
            case 2:
                displayForward(head);
                break;
            case 3:
                displayReverse(head);
                break;
            case 4:
                displayReverseIterative(head);
                break;
            case 5:
                head = reverseList(head);
                printf("List reversed!\n");
                displayForward(head);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 6);
    
    // Clean up
    freeList(head);
    
    return 0;
}