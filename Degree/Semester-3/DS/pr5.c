//Practical 5: Write a program in C to perform various operations on Singly LinkedList.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;   // better this way

Node* createNode(int val) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insert(int val) {
    Node* newNode = createNode(val);
    if(newNode == NULL) return;

    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void delete() {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if(head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    Node *temp = head, *prev = NULL;

    while(temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void display() {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;
    printf("Linked List: ");

    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void search(int key) {
    Node* temp = head;
    int pos = 1;

    while(temp != NULL) {
        if(temp->data == key) {
            printf("Element %d found at position %d\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Element not found!\n");
}

void deleteAtStart() {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;
    head = head->next;
    free(temp);
}

void insertAtStart(int val) {
    Node* newNode = createNode(val);
    if(newNode == NULL) return;

    newNode->next = head;
    head = newNode;
}

void insertAtPosition(int val, int pos) {
    if(pos <= 0) {
        printf("Invalid position!\n");
        return;
    }

    Node* newNode = createNode(val);
    if(newNode == NULL) return;

    if(pos == 1) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for(int i = 1; i < pos - 1 && temp != NULL; i++){
        if(temp->next == NULL){
            printf("Position out of range! Inserting at end..\n");
            break; //exiting if last node, complaining and putting value lol
        }
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Position out of range! Inserting at end..\n");
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPosition(int pos) {
    if(head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if(pos == 1) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }

    Node *temp = head, *prev = NULL;
    for(int i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}


int main(){
    int choice, val, pos;

    while(1) {
        printf("\n---- Singly Linked List Operations ----\n");
        printf("1. Insert at Start\n");
        printf("2. Insert at Last\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Start\n");
        printf("5. Delete at Last\n");
        printf("6. Delete at Position\n");
        printf("7. Search Element\n");
        printf("8. Display List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter val: ");
                scanf("%d", &val);
                insertAtStart(val);
                break;

            case 2:
                printf("Enter val: ");
                scanf("%d", &val);
                insert(val);
                break;

            case 3:
                printf("Enter val: ");
                scanf("%d", &val);
                printf("\nEnter position: ");
                scanf("%d", &pos);
                insertAtPosition(val, pos);
                break;

            case 4:
                deleteAtStart();
                break;

            case 5:
                delete();
                break;

            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;

            case 7:
                printf("Enter val to search: ");
                scanf("%d", &val);
                search(val);
                break;

            case 8:
                display();
                break;

            case 9:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

/*OUTPUT:-
---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 1
Enter value: 22

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 1
Enter value: 44

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 2
Enter value: 42 

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 1
Enter value: 29

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 8
Linked List: 29 -> 44 -> 22 -> 42 -> NULL

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 7
Enter value to search: 2
Element not found!

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 7
Enter value to search: 22
Element 22 found at position 3

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 4

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 5

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 8
Linked List: 44 -> 22 -> NULL

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 2
Enter value: 99

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 2
Enter value: 78

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 2
Enter value: 78

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 8
Linked List: 44 -> 22 -> 99 -> 78 -> 78 -> NULL

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 6
Enter position to delete: 3

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 8
Linked List: 44 -> 22 -> 78 -> 78 -> NULL

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 3
Enter value: 98

Enter position: 2 

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 8
Linked List: 44 -> 98 -> 22 -> 78 -> 78 -> NULL

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 9
Exiting...

--Fixed any position out of range issue--
---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 2
Enter value: 323

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 3
Enter value: 29

Enter position: 32
Position out of range! Inserting at end..

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 8
Linked List: 323 -> 29 -> NULL

---- Singly Linked List Operations ----
1. Insert at Start
2. Insert at Last
3. Insert at Position
4. Delete at Start
5. Delete at Last
6. Delete at Position
7. Search Element
8. Display List
9. Exit
Enter your choice: 9
Exiting...*/