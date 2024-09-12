#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertBefore(Node** head, int newData, int existingData);
void insertAfter(Node** head, int newData, int existingData);
void deleteNode(Node** head, int key);
void traverseList(Node* head);
void reverseList(Node** head);
void sortList(Node** head);
void deleteEveryAlternateNode(Node** head);
void insertInSortedList(Node** head, int newData);
void displayList(Node* head);

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertBefore(Node** head, int newData, int existingData) {
    Node* newNode = createNode(newData);
    if (*head == NULL) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    if ((*head)->data == existingData) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != NULL && temp->next->data != existingData) {
        temp = temp->next;
    }

    if (temp->next == NULL) {
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAfter(Node** head, int newData, int existingData) {
    Node* temp = *head;
    while (temp != NULL && temp->data != existingData) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    Node* newNode = createNode(newData);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void traverseList(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void reverseList(Node** head) {
    Node *prev = NULL, *current = *head, *next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void sortList(Node** head) {
    if (*head == NULL) return;

    Node *i, *j;
    int temp;
    for (i = *head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

void deleteEveryAlternateNode(Node** head) {
    Node* temp = *head;
    Node* prev = NULL;

    if (temp == NULL) return;

    while (temp != NULL && temp->next != NULL) {
        prev = temp;
        temp = temp->next;
        prev->next = temp->next;
        free(temp);
        temp = prev->next;
    }
}

void insertInSortedList(Node** head, int newData) {
    Node* newNode = createNode(newData);
    Node* current;

    if (*head == NULL || (*head)->data >= newData) {
        newNode->next = *head;
        *head = newNode;
    } else {
        current = *head;
        while (current->next != NULL && current->next->data < newData) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void displayList(Node* head) {
    Node* temp = head;
    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("List contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    int choice, data, existingData;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert element before another element\n");
        printf("2. Insert element after another element\n");
        printf("3. Delete a given element\n");
        printf("4. Traverse the list\n");
        printf("5. Reverse the list\n");
        printf("6. Sort the list\n");
        printf("7. Delete every alternate node\n");
        printf("8. Insert element in a sorted list\n");
        printf("9. Display the list\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter new element and existing element: ");
                scanf("%d %d", &data, &existingData);
                insertBefore(&head, data, existingData);
                break;
            case 2:
                printf("Enter new element and existing element: ");
                scanf("%d %d", &data, &existingData);
                insertAfter(&head, data, existingData);
                break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 4:
                traverseList(head);
                break;
            case 5:
                reverseList(&head);
                break;
            case 6:
                sortList(&head);
                break;
            case 7:
                deleteEveryAlternateNode(&head);
                break;
            case 8:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                insertInSortedList(&head, data);
                break;
            case 9:
                displayList(head);
                break;
            case 10:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

