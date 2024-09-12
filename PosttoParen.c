#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct {
    int top;
    unsigned capacity;
    char** array;
} Stack;


Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char**)malloc(stack->capacity * sizeof(char*));
    return stack;
}


int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}


int isEmpty(Stack* stack) {
    return stack->top == -1;
}


void push(Stack* stack, const char* item) {
    if (isFull(stack)) return;
    stack->array[++stack->top] = strdup(item); // Duplicate the string before pushing
}


char* pop(Stack* stack) {
    if (isEmpty(stack)) return NULL;
    return stack->array[stack->top--];
}

char* peek(Stack* stack) {
    if (!isEmpty(stack)) return stack->array[stack->top];
    return NULL;
}


char* postfixToInfix(char* expression) {
    Stack* stack = createStack(100);
    if (!stack) return NULL;
    int i = 0;
    while (expression[i]) {
        if (isdigit(expression[i])) {

            char operand[2] = { expression[i], '\0' };
            push(stack, operand);
        } else if (expression[i] == ' ') {

            i++;
            continue;
        } else {

            char* val2 = pop(stack);
            char* val1 = pop(stack);
            if (!val1 || !val2) {
                printf("Error: Invalid postfix expression\n");
                free(stack->array);
                free(stack);
                return NULL;
            }

            char* result = (char*)malloc(strlen(val1) + strlen(val2) + 4 + 1);
            sprintf(result, "(%s%c%s)", val1, expression[i], val2);


            push(stack, result);


            free(val1);
            free(val2);
        }
        i++;
    }

    char* finalResult = pop(stack);
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

    char* result = postfixToInfix(expression);
    if (result) {
        printf("Fully parenthesized infix expression: %s\n", result);
        free(result);
    } else {
        printf("Error: Conversion failed.\n");
    }

    return 0;
}
