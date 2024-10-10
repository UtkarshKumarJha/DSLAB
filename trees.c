#include <stdio.h>
#include <stdlib.h>

// Node structure for binary tree
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// In-Order Traversal (Iterative)
void inOrderTraversal(TreeNode* root) {
    TreeNode* stack[100];
    int top = -1;
    TreeNode* current = root;

    while (top >= 0 || current) {
        while (current) {
            stack[++top] = current;
            current = current->left;
        }

        current = stack[top--];
        printf("%d ", current->data);
        current = current->right;
    }
}

// Pre-Order Traversal (Iterative)
void preOrderTraversal(TreeNode* root) {
    if (!root) return;

    TreeNode* stack[100];
    int top = -1;
    stack[++top] = root;

    while (top >= 0) {
        TreeNode* node = stack[top--];
        printf("%d ", node->data);

        if (node->right) stack[++top] = node->right;
        if (node->left) stack[++top] = node->left;
    }
}

// Post-Order Traversal (Iterative)
void postOrderTraversal(TreeNode* root) {
    if (!root) return;

    TreeNode* stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    stack1[++top1] = root;

    while (top1 >= 0) {
        TreeNode* node = stack1[top1--];
        stack2[++top2] = node;

        if (node->left) stack1[++top1] = node->left;
        if (node->right) stack1[++top1] = node->right;
    }

    while (top2 >= 0) {
        printf("%d ", stack2[top2--]->data);
    }
}

// Find the parent of a given element
TreeNode* findParent(TreeNode* root, int value) {
    if (!root || root->data == value) return NULL;

    TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        TreeNode* current = queue[front++];

        if ((current->left && current->left->data == value) || (current->right && current->right->data == value)) {
            return current;
        }

        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }

    return NULL;
}

// Calculate the depth of the tree
int treeDepth(TreeNode* root) {
    if (!root) return 0;
    int leftDepth = treeDepth(root->left);
    int rightDepth = treeDepth(root->right);
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// Find ancestors of a given element
int findAncestors(TreeNode* root, int value, int* ancestors, int index) {
    if (!root) return 0;

    if (root->data == value) return 1;

    ancestors[index] = root->data;
    if (findAncestors(root->left, value, ancestors, index + 1) || findAncestors(root->right, value, ancestors, index + 1)) {
        return 1;
    }

    return 0;
}

// Count the number of leaf nodes
int countLeafNodes(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to create a binary tree
TreeNode* createTree(int* arr, int size, int index) {
    if (index >= size || arr[index] == -1) return NULL; // -1 indicates null node

    TreeNode* root = createNode(arr[index]);
    root->left = createTree(arr, size, 2 * index + 1);
    root->right = createTree(arr, size, 2 * index + 2);
    return root;
}

// Function to print the tree (Level Order)
void printTree(TreeNode* root) {
    if (!root) {
        printf("Tree is empty.\n");
        return;
    }

    TreeNode* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        TreeNode* current = queue[front++];
        printf("%d ", current->data);

        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }
    printf("\n");
}

// Main function for testing
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7}; // Example array to create a binary tree
    int size = sizeof(arr) / sizeof(arr[0]);
    TreeNode* root = createTree(arr, size, 0);

    printf("In-Order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

    printf("Pre-Order Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Post-Order Traversal: ");
    postOrderTraversal(root);
    printf("\n");

    int value = 4;
    TreeNode* parent = findParent(root, value);
    if (parent) {
        printf("Parent of %d: %d\n", value, parent->data);
    } else {
        printf("Parent of %d not found.\n", value);
    }

    printf("Depth of tree: %d\n", treeDepth(root));

    int ancestors[100];
    if (findAncestors(root, value, ancestors, 0)) {
        printf("Ancestors of %d: ", value);
        for (int i = 0; ancestors[i] != 0; i++) {
            printf("%d ", ancestors[i]);
        }
        printf("\n");
    } else {
        printf("Ancestors of %d not found.\n", value);
    }

    printf("Leaf nodes count: %d\n", countLeafNodes(root));
    printf("Tree elements (Level Order): ");
    printTree(root);

    return 0;
}

