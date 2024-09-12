#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct {
    int top;
    int capacity;
    char* array;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}


void push(Stack* stack, char item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}


char pop(Stack* stack) {
    if (isEmpty(stack)) return 'N';
    return stack->array[stack->top--];
}

char peek(Stack* stack) {
    if (!isEmpty(stack)) return stack->array[stack->top];
    return 'N';
}


int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}


int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return 0;
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char* exp) {
    Stack* stack = createStack(100);

    int i = 0, k = 0;
    char postfix[100];

    while (exp[i]) {
        if (isalnum(exp[i])) {
            postfix[k++] = exp[i];
        } else if (exp[i] == '(') {
            push(stack, exp[i]);
        } else if (exp[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[k++] = pop(stack);
            }
            pop(stack); // Remove '(' from stack
        } else if (isOperator(exp[i])) {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(exp[i])) {
                postfix[k++] = pop(stack);
            }
            push(stack, exp[i]);
        }
        i++;
    }

    while (!isEmpty(stack)) {
        postfix[k++] = pop(stack);
    }

    postfix[k] = '\0';
    printf("Postfix Expression: %s\n", postfix);

    free(stack->array);
    free(stack);
}

int main() {
    char exp[100];
    printf("Enter infix expression: ");
    fgets(exp, sizeof(exp), stdin);
    size_t len = strlen(exp);
    if (len > 0 && exp[len - 1] == '\n') {
        exp[len - 1] = '\0';
    }

    infixToPostfix(exp);
    return 0;
}

