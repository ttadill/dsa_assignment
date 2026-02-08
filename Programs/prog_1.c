#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// Function to initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Function to check if stack is empty
bool isEmpty(Stack *s) {
    return s->top == -1;
}

// Function to check if stack is full
bool isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Function to push element onto stack
void push(Stack *s, char item) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        return;
    }
    s->items[++(s->top)] = item;
}

// Function to pop element from stack
char pop(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[(s->top)--];
}

// Function to peek at top element
char peek(Stack *s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

// Function to check if character is opening bracket
bool isOpeningBracket(char ch) {
    return (ch == '(' || ch == '[' || ch == '{');
}

// Function to check if character is closing bracket
bool isClosingBracket(char ch) {
    return (ch == ')' || ch == ']' || ch == '}');
}

// Function to check if brackets match
bool isMatchingPair(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '[' && closing == ']') ||
            (opening == '{' && closing == '}'));
}

// Function to check if expression has balanced parentheses
bool areParenthesesBalanced(char *expression) {
    Stack stack;
    initStack(&stack);
    
    int length = strlen(expression);
    
    for (int i = 0; i < length; i++) {
        char current = expression[i];
        
        // If opening bracket, push to stack
        if (isOpeningBracket(current)) {
            push(&stack, current);
        }
        // If closing bracket, check if it matches
        else if (isClosingBracket(current)) {
            if (isEmpty(&stack)) {
                return false;  // No matching opening bracket
            }
            
            char top = pop(&stack);
            if (!isMatchingPair(top, current)) {
                return false;  // Mismatched brackets
            }
        }
    }
    
    // If stack is empty, all brackets are balanced
    return isEmpty(&stack);
}

// Function to display result
void checkAndDisplay(char *expression) {
    printf("\nExpression: %s\n", expression);
    
    if (areParenthesesBalanced(expression)) {
        printf("Result: BALANCED ✓\n");
    } else {
        printf("Result: NOT BALANCED ✗\n");
    }
    printf("-------------------------------------------\n");
}

int main() {
    printf("=========================================\n");
    printf("  BALANCED PARENTHESES CHECKER\n");
    printf("=========================================\n");
    
    // Test expressions from assignment
    char expr1[] = "a + (b - c) * (d";
    char expr2[] = "m + [a - b * (c + d * {m)]";
    char expr3[] = "a + (b - c)";
    
    // Additional test cases
    char expr4[] = "{[()]}";
    char expr5[] = "((a + b) * (c - d))";
    
    checkAndDisplay(expr1);
    checkAndDisplay(expr2);
    checkAndDisplay(expr3);
    checkAndDisplay(expr4);
    checkAndDisplay(expr5);
    
    // Interactive mode
    printf("\nEnter your own expression (max 100 chars): ");
    char userExpr[MAX_SIZE];
    if (fgets(userExpr, MAX_SIZE, stdin) != NULL) {
        // Remove newline character
        userExpr[strcspn(userExpr, "\n")] = 0;
        checkAndDisplay(userExpr);
    }
    
    return 0;
}