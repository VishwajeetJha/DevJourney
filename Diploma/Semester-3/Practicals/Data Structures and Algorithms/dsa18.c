#include <stdio.h>
#include <stdlib.h>

// Define a structure for a BST node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

// Function to create a new BST node
Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a key into BST
Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to search for a key in BST
Node* search(Node* root, int key) {
    // Base cases: root is null or key is present at the root
    if (root == NULL || root->data == key) {
        return root;
    }

    // Key is greater than root's key
    if (key > root->data) {
        return search(root->right, key);
    }

    // Key is smaller than root's key
    return search(root->left, key);
}

// Function to do an in-order traversal of the BST
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Driver program to test the above functions
int main() {
    Node* root = NULL;

    // Insert elements into the BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Perform in-order traversal to display the elements
    printf("In-order traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    // Search for a key in the BST
    int keyToSearch = 40;
    Node* result = search(root, keyToSearch);

    // Display the search result
    if (result != NULL) {
        printf("Key %d found in the BST.\n", keyToSearch);
    } else {
        printf("Key %d not found in the BST.\n", keyToSearch);
    }

    return 0;
}