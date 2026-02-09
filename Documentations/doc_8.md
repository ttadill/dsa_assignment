# Program 8: Sorting Algorithm Comparison

## Overview
This program generates N random integers and sorts them using the user's choice of sorting algorithm (Bubble Sort, Selection Sort, Insertion Sort, or Merge Sort), displaying statistics including comparisons, swaps, and execution time.

## Data Structures

### Statistics Structure
```c
typedef struct {
    long long comparisons;
    long long swaps;
} Statistics;
```
- **comparisons**: Total number of element comparisons
- **swaps**: Total number of element swaps (or moves for Insertion Sort)
- **long long**: Used to handle large counts for big arrays

## Functions Implemented

### Utility Functions

1. **`void generateRandomArray(int arr[], int n, int min, int max)`**
   - Generates random integers in range [min, max]
   - Uses rand() with current time as seed
   - Time Complexity: O(n)

2. **`void printArray(int arr[], int n, int maxDisplay)`**
   - Displays array elements
   - Limits display to maxDisplay elements for large arrays
   - Time Complexity: O(min(n, maxDisplay))

3. **`void copyArray(int source[], int dest[], int n)`**
   - Creates copy of array for comparison testing
   - Time Complexity: O(n)

4. **`bool isSorted(int arr[], int n)`**
   - Verifies if array is sorted correctly
   - Time Complexity: O(n)

### Sorting Algorithms

5. **`void bubbleSort(int arr[], int n, Statistics *stats)`**
   - **Algorithm**:
     ```
     For i = 0 to n-2:
       For j = 0 to n-i-2:
         If arr[j] > arr[j+1]:
           Swap them
       If no swaps in this pass:
         Break (optimization)
     ```
   - **Time Complexity**:
     - Best Case: O(n) - already sorted
     - Average Case: O(n²)
     - Worst Case: O(n²) - reverse sorted
   - **Space Complexity**: O(1)
   - **Stable**: Yes
   - **Adaptive**: Yes (with optimization)
   - **Best for**: Small arrays, nearly sorted data

6. **`void selectionSort(int arr[], int n, Statistics *stats)`**
   - **Algorithm**:
     ```
     For i = 0 to n-2:
       Find minimum in arr[i...n-1]
       Swap arr[i] with minimum
     ```
   - **Time Complexity**:
     - Best Case: O(n²)
     - Average Case: O(n²)
     - Worst Case: O(n²)
   - **Space Complexity**: O(1)
   - **Stable**: No
   - **Adaptive**: No
   - **Best for**: Small arrays where swaps are expensive
   - **Comparisons**: Always (n-1) + (n-2) + ... + 1 = n(n-1)/2
   - **Swaps**: At most n-1

7. **`void insertionSort(int arr[], int n, Statistics *stats)`**
   - **Algorithm**:
     ```
     For i = 1 to n-1:
       key = arr[i]
       Insert key into sorted portion arr[0...i-1]
       by shifting larger elements right
     ```
   - **Time Complexity**:
     - Best Case: O(n) - already sorted
     - Average Case: O(n²)
     - Worst Case: O(n²) - reverse sorted
   - **Space Complexity**: O(1)
   - **Stable**: Yes
   - **Adaptive**: Yes
   - **Best for**: Small arrays, nearly sorted data, online sorting

8. **`void mergeSort(int arr[], int left, int right, Statistics *stats)`**
   - **Algorithm** (Divide and Conquer):
     ```
     If left < right:
       mid = (left + right) / 2
       mergeSort(left half)
       mergeSort(right half)
       merge(both halves)
     ```
   - **Time Complexity**:
     - Best Case: O(n log n)
     - Average Case: O(n log n)
     - Worst Case: O(n log n)
   - **Space Complexity**: O(n) - for temporary arrays
   - **Stable**: Yes
   - **Adaptive**: No
   - **Best for**: Large arrays, linked lists, external sorting
   - **Recurrence**: T(n) = 2T(n/2) + O(n)

9. **`void merge(int arr[], int left, int mid, int right, Statistics *stats)`**
   - Merges two sorted subarrays
   - Creates temporary arrays for merging
   - Time Complexity: O(n)

### Display Functions

10. **`void displayStatistics(const char *algorithmName, Statistics stats, double timeTaken, int n)`**
    - Shows algorithm performance metrics
    - Displays comparisons, swaps, and time

## Main Method Organization

The `main()` function is organized as follows:

