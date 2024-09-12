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

void insertRear(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteRear(Node** head) {
    if (*head == NULL) return;
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);
}

void insertAtPosition(Node** head, int data, int position) {
    Node* newNode = createNode(data);
    if (position == 0) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }
    Node* temp = *head;
    for (int i = 0; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAtPosition(Node** head, int position) {
    if (*head == NULL) return;
    Node* temp = *head;
    if (position == 0) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < position; i++) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void insertAfter(Node** head, int data, int afterData) {
    Node* temp = *head;
    while (temp != NULL && temp->data != afterData) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    Node* newNode = createNode(data);
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertBefore(Node** head, int data, int beforeData) {
    Node* temp = *head;
    while (temp != NULL && temp->data != beforeData) {
        temp = temp->next;
    }
    if (temp == NULL) return;
    Node* newNode = createNode(data);
    newNode->prev = temp->prev;
    newNode->next = temp;
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        *head = newNode;
    }
    temp->prev = newNode;
}

void traverseList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverseList(Node** head) {
    Node* temp = NULL;
    Node* current = *head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        *head = temp->prev;
    }
}

int main() {
    Node* list = NULL;
    int choice, data, position, afterData, beforeData;

    while (1) {
        printf("1. Insert at rear\n2. Delete from rear\n3. Insert at position\n4. Delete at position\n5. Insert after\n6. Insert before\n7. Traverse\n8. Reverse\n0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertRear(&list, data);
                break;
            case 2:
                deleteRear(&list);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &position);
                insertAtPosition(&list, data, position);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(&list, position);
                break;
            case 5:
                printf("Enter data and data after which to insert: ");
                scanf("%d %d", &data, &afterData);
                insertAfter(&list, data, afterData);
                break;
            case 6:
                printf("Enter data and data before which to insert: ");
                scanf("%d %d", &data, &beforeData);
                insertBefore(&list, data, beforeData);
                break;
            case 7:
                traverseList(list);
                break;
            case 8:
                reverseList(&list);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
