#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the BST
typedef struct node {
    int key;
    struct node *left, *right;
}node;

// Function to create a new node
node* newNode(int item) {
    node* temp = (node*)malloc(sizeof(node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to perform inorder traversal
void inorder(node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Function to perform preorder traversal
void preorder(node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform postorder traversal
void postorder(node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

// // Function to insert a new node with a given key
node* insert(node* node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    return node;
}

// Main function
int main() {
    node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}