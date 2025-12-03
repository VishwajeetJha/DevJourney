//Practical 9(A): Write a program in C for sorting the elements by Bubble sortmethod.
#include <stdio.h>

int arr[] = {64, 34, 25, 12, 22, 11, 90};
int SIZE = sizeof(arr) / sizeof(arr[0]);

void main(){
    int i, j, temp;

    // ---- Bubble Sort ----
    for (i = 0; i < SIZE - 1; i++) {
        for (j = 0; j < SIZE - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nSorted array (Bubble Sort):\n");
    for (i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);

    printf("\n");
}
/*OUTPUT:-
Sorted array (Bubble Sort):
11 12 22 25 34 64 90 */