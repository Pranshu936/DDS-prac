#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;  // Return unchanged root pointer
}

// Function to find the minimum value node in a tree (used in deletion)
struct Node* findMinNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: get the inorder successor (smallest in the right subtree)
        struct Node* temp = findMinNode(root->right);
        root->data = temp->data;  // Copy inorder successor's data to this node
        root->right = deleteNode(root->right, temp->data);  // Delete the inorder successor
    }

    return root;
}

// Function for inorder traversal (prints the tree in ascending order)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Main function to test the BST
int main() {
    struct Node* root = NULL;
    
    // Insert nodes into the BST
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    printf("Inorder traversal of the BST:\n");
    inorderTraversal(root);
    printf("\n");

    // Delete a node and print the updated tree
    root = deleteNode(root, 20);
    printf("Inorder traversal after deleting 20:\n");
    inorderTraversal(root);
    printf("\n");

    root = deleteNode(root, 30);
    printf("Inorder traversal after deleting 30:\n");
    inorderTraversal(root);
    printf("\n");

    root = deleteNode(root, 50);
    printf("Inorder traversal after deleting 50:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
