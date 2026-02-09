#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

// Statistics structure
typedef struct {
    long long comparisons;
    long long swaps;
} Statistics;

// Function prototypes
void bubbleSort(int arr[], int n, Statistics *stats);
void selectionSort(int arr[], int n, Statistics *stats);
void insertionSort(int arr[], int n, Statistics *stats);
void mergeSort(int arr[], int left, int right, Statistics *stats);
void merge(int arr[], int left, int mid, int right, Statistics *stats);

// Utility function to print array
void printArray(int arr[], int n, int maxDisplay) {
    int displayCount = (n < maxDisplay) ? n : maxDisplay;
    
    for (int i = 0; i < displayCount; i++) {
        printf("%d ", arr[i]);
    }
    
    if (n > maxDisplay) {
        printf("... (showing first %d of %d elements)", maxDisplay, n);
    }
    printf("\n");
}

// Generate random array
void generateRandomArray(int arr[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

// Copy array
void copyArray(int source[], int dest[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

// Verify if array is sorted
bool isSorted(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

// ==================== BUBBLE SORT ====================
void bubbleSort(int arr[], int n, Statistics *stats) {
    stats->comparisons = 0;
    stats->swaps = 0;
    
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        
        for (int j = 0; j < n - i - 1; j++) {
            stats->comparisons++;
            
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                stats->swaps++;
                swapped = true;
            }
        }
        
        // If no swaps, array is sorted
        if (!swapped) {
            break;
        }
    }
}

// ==================== SELECTION SORT ====================
void selectionSort(int arr[], int n, Statistics *stats) {
    stats->comparisons = 0;
    stats->swaps = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        
        for (int j = i + 1; j < n; j++) {
            stats->comparisons++;
            
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        
        // Swap if needed
        if (minIdx != i) {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
            stats->swaps++;
        }
    }
}

// ==================== INSERTION SORT ====================
void insertionSort(int arr[], int n, Statistics *stats) {
    stats->comparisons = 0;
    stats->swaps = 0;
    
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements greater than key
        while (j >= 0) {
            stats->comparisons++;
            
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                stats->swaps++;
                j--;
            } else {
                break;
            }
        }
        
        arr[j + 1] = key;
    }
}

// ==================== MERGE SORT ====================
void merge(int arr[], int left, int mid, int right, Statistics *stats) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    
    // Copy data to temp arrays
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    // Merge the temp arrays back
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        stats->comparisons++;
        
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right, Statistics *stats) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid, stats);
        mergeSort(arr, mid + 1, right, stats);
        merge(arr, left, mid, right, stats);
    }
}

// Wrapper for merge sort
void mergeSortWrapper(int arr[], int n, Statistics *stats) {
    stats->comparisons = 0;
    stats->swaps = 0;  // Merge sort doesn't swap, but we count comparisons
    mergeSort(arr, 0, n - 1, stats);
}

// Display statistics
void displayStatistics(const char *algorithmName, Statistics stats, double timeTaken, int n) {
    printf("\n===========================================\n");
    printf("Algorithm: %s\n", algorithmName);
    printf("===========================================\n");
    printf("Array Size:         %d\n", n);
    printf("Total Comparisons:  %lld\n", stats.comparisons);
    
    if (stats.swaps > 0 || strcmp(algorithmName, "Merge Sort") != 0) {
        printf("Total Swaps:        %lld\n", stats.swaps);
    }
    
    printf("Time Taken:         %.6f seconds\n", timeTaken);
    printf("===========================================\n");
}

int main() {
    int n, choice;
    
    printf("=========================================\n");
    printf("  SORTING ALGORITHM COMPARISON\n");
    printf("=========================================\n\n");
    
    // Get array size from user
    printf("Enter the number of random integers (N): ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Invalid size!\n");
        return 1;
    }
    
    // Allocate arrays
    int *original = (int *)malloc(n * sizeof(int));
    int *toSort = (int *)malloc(n * sizeof(int));
    
    if (original == NULL || toSort == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    
    // Seed random number generator
    srand(time(NULL));
    
    // Generate random array
    generateRandomArray(original, n, 1, 1000);
    
    printf("\nRandom array generated successfully!\n");
    printf("Array range: [1, 1000]\n\n");
    
    // Display original array
    printf("Original Array (unsorted):\n");
    printArray(original, n, 20);
    
    // Menu for sorting algorithm selection
    printf("\n===========================================\n");
    printf("Select Sorting Algorithm:\n");
    printf("===========================================\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("===========================================\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);
    
    Statistics stats;
    clock_t start, end;
    double timeTaken;
    const char *algorithmName;
    
    // Copy original array
    copyArray(original, toSort, n);
    
    // Perform sorting based on choice
    switch (choice) {
        case 1:
            algorithmName = "Bubble Sort";
            printf("\nSorting using Bubble Sort...\n");
            start = clock();
            bubbleSort(toSort, n, &stats);
            end = clock();
            break;
            
        case 2:
            algorithmName = "Selection Sort";
            printf("\nSorting using Selection Sort...\n");
            start = clock();
            selectionSort(toSort, n, &stats);
            end = clock();
            break;
            
        case 3:
            algorithmName = "Insertion Sort";
            printf("\nSorting using Insertion Sort...\n");
            start = clock();
            insertionSort(toSort, n, &stats);
            end = clock();
            break;
            
        case 4:
            algorithmName = "Merge Sort";
            printf("\nSorting using Merge Sort...\n");
            start = clock();
            mergeSortWrapper(toSort, n, &stats);
            end = clock();
            break;
            
        default:
            printf("Invalid choice!\n");
            free(original);
            free(toSort);
            return 1;
    }
    
    timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    // Display sorted array
    printf("\nSorted Array:\n");
    printArray(toSort, n, 20);
    
    // Verify sorting
    if (isSorted(toSort, n)) {
        printf("\n✓ Array is correctly sorted!\n");
    } else {
        printf("\n✗ Error: Array is not sorted correctly!\n");
    }
    
    // Display statistics
    displayStatistics(algorithmName, stats, timeTaken, n);
    
    // Option to compare with other algorithms
    printf("\nWould you like to compare with other algorithms? (1=Yes, 0=No): ");
    int compare;
    scanf("%d", &compare);
    
    if (compare == 1) {
        printf("\n===========================================\n");
        printf("COMPARING ALL ALGORITHMS\n");
        printf("===========================================\n");
        
        // Bubble Sort
        copyArray(original, toSort, n);
        start = clock();
        bubbleSort(toSort, n, &stats);
        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        displayStatistics("Bubble Sort", stats, timeTaken, n);
        
        // Selection Sort
        copyArray(original, toSort, n);
        start = clock();
        selectionSort(toSort, n, &stats);
        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        displayStatistics("Selection Sort", stats, timeTaken, n);
        
        // Insertion Sort
        copyArray(original, toSort, n);
        start = clock();
        insertionSort(toSort, n, &stats);
        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        displayStatistics("Insertion Sort", stats, timeTaken, n);
        
        // Merge Sort
        copyArray(original, toSort, n);
        start = clock();
        mergeSortWrapper(toSort, n, &stats);
        end = clock();
        timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC;
        displayStatistics("Merge Sort", stats, timeTaken, n);
    }
    
    // Clean up
    free(original);
    free(toSort);
    
    printf("\nProgram completed successfully!\n");
    
    return 0;
}