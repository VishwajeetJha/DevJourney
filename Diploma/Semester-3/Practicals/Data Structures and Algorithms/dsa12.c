//Practical 12: Insert_ordered_list

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next; //Self-Referential Structure
}Node;

int ins_ord(Node *node, int data){
    Node *temp2=(Node *)malloc(sizeof(Node));
    Node *p=(Node *)malloc(sizeof(Node));

    temp2->next=NULL;
    temp2->data=data;
    
    p=node;

    while(node != NULL){
        p=p->next;             //successing node
        if(temp2->data < node->data){      //case 1: insertion_node->data LESS THAN preceeding_node->data
            temp2->next=node;
            break;
        }
        else if(temp2->data > node->data && temp2->data < p->data ){     //case 2: insertion_node->data GREATER THAN preceeding_node->data
            temp2->next=p;
            node->next=temp2;
            break;
        }
        else if(temp2->data==node->data){       //case 3: insertion_node->data EQUAL TO preceeding_node->data
            temp2->next=node->next;
            node->next=temp2;
            break;
        }
        else if(p->next==NULL){
            p->next=temp2;
            break;
        }
        node=node->next;       //preceeding node
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
    Node* head = (Node*)malloc(sizeof(Node));
    Node* sec = (Node*)malloc(sizeof(Node));

    //old nodes: [  1 | -]-->[  3 |N]
    head->data = 1;
    head->next = sec;
    sec->data = 3;
    sec->next = NULL;

    printf("List before insertion:-\n");
    printList(head);

    //call format ins_ord(head_pointer, value_to_put)
    ins_ord(head,5);
    ins_ord(head,3);
    ins_ord(head,8);
    ins_ord(head,2);

    printf("\n\nUpdated list(inserted):-\n");
    printList(head);

    return 0;
}