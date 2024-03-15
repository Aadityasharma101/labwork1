#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Structure for Stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Stack Operations
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

char peek(struct Stack* stack) {
    return stack->array[stack->top];
}

char pop(struct Stack* stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '$';
}

void push(struct Stack* stack, char op) {
    stack->array[++stack->top] = op;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to get the precedence of operators
int precedence(char ch) {
   
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    if(ch== '$')
        return 3;
    else
    return -1;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* infix, char* postfix) {
    struct Stack* stack = createStack(strlen(infix));
    int i, k;
    for (i = 0, k = -1; infix[i]; ++i) {
        if (isalnum(infix[i]))
            postfix[++k] = infix[i];
        else if (infix[i] == '(')
            push(stack, infix[i]);
        else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(')
                postfix[++k] = pop(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return; // Invalid expression
            else
                pop(stack);
        } else { // Operator
            while (!isEmpty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
                postfix[++k] = pop(stack);
            push(stack, infix[i]);
        }
    }

    // Pop all the remaining operators from the stack
    while (!isEmpty(stack))
        postfix[++k] = pop(stack);
    postfix[++k] = '\0';
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    
    // Input infix expression
    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    
    // Remove newline character if present
    if (infix[strlen(infix) - 1] == '\n')
        infix[strlen(infix) - 1] = '\0';
    
    // Convert infix to postfix
    infixToPostfix(infix, postfix);
    
    // Output postfix expression
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}
