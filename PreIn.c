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
    if (isFull(stack)) return;
    stack->array[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) return -1;
    return stack->array[stack->top--];
}

int peek(Stack* stack) {
    if (!isEmpty(stack)) return stack->array[stack->top];
    return -1;
}

int evaluatePrefix(char* expression) {
    Stack* stack = createStack(100);
    if (!stack) return -1;

    int i = strlen(expression) - 1;
    while (i >= 0) {
        if (isdigit(expression[i])) {
            push(stack, expression[i] - '0');
        } else if (expression[i] == ' ') {
            i--;
            continue;
        } else {
            int val1 = pop(stack);
            int val2 = pop(stack);
            int result;

            if (val1 == -1 || val2 == -1) {
                printf("Error: Not enough operands\n");
                free(stack->array);
                free(stack);
                return -1;
            }

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
                    if (val2 == 0) {
                        printf("Error: Division by zero\n");
                        free(stack->array);
                        free(stack);
                        return -1;
                    }
                    result = val1 / val2;
                    break;
                default:
                    printf("Error: Unsupported operator: %c\n", expression[i]);
                    free(stack->array);
                    free(stack);
                    return -1;
            }
            push(stack, result);
        }
        i--;
    }

    int finalResult = pop(stack);
    free(stack->array);
    free(stack);
    return finalResult;
}

int main() {
    char expression[100];
    printf("Enter a prefix expression: ");
    fgets(expression, sizeof(expression), stdin);

    size_t len = strlen(expression);
    if (len > 0 && expression[len - 1] == '\n') {
        expression[len - 1] = '\0';
    }

    int result = evaluatePrefix(expression);
    if (result != -1) {
        printf("Result: %d\n", result);
    } else {
        printf("Error: Evaluation failed.\n");
    }

    return 0;
}
