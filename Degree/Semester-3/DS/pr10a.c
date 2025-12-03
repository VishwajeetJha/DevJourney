//Practical 10(A): Write a program in C for sorting the elements by Insertion sortmethod.
#include <stdio.h>

int arr[] = {78, 99, 25, 122, 2, 11, 95, 67, 43, 88};
int SIZE = sizeof(arr) / sizeof(arr[0]);

void main(){
    int i, j, key;

    // ---- Insertion Sort ----
    for (i = 1; i < SIZE; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }

    printf("\nSorted array (Insertion Sort):\n");
    for (i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

/*OUTPUT:-
Sorted array (Insertion Sort):
2 11 25 43 67 78 88 95 99 122*/