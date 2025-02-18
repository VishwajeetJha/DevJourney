//Practical 16A: Remove_End_LL

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next; //Self-Referential Structure
}Node;

void removeStart(Node **node){
    if(*node==NULL){
        printf("\nList Empty..!");
    }
    else if((*node)->next==NULL){
        free(*node);
        *node=NULL;
    }
    else{
        Node *p=*node;
        *node=(*node)->next;
        free(p);
        p=NULL;
    }
}
void printList(Node* node) {
    while (node != NULL) {
        printf(" %d ->", node->data);
        node = node->next;
    }
    printf(" NULL");
}

int main() {
    //basic nodes
    Node* head = (Node*)malloc(sizeof(Node));
    Node* second = (Node*)malloc(sizeof(Node));
    Node* third = (Node*)malloc(sizeof(Node));



    printf("\nList:-\n");
    printList(head);

    removeStart(&head);
    printf("\nUpdated List(removed from start):-\n");
    printList(head);

    removeStart(&head);
    printf("\nUpdated List(removed from start):-\n");
    printList(head);

    return 0;
}