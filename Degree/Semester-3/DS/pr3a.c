//Practical 3(A): Write a program in C for implementing a stack using arrays. It involves various operations such as push, pop and display.
#include <stdio.h>

#define SIZE 20

int stack[SIZE];
int TOP = -1;


void pop(){
    if(TOP == -1){
        printf("ERR: Stack Underflow!\n");
    }
    else{
        printf("Popping element: %d", stack[TOP]);
        TOP--;
    }
}

void push(int n){
    if(TOP == SIZE-1){
        printf("ERR: Stack Overflow!\n");
    }
    else{
        TOP++;
        stack[TOP] = n;
        printf("Pushed element: %d\n", n);
    }
}

void display(){
    if(TOP == -1){
        printf("ERR: Stack is empty!\n");
    }
    else{
        printf("Stack elements are:\n");
        for(int i=TOP; i>=0; i--){
        printf("%d ", stack[i]);
        }
    }
}

void main(){
    int choice, n;
    while(1){
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &n);
                push(n);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                return;
            default:
                printf("Invalid choice!\n");
        }
    }
}

/*OUTPUT:-


1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter the element to be pushed: 23
Pushed element: 23

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter the element to be pushed: 34
Pushed element: 34

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 1
Enter the element to be pushed: 99
Pushed element: 99

1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack elements are:
99 34 23 
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
Popping element: 99
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 2
Popping element: 34
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 3
Stack elements are:
23 
1. Push
2. Pop
3. Display
4. Exit
Enter your choice: 4
Exiting...

*/