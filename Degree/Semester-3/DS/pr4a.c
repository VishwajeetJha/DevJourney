//Practical 4(A): Write a program in C for implementing the queue using arrays with its basic operations like insert & delete element. Also display the queue.
#include <stdio.h>

#define SIZE 20

int queue[SIZE];
int FRONT = -1, REAR = -1;

void enqueue(int element){
    if(REAR == SIZE - 1){
        printf("ERR: Queue Overflow!\n");
        return;
    }
    if(FRONT == -1) FRONT = 0;
    queue[++REAR] = element; 
    printf("Inserted: %d\n", element);
}

void dequeue(){
    if(FRONT == -1 || FRONT > REAR){    //ensuring FRONT is behind REAR
        printf("ERR: Queue Underflow!\n");
        return;
    }
    printf("Deleted: %d\n", queue[FRONT++]);
    if(FRONT > REAR) FRONT = REAR = -1; //reset
}

void display(){
    if(FRONT == -1){
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements:\n");
    for(int i = FRONT; i <= REAR; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void main(){
    int choice, element;
    while(1){
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue (Insert)\n");
        printf("2. Dequeue (Delete)\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

/*OUTPUT:-
Queue Operations Menu:
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display Queue
4. Exit
Enter your choice: 1
Enter element to insert: 22
Inserted: 22

Queue Operations Menu:
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display Queue
4. Exit
Enter your choice: 1
Enter element to insert: 44
Inserted: 44

Queue Operations Menu:
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display Queue
4. Exit
Enter your choice: 1
Enter element to insert: 32
Inserted: 32

Queue Operations Menu:
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display Queue
4. Exit
Enter your choice: 3
Current Queue: 22 44 32 

Queue Operations Menu:
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display Queue
4. Exit
Enter your choice: 2
Deleted: 22

Queue Operations Menu:
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display Queue
4. Exit
Enter your choice: 2
Deleted: 44

Queue Operations Menu:
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display Queue
4. Exit
Enter your choice: 2
Deleted: 32

Queue Operations Menu:
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display Queue
4. Exit
Enter your choice: 2
ERR: Queue Underflow!

Queue Operations Menu:
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display Queue
4. Exit
Enter your choice: 3
Queue is empty.

Queue Operations Menu:
1. Enqueue (Insert)
2. Dequeue (Delete)
3. Display Queue
4. Exit
Enter your choice: 4
Exiting...
*/