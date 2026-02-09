#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Min Heap Structure
typedef struct {
    int data[MAX_SIZE];
    int size;
} MinHeap;

// Max Heap Structure
typedef struct {
    int data[MAX_SIZE];
    int size;
} MaxHeap;

// ==================== MIN HEAP FUNCTIONS ====================

void initMinHeap(MinHeap *h) {
    h->size = 0;
}

// Get parent index
int getParent(int i) {
    return (i - 1) / 2;
}

// Get left child index
int getLeftChild(int i) {
    return 2 * i + 1;
}

// Get right child index
int getRightChild(int i) {
    return 2 * i + 2;
}

// Swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up for min heap (after insertion)
void minHeapifyUp(MinHeap *h, int index) {
    while (index > 0 && h->data[getParent(index)] > h->data[index]) {
        swap(&h->data[index], &h->data[getParent(index)]);
        index = getParent(index);
    }
}

// Heapify down for min heap (after deletion)
void minHeapifyDown(MinHeap *h, int index) {
    int smallest = index;
    int left = getLeftChild(index);
    int right = getRightChild(index);
    
    if (left < h->size && h->data[left] < h->data[smallest]) {
        smallest = left;
    }
    
    if (right < h->size && h->data[right] < h->data[smallest]) {
        smallest = right;
    }
    
    if (smallest != index) {
        swap(&h->data[index], &h->data[smallest]);
        minHeapifyDown(h, smallest);
    }
}

// Insert into min heap
void insertMinHeap(MinHeap *h, int value) {
    if (h->size >= MAX_SIZE) {
        printf("Heap is full!\n");
        return;
    }
    
    h->data[h->size] = value;
    minHeapifyUp(h, h->size);
    h->size++;
}

// Build min heap from array
void buildMinHeap(MinHeap *h, int arr[], int n) {
    if (n > MAX_SIZE) {
        printf("Array too large!\n");
        return;
    }
    
    // Copy array to heap
    for (int i = 0; i < n; i++) {
        h->data[i] = arr[i];
    }
    h->size = n;
    
    // Heapify from last non-leaf node to root
    for (int i = (n / 2) - 1; i >= 0; i--) {
        minHeapifyDown(h, i);
    }
}

// ==================== MAX HEAP FUNCTIONS ====================

void initMaxHeap(MaxHeap *h) {
    h->size = 0;
}

// Heapify up for max heap
void maxHeapifyUp(MaxHeap *h, int index) {
    while (index > 0 && h->data[getParent(index)] < h->data[index]) {
        swap(&h->data[index], &h->data[getParent(index)]);
        index = getParent(index);
    }
}

// Heapify down for max heap
void maxHeapifyDown(MaxHeap *h, int index) {
    int largest = index;
    int left = getLeftChild(index);
    int right = getRightChild(index);
    
    if (left < h->size && h->data[left] > h->data[largest]) {
        largest = left;
    }
    
    if (right < h->size && h->data[right] > h->data[largest]) {
        largest = right;
    }
    
    if (largest != index) {
        swap(&h->data[index], &h->data[largest]);
        maxHeapifyDown(h, largest);
    }
}

// Insert into max heap
void insertMaxHeap(MaxHeap *h, int value) {
    if (h->size >= MAX_SIZE) {
        printf("Heap is full!\n");
        return;
    }
    
    h->data[h->size] = value;
    maxHeapifyUp(h, h->size);
    h->size++;
}

// Build max heap from array
void buildMaxHeap(MaxHeap *h, int arr[], int n) {
    if (n > MAX_SIZE) {
        printf("Array too large!\n");
        return;
    }
    
    // Copy array to heap
    for (int i = 0; i < n; i++) {
        h->data[i] = arr[i];
    }
    h->size = n;
    
    // Heapify from last non-leaf node to root
    for (int i = (n / 2) - 1; i >= 0; i--) {
        maxHeapifyDown(h, i);
    }
}

// ==================== DISPLAY FUNCTIONS ====================

void displayMinHeap(MinHeap *h) {
    printf("Min Heap: ");
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->data[i]);
    }
    printf("\n");
}

void displayMaxHeap(MaxHeap *h) {
    printf("Max Heap: ");
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->data[i]);
    }
    printf("\n");
}

// Display heap in tree structure
void displayHeapTree(int heap[], int size, char *type) {
    printf("\n%s Heap Tree Structure:\n", type);
    printf("-------------------------------------------\n");
    
    if (size == 0) {
        printf("Empty heap\n");
        return;
    }
    
    int level = 0;
    int nodesInLevel = 1;
    int index = 0;
    
    while (index < size) {
        printf("Level %d: ", level);
        
        for (int i = 0; i < nodesInLevel && index < size; i++) {
            printf("%d ", heap[index]);
            index++;
        }
        printf("\n");
        
        level++;
        nodesInLevel *= 2;
    }
    printf("-------------------------------------------\n");
}

