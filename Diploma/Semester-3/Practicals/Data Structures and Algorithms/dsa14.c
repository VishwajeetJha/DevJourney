//Practical 14: LL_COUNT
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next; //Self-Referential Structure
} Node;

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    Node* second = (Node*)malloc(sizeof(Node));
    Node* third = (Node*)malloc(sizeof(Node));

    int cnt = 0;

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;
    
    while (head != NULL) {
        head = head->next; // Move to the next node
        cnt++;
    }
    printf("Number of nodes: %d", cnt);
    
    //free memory after usage is complete, not required always but always better to do :3
    free(head);
    free(second);
    free(third);
    return 0;
}