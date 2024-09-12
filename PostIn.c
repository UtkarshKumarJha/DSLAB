#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct {
    int top;
    unsigned capacity;
    int* array;
} Stack;


Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}


int isEmpty(Stack* stack) {
    return stack->top == -1;
}


void push(Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    return stack->array[stack->top--];
}

int peek(Stack* stack) {
    if (!isEmpty(stack)) return stack->array[stack->top];
    return -1;
}

int evaluatePostfix(char* expression) {
    Stack* stack = createStack(100);
    int i = 0;
    while (expression[i]) {
        if (isdigit(expression[i])) {
            push(stack, expression[i] - '0');
        } else if (expression[i] == ' ') {
            i++;
            continue;
        } else {
            int val2 = pop(stack);
            int val1 = pop(stack);
            int result;

            switch (expression[i]) {
                case '+':
                    result = val1 + val2;
                    break;
                case '-':
                    result = val1 - val2;
                    break;
                case '*':
                    result = val1 * val2;
                    break;
                case '/':
                    result = val1 / val2;
                    break;
                default:
                    printf("Unsupported operator: %c\n", expression[i]);
                    free(stack->array);
                    free(stack);
                    return -1; // Return an error code for unsupported operator
            }
            push(stack, result);
        }
        i++;
    }

    int finalResult = pop(stack);
    free(stack->array);
    free(stack);
    return finalResult;
}

int main() {
    char expression[100];
    printf("Enter a postfix expression: ");
    fgets(expression, sizeof(expression), stdin);

    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
    }

    int result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}

