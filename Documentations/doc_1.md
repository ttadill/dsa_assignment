# Program 1: Balanced Parentheses Checker

## Overview
This program checks whether a given mathematical expression has balanced parentheses using a stack data structure. It ensures that every opening bracket has a matching closing bracket in the correct order.

## Data Structure Used

### Stack
The stack follows the LIFO (Last In, First Out) principle.

- **items**: Array used to store brackets  
- **top**: Stores the index of the top element  
- **MAX_SIZE**: Maximum size of the stack (100)  

When the stack is empty, the value of `top` is `-1`.

## Functions Used

### Stack Operations
- **initStack()**  
  Initializes the stack by setting `top = -1`
- **isEmpty()**  
  Checks whether the stack is empty
- **isFull()**  
  Checks whether the stack is full
- **push()**  
  Inserts an element into the stack
- **pop()**  
  Removes and returns the top element of the stack
- **peek()**  
  Returns the top element without removing it  

All stack operations take **O(1)** time.

### Helper Functions
- **isOpeningBracket()**  
  Checks for `(`, `{`, or `[`
- **isClosingBracket()**  
  Checks for `)`, `}`, or `]`
- **isMatchingPair()**  
  Checks whether opening and closing brackets match correctly

## Main Algorithm

### areParenthesesBalanced()
1. Initialize an empty stack  
2. Traverse each character of the expression  
3. Push opening brackets onto the stack  
4. When a closing bracket is found:  
   - If the stack is empty → NOT balanced  
   - Pop the stack and check for a matching pair  
5. After traversal, the stack should be empty  

- **Time Complexity:** O(n)  
- **Space Complexity:** O(n)

## Program Flow
The `main()` function:

- Displays the program title  
- Tests expressions given in the assignment  
- Tests additional expressions  
- Allows the user to enter a custom expression  
- Displays whether the expression is BALANCED or NOT BALANCED  

## Sample Output
```
Expression: a + (b - c) * (d
Result: NOT BALANCED

Expression: m + [a - b * (c + d * {m)]
Result: NOT BALANCED

Expression: a + (b - c)
Result: BALANCED

Expression: {[()]}
Result: BALANCED
```

## Key Points
- Uses stack data structure
- Supports (), {}, and []
- Checks correct order and nesting of brackets
- Efficient single-pass algorithm
