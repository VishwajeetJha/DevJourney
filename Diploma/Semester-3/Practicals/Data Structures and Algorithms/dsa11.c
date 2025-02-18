//Practical 11: Insert_at_End

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next; //Self-Referential Structure
}Node;

void insertAtEnd(Node *p,int data){
    Node *temp2 = (Node*)malloc(sizeof(Node));
    temp2->data=data;
    temp2->next=NULL;

    while(p->next != NULL) {
        p = p->next; // Move to the next till we reach to node jaha pe node ka 'next' is null
    }
    p->next=temp2;
}
void printList(Node* node) {
    while (node != NULL) {
        printf(" %d ->", node->data);
        node = node->next;
    }
    printf(" NULL");
}
int main() {
    Node *head = (Node*)malloc(sizeof(Node));
    Node *sec = (Node*)malloc(sizeof(Node));

    head->data = 1;
    head->next = sec;
    sec->data = 2;
    sec->next = NULL;

    printf("\nLinked List:-\n");
    printList(head);

    insertAtEnd(head,5);
    insertAtEnd(head,3);
    insertAtEnd(head,7);

    printf("\n\nUpdated List(added to end):-\n");
    printList(head);
    
    return 0;
}