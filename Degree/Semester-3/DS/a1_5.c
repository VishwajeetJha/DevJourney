#include <stdio.h>
#define SIZE 5

int cq[SIZE];
int FRONT = -1, REAR = -1;

// Function to insert (enqueue)
void enqueue(int value) {
    if ((FRONT == 0 && REAR == SIZE - 1) || (REAR == (FRONT - 1) % (SIZE - 1))) {
        printf("Queue is Full!\n");
        return;
    }
    else if (FRONT == -1) { // First element
        FRONT = REAR = 0;
        cq[REAR] = value;
    }
    else if (REAR == SIZE - 1 && FRONT != 0) { // Wrap around
        REAR = 0;
        cq[REAR] = value;
    }
    else {
        REAR++;
        cq[REAR] = value;
    }
}

// Function to delete (dequeue)
void dequeue() {
    if (FRONT == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Deleted: %d\n", cq[FRONT]);

    if (FRONT == REAR) { // Only one element
        FRONT = REAR = -1;
    }
    else if (FRONT == SIZE - 1) { // Wrap around
        FRONT = 0;
    }
    else {
        FRONT++;
    }
}

// Display function
void display() {
    if (FRONT == -1) {
        printf("Queue is Empty!\n");
        return;
    }

    printf("Queue elements: ");
    if (REAR >= FRONT) {
        for (int i = FRONT; i <= REAR; i++)
            printf("%d ", cq[i]);
    }
    else {
        for (int i = FRONT; i < SIZE; i++)
            printf("%d ", cq[i]);
        for (int i = 0; i <= REAR; i++)
            printf("%d ", cq[i]);
    }
    printf("\n");
}

void main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    display();

    dequeue();
    dequeue();

    display();

    enqueue(60);
    enqueue(70);

    display();
}
