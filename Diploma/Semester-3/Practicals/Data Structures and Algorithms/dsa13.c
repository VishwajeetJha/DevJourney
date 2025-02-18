//Practical 13: LL_Insert_Bef_Pos
#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next; //Self-Referential Structure
}Node;
void printList(Node* node) {
    while (node != NULL) {
        printf(" %d ->", node->data);
        node = node->next;
    }
    printf(" NULL");
}
int main() {
    //Main Nodes
    Node *head =  (Node*)malloc(sizeof(Node));
    Node *sec = (Node*)malloc(sizeof(Node));
    Node *thr = (Node*)malloc(sizeof(Node));
    Node *q = (Node*)malloc(sizeof(Node));
    Node *p = (Node*)malloc(sizeof(Node));
    Node *add = (Node*)malloc(sizeof(Node));
    int pos;        //To record position 
    p=q=head;
    add->data=5;
    add->next=NULL;
    head->data = 1;         //0
    head->next = sec;
    sec->data = 2;          //1
    sec->next = thr;
    thr->data=3;            //2
    thr->next=NULL;
    printList(head);
    printf("\n\nEnter position to insert node before: ");
    scanf("%d", &pos);
    for(int i=0; i<=pos && q->next != NULL; i++) {
        q=q->next;
        if(i==pos-1 && q!=NULL){
            add->next=p->next;
            p->next=add;
            add->next=q;
            break;
        }
        else if(pos==0){
            break;
        }
        else if(q->next==NULL){
            q->next=add;
            add->next=NULL;
        }
        p=p->next;
    }
    if(pos==0){     //position = 0 means beginning
            add->next=head;
            head=add;
    }
    printf("\nUpdated list(inserted %d):-\n", add->data);
    printList(head);
    return 0;
}