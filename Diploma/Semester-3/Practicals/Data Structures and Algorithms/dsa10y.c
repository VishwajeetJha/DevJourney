#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

void insertAtBeginning(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}
void printList(Node* node) {
    while (node != NULL) {
        printf(" %d ->", node->data);
        node = node->next;
    }
    printf(" NULL");
}
int main() {
    Node* head = NULL;
    insertAtBeginning(&head, 6);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 9);
    insertAtBeginning(&head, 0);
    printf("Created linked list is:");
    printList(head);
    return 0;
}