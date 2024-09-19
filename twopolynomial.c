#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

Node* createNode(int coefficient, int exponent) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}


Node* addPolynomials(Node* poly1, Node* poly2) {
    Node* result = NULL;
    Node* temp1 = poly1;
    Node* temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exponent > temp2->exponent) {
            Node* newNode = createNode(temp1->coefficient, temp1->exponent);
            newNode->next = result;
            result = newNode;
            temp1 = temp1->next;
        } else if (temp1->exponent < temp2->exponent) {
            Node* newNode = createNode(temp2->coefficient, temp2->exponent);
            newNode->next = result;
            result = newNode;
            temp2 = temp2->next;
        } else {
            int coefficient = temp1->coefficient + temp2->coefficient;
            if (coefficient != 0) {
                Node* newNode = createNode(coefficient, temp1->exponent);
                newNode->next = result;
                result = newNode;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != NULL) {
        Node* newNode = createNode(temp1->coefficient, temp1->exponent);
        newNode->next = result;
        result = newNode;
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        Node* newNode = createNode(temp2->coefficient, temp2->exponent);
        newNode->next = result;
        result = newNode;
        temp2 = temp2->next;
    }

    return result;
}

void displayPoly(Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d + ", poly->coefficient, poly->exponent);
        poly = poly->next;
    }
    printf("\n");
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;
    Node* result = NULL;

    poly1 = createNode(2, 2);
    poly1->next = createNode(3, 1);
    poly1->next->next = createNode(1, 0);


    poly2 = createNode(1, 2);
    poly2->next = createNode(2, 1);
    poly2->next->next = createNode(3, 0);

    printf("Polynomial 1: ");
    displayPoly(poly1);
    printf("Polynomial 2: ");
    displayPoly(poly2);

    result = addPolynomials(poly1, poly2);
    printf("Result: ");
    displayPoly(result);

    return 0;
}