// Verify heap properties
bool verifyMinHeap(MinHeap *h) {
    for (int i = 0; i < h->size; i++) {
        int left = getLeftChild(i);
        int right = getRightChild(i);
        
        if (left < h->size && h->data[i] > h->data[left]) {
            return false;
        }
        if (right < h->size && h->data[i] > h->data[right]) {
            return false;
        }
    }
    return true;
}

bool verifyMaxHeap(MaxHeap *h) {
    for (int i = 0; i < h->size; i++) {
        int left = getLeftChild(i);
        int right = getRightChild(i);
        
        if (left < h->size && h->data[i] < h->data[left]) {
            return false;
        }
        if (right < h->size && h->data[i] < h->data[right]) {
            return false;
        }
    }
    return true;
}

int main() {
    printf("=========================================\n");
    printf("  MIN HEAP AND MAX HEAP IMPLEMENTATION\n");
    printf("=========================================\n\n");
    
    // Test arrays
    int arr1[] = {15, 10, 20, 8, 12, 25, 6};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    int arr2[] = {4, 10, 3, 5, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int arr3[] = {50, 30, 20, 15, 10, 8, 16};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    
    // Build Min Heap from first array
    printf("Test Case 1:\n");
    printf("-------------------------------------------\n");
    printf("Original Array: ");
    for (int i = 0; i < n1; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n\n");
    
    MinHeap minHeap1;
    initMinHeap(&minHeap1);
    buildMinHeap(&minHeap1, arr1, n1);
    
    displayMinHeap(&minHeap1);
    displayHeapTree(minHeap1.data, minHeap1.size, "Min");
    printf("Min Heap Valid: %s\n\n", verifyMinHeap(&minHeap1) ? "YES" : "NO");
    
    // Build Max Heap from first array
    MaxHeap maxHeap1;
    initMaxHeap(&maxHeap1);
    buildMaxHeap(&maxHeap1, arr1, n1);
    
    displayMaxHeap(&maxHeap1);
    displayHeapTree(maxHeap1.data, maxHeap1.size, "Max");
    printf("Max Heap Valid: %s\n\n", verifyMaxHeap(&maxHeap1) ? "YES" : "NO");
    
    // Test Case 2
    printf("Test Case 2:\n");
    printf("-------------------------------------------\n");
    printf("Original Array: ");
    for (int i = 0; i < n2; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n\n");
    
    MinHeap minHeap2;
    initMinHeap(&minHeap2);
    buildMinHeap(&minHeap2, arr2, n2);
    
    displayMinHeap(&minHeap2);
    displayHeapTree(minHeap2.data, minHeap2.size, "Min");
    
    MaxHeap maxHeap2;
    initMaxHeap(&maxHeap2);
    buildMaxHeap(&maxHeap2, arr2, n2);
    
    displayMaxHeap(&maxHeap2);
    displayHeapTree(maxHeap2.data, maxHeap2.size, "Max");
    printf("\n");
    
    // Test Case 3
    printf("Test Case 3:\n");
    printf("-------------------------------------------\n");
    printf("Original Array: ");
    for (int i = 0; i < n3; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n\n");
    
    MinHeap minHeap3;
    initMinHeap(&minHeap3);
    buildMinHeap(&minHeap3, arr3, n3);
    displayMinHeap(&minHeap3);
    
    MaxHeap maxHeap3;
    initMaxHeap(&maxHeap3);
    buildMaxHeap(&maxHeap3, arr3, n3);
    displayMaxHeap(&maxHeap3);
    printf("\n");
    
    // Interactive mode
    printf("=========================================\n");
    printf("Create your own heap:\n");
    printf("=========================================\n");
    
    int choice, n, value;
    int userArray[MAX_SIZE];
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid size!\n");
        return 1;
    }
    
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &userArray[i]);
    }
    
    MinHeap userMinHeap;
    MaxHeap userMaxHeap;
    
    do {
        printf("\n1. Build Min Heap\n");
        printf("2. Build Max Heap\n");
        printf("3. Insert into Min Heap\n");
        printf("4. Insert into Max Heap\n");
        printf("5. Display heaps\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                initMinHeap(&userMinHeap);
                buildMinHeap(&userMinHeap, userArray, n);
                printf("Min Heap built successfully!\n");
                displayMinHeap(&userMinHeap);
                displayHeapTree(userMinHeap.data, userMinHeap.size, "Min");
                break;
            case 2:
                initMaxHeap(&userMaxHeap);
                buildMaxHeap(&userMaxHeap, userArray, n);
                printf("Max Heap built successfully!\n");
                displayMaxHeap(&userMaxHeap);
                displayHeapTree(userMaxHeap.data, userMaxHeap.size, "Max");
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertMinHeap(&userMinHeap, value);
                printf("Inserted %d into Min Heap\n", value);
                displayMinHeap(&userMinHeap);
                break;
            case 4:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertMaxHeap(&userMaxHeap, value);
                printf("Inserted %d into Max Heap\n", value);
                displayMaxHeap(&userMaxHeap);
                break;
            case 5:
                printf("\nCurrent Heaps:\n");
                displayMinHeap(&userMinHeap);
                displayMaxHeap(&userMaxHeap);
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