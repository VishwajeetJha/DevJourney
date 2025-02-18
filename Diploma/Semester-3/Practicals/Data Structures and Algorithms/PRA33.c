#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void deleteNode(struct Node **head_ref, int position) {
    if (*head_ref == NULL)
        return;
    struct Node* temp = *head_ref;
    if (position == 0) {
        *head_ref = temp->next; // Change head
        free(temp); // Free old head
        return;
    }
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
    if (temp == NULL || temp->next == NULL)
        return;
    struct Node* next = temp->next->next;
    free(temp->next); // Free memory
    temp->next = next; // Unlink the deleted node
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
    printf("Linked list before deletion: ");
    printList(head);
    int position = 1; // Position of node to be deleted
    deleteNode(&head, position);
    printf("\nLinked list after deletion at position %d: ", position);
    printList(head);
    return 0;
}