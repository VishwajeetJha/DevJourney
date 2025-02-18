#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the BST
typedef struct tree {
    int key;
    struct tree *LPTR, *RPTR;
}tree;

// Function to create a new node
tree* newNode(int item) {
    tree* temp = (tree*)malloc(sizeof(tree));
    temp->key = item;
    temp->LPTR = temp->RPTR = NULL;
    return temp;
}

// Function to perform inorder traversal
void inorder(tree* root) {
    if (root != NULL) {
        inorder(root->LPTR);
        printf("%d ", root->key);
        inorder(root->RPTR);
    }
}

// Function to perform preorder traversal
void preorder(tree* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder(root->LPTR);
        preorder(root->RPTR);
    }
}

// Function to perform postorder traversal
void postorder(tree* root) {
    if (root != NULL) {
        postorder(root->LPTR);
        postorder(root->RPTR);
        printf("%d ", root->key);
    }
}

// Function to insert a new node with a given key
tree* insert(tree* node, int key) {
    if (node == NULL){
        return newNode(key);
    }
    else if (key < node->key){
        node->LPTR = insert(node->LPTR, key);
    }
    else if (key > node->key){
        node->RPTR = insert(node->RPTR, key);
    }
    return node;
}

// Function to find the node with the minimum key value
tree* minValueNode(tree* node) {
    tree* current = node;
    while (current && current->LPTR != NULL)
        current = current->LPTR;
    return current;
}

// Function to delete a node with a given key
tree* deleteNode(tree* root, int key) {
    if (root == NULL) return root;
    if (key < root->key) root->LPTR = deleteNode(root->LPTR, key);
    else if (key > root->key) root->RPTR = deleteNode(root->RPTR, key);
    else {
        if (root->LPTR == NULL) {
            tree* temp = root->RPTR;
            free(root);
            return temp;
        }
        else if (root->RPTR == NULL) {
            tree* temp = root->LPTR;
            free(root);
            return temp;
        }
        tree* temp = minValueNode(root->RPTR);
        root->key = temp->key;
        root->RPTR = deleteNode(root->RPTR, temp->key);
    }
    return root;
}

// Function to search for a key in the BST
tree* search(tree* root, int key) {
    if (root == NULL || root->key == key) return root;
    if (root->key < key) return search(root->RPTR, key);
    return search(root->LPTR, key);
}

// Main function
int main() {
    tree* root = NULL;
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

    printf("Deleting 70\n");
    root = deleteNode(root, 70);
    printf("Inorder traversal after deletion: ");
    inorder(root);
    printf("\n");

    tree* result = search(root, 60);
    if (result != NULL)
        printf("Element 60 found in the BST\n");
    else
        printf("Element 60 not found in the BST\n");

    return 0;
}