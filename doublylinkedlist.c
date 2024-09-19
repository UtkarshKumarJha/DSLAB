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
    newNode->next = newNode->prev = newNode;
    return newNode;
}


void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}

void deleteNode(Node** head, int data) {
    Node* temp = *head;
    while (temp->next != *head && temp->data != data) {
        temp = temp->next;
    }
    if (temp->data == data) {
        if (temp == *head) {
            *head = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}


void displayList(Node* head) {
    Node* temp = head;
    while (temp->next != head) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main() {
    Node* head = NULL;
    int choice, data;

    while (1) {
        printf("Menu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insertNode(&head, data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

