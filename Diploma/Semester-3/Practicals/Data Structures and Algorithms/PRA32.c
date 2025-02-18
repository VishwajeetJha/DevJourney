#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insertNode(struct Node** head_ref, int data, int position) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    if (position == 0) {
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    struct Node* temp = *head_ref;
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL) {
        printf("Position out of range");
        return;
    }
    new_node->next = temp->next;
    temp->next = new_node;
}
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ->", node->data);
        node = node->next;
        if(node == NULL){
            printf("NULL\n");
        }
    }
}
int main() {
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1; // Assign data in first node
    head->next = second; // Link first node with the second node
    second->data = 2; // Assign data to second node
    second->next = third; // Link second node with the third node
    third->data = 3; // Assign data to third node
    third->next = NULL;
    printf("Linked list before insertion: ");
    printList(head);
    int position = 1; // Position of node to be inserted
    int data = 4; // Data for the new node
    insertNode(&head, data, position);
    printf("\nLinked list after insertion at position %d: ", position);
    printList(head);
    return 0;
}