#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>

#define MAX_SIZE 100

// Stack for characters (operators)
typedef struct {
    char items[MAX_SIZE];
    int top;
} CharStack;

// Stack for integers (operands)
typedef struct {
    int items[MAX_SIZE];
    int top;
} IntStack;

// Character Stack Functions
void initCharStack(CharStack *s) {
    s->top = -1;
}

bool isCharStackEmpty(CharStack *s) {
    return s->top == -1;
}

void pushChar(CharStack *s, char item) {
    if (s->top < MAX_SIZE - 1) {
        s->items[++(s->top)] = item;
    }
}

char popChar(CharStack *s) {
    if (!isCharStackEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0';
}

char peekChar(CharStack *s) {
    if (!isCharStackEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

// Integer Stack Functions
void initIntStack(IntStack *s) {
    s->top = -1;
}

bool isIntStackEmpty(IntStack *s) {
    return s->top == -1;
}

void pushInt(IntStack *s, int item) {
    if (s->top < MAX_SIZE - 1) {
        s->items[++(s->top)] = item;
    }
}

int popInt(IntStack *s) {
    if (!isIntStackEmpty(s)) {
        return s->items[(s->top)--];
    }
    return 0;
}

// Function to check if character is an operator
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

// Function to get precedence of operators
int getPrecedence(char op) {
    switch(op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Function to check if operator is right associative
bool isRightAssociative(char op) {
    return op == '^';
}

// Function to convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    CharStack stack;
    initCharStack(&stack);
    
    int j = 0;  // Index for postfix string
    int len = strlen(infix);
    
    for (int i = 0; i < len; i++) {
        char current = infix[i];
        
        // Skip whitespace
        if (isspace(current)) {
            continue;
        }
        
        // If operand (digit or letter), add to postfix
        if (isalnum(current)) {
            postfix[j++] = current;
            postfix[j++] = ' ';  // Add space separator
        }
        // If opening parenthesis, push to stack
        else if (current == '(') {
            pushChar(&stack, current);
        }
        // If closing parenthesis, pop until opening parenthesis
        else if (current == ')') {
            while (!isCharStackEmpty(&stack) && peekChar(&stack) != '(') {
                postfix[j++] = popChar(&stack);
                postfix[j++] = ' ';
            }
            popChar(&stack);  // Remove '('
        }
        // If operator
        else if (isOperator(current)) {
            while (!isCharStackEmpty(&stack) && 
                   peekChar(&stack) != '(' &&
                   (getPrecedence(peekChar(&stack)) > getPrecedence(current) ||
                    (getPrecedence(peekChar(&stack)) == getPrecedence(current) && 
                     !isRightAssociative(current)))) {
                postfix[j++] = popChar(&stack);
                postfix[j++] = ' ';
            }
            pushChar(&stack, current);
        }
    }
    
    // Pop remaining operators
    while (!isCharStackEmpty(&stack)) {
        postfix[j++] = popChar(&stack);
        postfix[j++] = ' ';
    }
    
    postfix[j] = '\0';
}

// Function to evaluate postfix expression
int evaluatePostfix(char *postfix) {
    IntStack stack;
    initIntStack(&stack);
    
    int len = strlen(postfix);
    
    for (int i = 0; i < len; i++) {
        char current = postfix[i];
        
        // Skip whitespace
        if (isspace(current)) {
            continue;
        }
        
        // If operand (digit), push to stack
        if (isdigit(current)) {
            pushInt(&stack, current - '0');
        }
        // If operator, pop two operands and apply operation
        else if (isOperator(current)) {
            int operand2 = popInt(&stack);
            int operand1 = popInt(&stack);
            int result;
            
            switch(current) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': 
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        return 0;
                    }
                    result = operand1 / operand2; 
                    break;
                case '^': result = (int)pow(operand1, operand2); break;
                default: result = 0;
            }
            
            pushInt(&stack, result);
        }
    }
    
    return popInt(&stack);
}

int main() {
    printf("=========================================\n");
    printf("  INFIX TO POSTFIX CONVERTER & EVALUATOR\n");
    printf("=========================================\n\n");
    
    // Test cases
    char *testCases[] = {
        "3+4*2",
        "3+4*2/(1-5)^2",
        "(3+4)*2",
        "5+3*2-8/4",
        "2^3^2"
    };
    
    int numTests = sizeof(testCases) / sizeof(testCases[0]);
    
    for (int i = 0; i < numTests; i++) {
        char postfix[MAX_SIZE];
        
        printf("Test Case %d:\n", i + 1);
        printf("Infix Expression:   %s\n", testCases[i]);
        
        infixToPostfix(testCases[i], postfix);
        printf("Postfix Expression: %s\n", postfix);
        
        int result = evaluatePostfix(postfix);
        printf("Evaluation Result:  %d\n", result);
        printf("-------------------------------------------\n\n");
    }
    
    // Interactive mode
    printf("Enter your infix expression (digits and operators only): ");
    char userExpr[MAX_SIZE];
    if (fgets(userExpr, MAX_SIZE, stdin) != NULL) {
        userExpr[strcspn(userExpr, "\n")] = 0;
        
        char postfix[MAX_SIZE];
        printf("\nInfix Expression:   %s\n", userExpr);
        
        infixToPostfix(userExpr, postfix);
        printf("Postfix Expression: %s\n", postfix);
        
        int result = evaluatePostfix(postfix);
        printf("Evaluation Result:  %d\n", result);
    }
    
    return 0;
}