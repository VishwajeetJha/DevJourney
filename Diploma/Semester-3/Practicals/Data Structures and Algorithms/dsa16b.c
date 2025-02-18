//Practical 16B: Remove_End_LL

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next; //Self-Referential Structure
}Node;

void removeEnd(Node **node){
    if(*node==NULL){
        printf("List Empty..!\n");
    }
    else if((*node)->next==NULL){
        free(*node);
        *node=NULL;
    }
    else{
        Node *p=*node;
        Node *q=*node;
        while(p != NULL) {
            p = p->next; // Move to the next node
            if(p->next == NULL){
                q->next=NULL;
                free(p);
                p=NULL;
                break;
            }
            q = q->next;
        }
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

    //Initializations
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    printf("\nList:-\n");
    printList(head);

    printf("\nUpdated List(removed from end):-\n");
    removeEnd(&head);
    printList(head);

    printf("\nUpdated List(removed from end):-\n");
    removeEnd(&head);
    printList(head);

    return 0;
}