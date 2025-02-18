#include <stdio.h>
int main() {
    int const n = 50;
    int fr = -1, rr = -1; //, n;
    // printf("Enter Size of Queue: ");
    // scanf("%d", &n);
    int a[n];
    int choice, item;
    while (choice != 4) {
        printf("Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (rr == n - 1) {
                    printf("\n\n-->Queue is Full\nPlease Select again:-\n");
                } else {
                    printf("Enter an element to Enqueue: ");
                    scanf("%d", &item);
                    if (fr == -1) {
                        fr = 0;
                    }
                    rr = rr + 1;
                    a[rr] = item;
                    printf("Element enqueued successfully\n");
                }
                break;
            case 2:
                if (fr == -1) {
                    printf("\n\n-->Queue is Empty\nPlease Select again:-\n");
                } else {
                    printf("Dequeued element: %d\n", a[fr]);
                    if (fr == rr) {
                        fr = -1;
                        rr = -1;
                    } else {
                        fr = fr + 1;
                    }
                }
                break;
            case 3:
                if (fr == -1) {
                    printf("\n\n-->Queue is Empty\nPlease Select again:-\n");
                } else {
                    printf("Queue Elements:-\n ");
                    for (int i = fr; i <= rr; i++) {
                        printf("%d\n ", a[i]);
                    }
                    printf("\n");
                }
                break;
            case 4:
                printf("Exiting the program\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}