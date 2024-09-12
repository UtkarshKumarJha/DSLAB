#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int top;
    unsigned capacity;
    char* array;
} Stack;

Stack* createStack(unsigned capacity) {
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
    if (isEmpty(stack)) return '\0';
    return stack->array[stack->top--];
}

char peek(Stack* stack) {
    if (!isEmpty(stack)) return stack->array[stack->top];
    return '\0';
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
        default:
            return 0;
    }
}

void reverse(char* str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

void infixToPostfix(char* infix, char* postfix) {
    Stack* stack = createStack(strlen(infix));
    if (!stack) return;

    int k = 0;
    for (int i = 0; infix[i]; i++) {
        if (isalpha(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            push(stack, infix[i]);
        } else if (infix[i] == ')') {
            while (!isEmpty(stack) && peek(stack) != '(') {
                postfix[k++] = pop(stack);
            }
            pop(stack);
        } else {
            while (!isEmpty(stack) && precedence(peek(stack)) >= precedence(infix[i])) {
                postfix[k++] = pop(stack);
            }
            push(stack, infix[i]);
        }
    }

    while (!isEmpty(stack)) {
        postfix[k++] = pop(stack);
    }
    postfix[k] = '\0';

    free(stack->array);
    free(stack);
}

void infixToPrefix(char* infix, char* prefix) {
    reverse(infix);

    for (int i = 0; infix[i]; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    char postfix[100];
    infixToPostfix(infix, postfix);

    reverse(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[100], prefix[100];
    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);

    size_t len = strlen(infix);
    if (len > 0 && infix[len - 1] == '\n') {
        infix[len - 1] = '\0';
    }

    infixToPrefix(infix, prefix);
    printf("Prefix expression: %s\n", prefix);

    return 0;
}

