#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main() {
    struct node* first = NULL;
    struct node* sec = NULL;
    struct node* last = NULL;

    first = (struct node*)malloc(sizeof(struct node));
    sec = (struct node*)malloc(sizeof(struct node));
    last = (struct node*)malloc(sizeof(struct node));

    //first->data = 1;
    first->next = sec;
    //sec->data = 2;
    sec->next = last;
    //last->data = 3;
    last->next = NULL;

    struct node* current = first; //seperate pointer chahiye, wapis first node pe jaane ko and to iterate

    while (current != NULL) {
        printf("Enter element: ");
        scanf("%d", &(current->data));
        current = current->next;
    }

    current = first; //wapis first pointer pe going

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
        if(current==NULL){
            printf("NULL\n");
        }
    }
    
    return 0;
}
