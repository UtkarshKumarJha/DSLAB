#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;


typedef struct DoublyLinkedCircularList {
    Node* head;
} DoublyLinkedCircularList;


Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}


void insert(DoublyLinkedCircularList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* tail = list->head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = list->head;
        list->head->prev = newNode;
    }
}

void deleteElement(DoublyLinkedCircularList* list, int data) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = list->head;
    do {
        if (current->data == data) {
            if (current->next == list->head) {
                list->head = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
                if (current == list->head) {
                    list->head = current->next;
                }
            }
            printf("Deleted: %d\n", data);
            free(current);
            return;
        }
        current = current->next;
    } while (current != list->head);

    printf("Element %d not found.\n", data);
}


void display(DoublyLinkedCircularList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* current = list->head;
    do {
        printf("%d <-> ", current->data);
        current = current->next;
    } while (current != list->head);
    printf("(back to head)\n");
}


void menu() {
    printf("Menu:\n");
    printf("1. Insert an element\n");
    printf("2. Delete an element\n");
    printf("3. Display the list\n");
    printf("4. Exit\n");
}

int main() {
    DoublyLinkedCircularList list = {NULL};
    int choice, data;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                insert(&list, data);
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &data);
                deleteElement(&list, data);
                break;
            case 3:
                display(&list);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
