//Practical 11(A): Write a program in C for sorting the elements by Quick sortmethod.
#include <stdio.h>

int arr[] = {23, 45, 12, 67, 34, 89, 10, 5, 78, 56};
int SIZE = sizeof(arr) / sizeof(arr[0]);

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot element
    int i = low - 1;       // index of smaller element
    int temp;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // swap arr[i] and arr[j]
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // swap arr[i+1] and arr[high] (pivot)
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // return pivot position
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);  // Left part
        quickSort(arr, p + 1, high); // Right part
    }
}

void main(){
    printf("\nUnsorted array (Merge Sort):\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);

    quickSort(arr, 0, SIZE - 1);

    printf("\nSorted array (Quick Sort):\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

/*OUTPUT:-
Unsorted array (Merge Sort):
23 45 12 67 34 89 10 5 78 56 
Sorted array (Quick Sort):
5 10 12 23 34 45 56 67 78 89 */