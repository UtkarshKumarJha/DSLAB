#include <stdio.h>
#include <stdlib.h>

// Node structure for binary tree
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive function to create a binary tree
Node* createBinaryTreeRecursive() {
    int data;
    printf("Enter data (-1 for no child): ");
    scanf("%d", &data);

    if (data == -1) return NULL;

    Node* newNode = createNode(data);
    printf("Enter left child of %d: ", data);
    newNode->left = createBinaryTreeRecursive();
    printf("Enter right child of %d: ", data);
    newNode->right = createBinaryTreeRecursive();

    return newNode;
}

void printBinaryTreeRecursive(Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    printBinaryTreeRecursive(root->left);
    printBinaryTreeRecursive(root->right);
}

int main() {
    Node* root = createBinaryTreeRecursive();

    printf("Binary tree: ");
    printBinaryTreeRecursive(root);
    printf("\n");

    return 0;
}
