#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

Node* concatenateLists(Node* X1, Node* X2) {
    if (X1 == NULL) return X2;
    Node* temp = X1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = X2;
    if (X2 != NULL) {
        X2->prev = temp;
    }
    return X1;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;
    Node* result = NULL;

    list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->prev = list1;
    list1->next->next = createNode(3);
    list1->next->next->prev = list1->next;


    list2 = createNode(4);
    list2->next = createNode(5);
    list2->next->prev = list2;
    list2->next->next = createNode(6);
    list2->next->next->prev = list2->next;

    result = concatenateLists(list1, list2);


    Node* temp = result;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
