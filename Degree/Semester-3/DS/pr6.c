//Practical 6: Write a program in C to implement above binary tree traversal methods.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
} Node;

Node* head = NULL;   // better this way

Node* createNode(int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Preorder Traversal: Root -> Left -> Right
void preorder(Node* tree) {
    if (tree != NULL) {
        printf("%d ", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

// Inorder Traversal: Left -> Root -> Right
void inorder(Node* tree) {
    if (tree != NULL) {
        inorder(tree->left);
        printf("%d ", tree->data);
        inorder(tree->right);
    }
}

// Postorder Traversal: Left -> Right -> Root
void postorder(Node* tree) {
    if (tree != NULL) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ", tree->data);
    }
}

int main(){

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Preorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    printf("\n");
    return 0;
}

/*OUTPUT:-
Preorder Traversal: 1 2 4 5 3 6 7 
Inorder Traversal: 4 2 5 1 6 3 7 
Postorder Traversal: 4 5 2 6 7 3 1 
*/