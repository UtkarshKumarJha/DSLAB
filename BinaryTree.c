#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inOrderTraversal(Node* root) {
    if (root == NULL) return;

    Node* stack[100];
    int top = -1;
    Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}


void postOrderTraversal(Node* root) {
    if (root == NULL) return;

    Node* stack1[100];
    Node* stack2[100];
    int top1 = -1;
    int top2 = -1;
    Node* current = root;

    while (current != NULL || top1 != -1) {
        while (current != NULL) {
            stack1[++top1] = current;
            current = current->left;
        }

        current = stack1[top1--];
        stack2[++top2] = current;
        current = current->right;
    }

    while (top2 != -1) {
        current = stack2[top2--];
        printf("%d ", current->data);
    }
}

void preOrderTraversal(Node* root) {
    if (root == NULL) return;

    Node* stack[100];
    int top = -1;
    Node* current = root;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            printf("%d ", current->data);
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        current = current->right;
    }
}


void printParent(Node* root, int data) {
    if (root == NULL) return;

    if (root->left != NULL && root->left->data == data) {
        printf("Parent of %d is %d\n", data, root->data);
        return;
    }

    if (root->right != NULL && root->right->data == data) {
        printf("Parent of %d is %d\n", data, root->data);
        return;
    }

    printParent(root->left, data);
    printParent(root->right, data);
}


int printDepth(Node* root) {
    if (root == NULL) return 0;

    int leftDepth = printDepth(root->left);
    int rightDepth = printDepth(root->right);

    if (leftDepth > rightDepth) {
        return leftDepth + 1;
    } else {
        return rightDepth + 1;
    }
}


void printAncestors(Node* root, int data) {
    if (root == NULL) return;

    if (root->data == data) {
        return;
    }

    printf("%d ", root->data);
    if (root->left != NULL && root->left->data == data) {
        return;
    }

    if (root->right != NULL && root->right->data == data) {
        return;
    }

    printAncestors(root->left, data);
    printAncestors(root->right, data);
}


int countLeafNodes(Node* root) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    return countLeafNodes(root->left) + countLeafNodes(root->right);
}


Node* createBinaryTree() {
    int data;
    printf("Enter data (-1 for no child): ");
    scanf("%d", &data);

    if (data == -1) return NULL;

    Node* newNode = createNode(data);
    printf("Enter left child of %d: ", data);
    newNode->left = createBinaryTree();
    printf("Enter right child of %d: ", data);
    newNode->right = createBinaryTree();

    return newNode;
}


void printBinaryTree(Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

int main() {
    Node* root = createBinaryTree();

    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Post-order traversal: ");
    postOrderTraversal(root);
    printf("\n");

    printf("Pre-order traversal: ");
    preOrderTraversal(root);
    printf("\n");

    int data;
    printf("Enter data to find parent: ");
    scanf("%d", &data);
    printParent(root, data);

    printf("Depth of the tree: %d\n", printDepth(root));

    printf("Enter data to find ancestors: ");
    scanf("%d", &data);
    printf("Ancestors of %d: ", data);
    printAncestors(root, data);
    printf("\n");

    printf("Number of leaf nodes: %d\n", countLeafNodes(root));

    printf("Binary tree: ");
    printBinaryTree(root);
    printf("\n");

    return 0;
}
