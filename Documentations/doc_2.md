# Program 2: Infix to Postfix Conversion and Evaluation

## Overview
This program converts infix mathematical expressions to postfix notation and evaluates the resulting postfix expression using stack data structures.

## Data Structures

### CharStack (for operators)
```c
typedef struct {
    char items[MAX_SIZE];
    int top;
} CharStack;
```
- Used to store operators during infix to postfix conversion
- **items**: Array of characters
- **top**: Index of top element

### IntStack (for operands)
```c
typedef struct {
    int items[MAX_SIZE];
    int top;
} IntStack;
```
- Used to store operands during postfix evaluation
- **items**: Array of integers
- **top**: Index of top element

## Functions Implemented

### CharStack Operations
1. **`void initCharStack(CharStack *s)`**
   - Initializes character stack

2. **`bool isCharStackEmpty(CharStack *s)`**
   - Checks if character stack is empty

3. **`void pushChar(CharStack *s, char item)`**
   - Pushes character onto stack

4. **`char popChar(CharStack *s)`**
   - Pops and returns character from stack

5. **`char peekChar(CharStack *s)`**
   - Returns top character without removing

### IntStack Operations
6. **`void initIntStack(IntStack *s)`**
   - Initializes integer stack

7. **`bool isIntStackEmpty(IntStack *s)`**
   - Checks if integer stack is empty

8. **`void pushInt(IntStack *s, int item)`**
   - Pushes integer onto stack

9. **`int popInt(IntStack *s)`**
   - Pops and returns integer from stack

### Helper Functions
10. **`bool isOperator(char ch)`**
    - Checks if character is +, -, *, /, or ^

11. **`int getPrecedence(char op)`**
    - Returns precedence level:
      - ^ (power): 3
      - *, /: 2
      - +, -: 1

12. **`bool isRightAssociative(char op)`**
    - Returns true for ^ (power operator)
    - All others are left associative

### Main Algorithms

13. **`void infixToPostfix(char *infix, char *postfix)`**
    - **Algorithm** (Shunting Yard Algorithm):
      1. Initialize empty operator stack
      2. For each token in infix expression:
         - If operand: append to postfix
         - If '(': push to stack
         - If ')': pop until '(' found
         - If operator:
           - Pop operators with higher/equal precedence
           - Push current operator
      3. Pop remaining operators to postfix
    - **Time Complexity**: O(n)
    - **Space Complexity**: O(n)

14. **`int evaluatePostfix(char *postfix)`**
    - **Algorithm**:
      1. Initialize empty operand stack
      2. For each token in postfix:
         - If operand: push to stack
         - If operator:
           - Pop two operands
           - Apply operation
           - Push result back
      3. Final stack value is result
    - **Time Complexity**: O(n)
    - **Space Complexity**: O(n)

## Main Method Organization

The `main()` function:
1. Displays program header
2. Tests multiple predefined expressions:
   - Simple: `3+4*2`
   - Complex: `3+4*2/(1-5)^2`
   - With parentheses: `(3+4)*2`
   - Multiple operators: `5+3*2-8/4`
   - Right associative: `2^3^2`
3. For each test:
   - Shows infix expression
   - Converts to postfix
   - Evaluates the result
4. Provides interactive mode for user input

## Conversion Examples

### Example 1: `3+4*2`
- **Step-by-step**:
  - Read 3: output "3 "
  - Read +: push to stack
  - Read 4: output "4 "
  - Read *: higher precedence, push to stack
  - Read 2: output "2 "
  - End: pop *, then +
- **Postfix**: `3 4 2 * +`
- **Evaluation**: 3 + (4 * 2) = 11

### Example 2: `(3+4)*2`
- **Postfix**: `3 4 + 2 *`
- **Evaluation**: (3 + 4) * 2 = 14

