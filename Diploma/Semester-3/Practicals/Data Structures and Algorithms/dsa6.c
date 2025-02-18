#include <stdio.h>
//1#include <stdlib.h>
int stack[5];
int top = 0;
void push(int value) {
    if (top >= 5 - 1) {
        printf("\n!!! Stack Overflow: Cannot push more elements. !!!\n");
    } else {
        top++;
        stack[top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}
int pop() {
    int poppedValue;
    if (top < 0) {
        printf("\n!!! Stack Underflow: Cannot pop from an empty stack. !!!\n");
        return 0;
    } else {
        poppedValue = stack[top];
        top--;
        return poppedValue;
    }
}
void display() {
    int i;
    if (top < 0) {
        printf("\n!!! Stack is empty. !!!\n");
    } else {
        printf("Stack elements: ");
        for (i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
int main() {
    int choice, value;
    while (choice != 4) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != 0) {
                    printf("Popped %d from the stack.\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exitted");
                break;
                //exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}