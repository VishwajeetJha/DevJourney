//Practical 15: LL_Search

#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next; //Self-Referential Structure
}Node;
int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    Node* second = (Node*)malloc(sizeof(Node));
    Node* third = (Node*)malloc(sizeof(Node));

    int cnt = 0;
    int x;

    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = NULL;

    printf("\nEnter Element to find: ");
    scanf("%d", &x);

    while (head->data != x && head != NULL) {
        head = head->next; // Move to the next node
        cnt++;
    }
    if(head->data==x){
        printf("Found node at position: %d", cnt);
    }
    else{
        printf("\nUnsuccessful search!\n");
    }

    free(head);
    free(second);
    free(third);
    return 0;
}