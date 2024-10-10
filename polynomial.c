#include <stdio.h>
#include <stdlib.h>

// Node structure for polynomial linked list
typedef struct PolyNode {
    int coeff;
    int exp;
    struct PolyNode* next;
} PolyNode;

// Function to create a new polynomial node
PolyNode* createPolyNode(int coeff, int exp) {
    PolyNode* newNode = (PolyNode*)malloc(sizeof(PolyNode));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to add two polynomials
PolyNode* addPolynomials(PolyNode* poly1, PolyNode* poly2) {
    PolyNode* result = NULL;
    PolyNode** lastPtrRef = &result;

    while (poly1 != NULL || poly2 != NULL) {
        PolyNode* newNode = NULL;

        if (poly1 == NULL) {
            newNode = createPolyNode(poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else if (poly2 == NULL) {
            newNode = createPolyNode(poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp > poly2->exp) {
            newNode = createPolyNode(poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            newNode = createPolyNode(poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0) {
                newNode = createPolyNode(sumCoeff, poly1->exp);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }

        if (newNode != NULL) {
            *lastPtrRef = newNode;
            lastPtrRef = &newNode->next;
        }
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(PolyNode* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }

    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Example usage
PolyNode* createPolynomial(int coeffs[], int exps[], int size) {
    PolyNode* head = NULL;
    PolyNode* current = NULL;

    for (int i = 0; i < size; i++) {
        PolyNode* newNode = createPolyNode(coeffs[i], exps[i]);
        if (!head) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

int main() {
    int coeffs1[] = {3, 5, 6};
    int exps1[] = {2, 1, 0}; // 3x^2 + 5x + 6
    PolyNode* poly1 = createPolynomial(coeffs1, exps1, 3);

    int coeffs2[] = {4, 2};
    int exps2[] = {1, 0}; // 4x + 2
    PolyNode* poly2 = createPolynomial(coeffs2, exps2, 2);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    PolyNode* resultPoly = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial: ");
    displayPolynomial(resultPoly);

    return 0;
}