1. **Input Phase**:
   - Get array size N from user
   - Allocate memory for arrays
   - Generate random integers in range [1, 1000]
   - Display original array

2. **Algorithm Selection**:
   - Display menu of sorting algorithms
   - User selects algorithm (1-4)
   - Copy original array to working array

3. **Sorting Execution**:
   - Start timer
   - Execute chosen sorting algorithm
   - Stop timer
   - Track comparisons and swaps

4. **Results Display**:
   - Show sorted array
   - Verify correctness
   - Display statistics

5. **Comparison Mode** (Optional):
   - Run all four algorithms on same data
   - Compare performance metrics
   - Show side-by-side statistics

## Algorithm Comparison Table

| Algorithm | Best Case | Average Case | Worst Case | Space | Stable | Adaptive |
|-----------|-----------|--------------|------------|-------|--------|----------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No | No |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes | No |

## Sample Output

```
=========================================
  SORTING ALGORITHM COMPARISON
=========================================

Enter the number of random integers (N): 15

Random array generated successfully!
Array range: [1, 1000]

Original Array (unsorted):
342 678 234 891 456 123 789 567 234 901 345 678 234 567 890 

===========================================
Select Sorting Algorithm:
===========================================
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Merge Sort
===========================================
Enter your choice (1-4): 4

Sorting using Merge Sort...

Sorted Array:
123 234 234 234 342 345 456 567 567 678 678 789 890 891 901 

✓ Array is correctly sorted!

===========================================
Algorithm: Merge Sort
===========================================
Array Size:         15
Total Comparisons:  39
Time Taken:         0.000023 seconds
===========================================

Would you like to compare with other algorithms? (1=Yes, 0=No): 1

===========================================
COMPARING ALL ALGORITHMS
===========================================

===========================================
Algorithm: Bubble Sort
===========================================
Array Size:         15
Total Comparisons:  105
Total Swaps:        42
Time Taken:         0.000012 seconds
===========================================

===========================================
Algorithm: Selection Sort
===========================================
Array Size:         15
Total Comparisons:  105
Total Swaps:        12
Time Taken:         0.000008 seconds
===========================================

===========================================
Algorithm: Insertion Sort
===========================================
Array Size:         15
Total Comparisons:  47
Total Swaps:        42
Time Taken:         0.000007 seconds
===========================================

===========================================
Algorithm: Merge Sort
===========================================
Array Size:         15
Total Comparisons:  39
Time Taken:         0.000024 seconds
===========================================

Program completed successfully!
```

## Performance Analysis for N=1000

Typical results (actual values vary with random data):

| Algorithm | Comparisons | Swaps | Time (sec) |
|-----------|-------------|-------|------------|
| Bubble Sort | ~499,500 | ~250,000 | ~0.015 |
| Selection Sort | 499,500 | 999 | ~0.008 |
| Insertion Sort | ~250,000 | ~250,000 | ~0.005 |
| Merge Sort | ~8,700 | 0 | ~0.001 |

**Observations**:
- Merge Sort has fewest comparisons
- Selection Sort has fewest swaps
- Merge Sort is fastest for large N
- Insertion Sort is fast for nearly sorted data

## Compilation and Execution

```bash
gcc prog_8.c -o prog_8
./prog_8
```

## When to Use Each Algorithm

### Bubble Sort
- ✓ Educational purposes
- ✓ Nearly sorted data
- ✗ Never for large datasets

### Selection Sort
- ✓ When swaps are expensive
- ✓ Small arrays
- ✗ When stability matters

### Insertion Sort
- ✓ Small arrays (< 50 elements)
- ✓ Nearly sorted data
- ✓ Online sorting (data arrives incrementally)
- ✓ As subroutine in hybrid algorithms

### Merge Sort
- ✓ Large datasets
- ✓ When stability is required
- ✓ Linked lists
- ✓ External sorting
- ✗ When space is limited

## Key Concepts

### Stability
A sorting algorithm is **stable** if equal elements maintain their relative order.
- Example: [(5,a), (3,b), (5,c)] → [(3,b), (5,a), (5,c)]

### Adaptivity
An algorithm is **adaptive** if it performs better on nearly sorted data.

### In-place
Sorts with O(1) extra space (Bubble, Selection, Insertion).

### Divide and Conquer
Recursively breaks problem into smaller subproblems (Merge Sort).

## Extension Ideas
- Add Quick Sort, Heap Sort
- Add best/worst case input generation
- Visualize sorting process
- Compare on different data distributions
- Add iterative vs recursive merge sort