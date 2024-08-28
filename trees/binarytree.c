#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;


TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to build a binary tree recursively
TreeNode* buildBinaryTree() {
    int data;
    printf("Enter data for the node (or -1 to indicate NULL): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL; 
    }

    TreeNode* newNode = createNode(data);

    printf("Enter left child for %d:\n", data);
    newNode->left = buildBinaryTree();

    printf("Enter right child for %d:\n", data);
    newNode->right = buildBinaryTree();

    return newNode;
}

void inorderTraversal(TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    TreeNode* root = NULL;

    // Build the binary tree
    printf("Building the binary tree:\n");
    root = buildBinaryTree();

    printf("\nInorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
