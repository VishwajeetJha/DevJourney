//Practical 10(B): Write a program in C for sorting the elements by Merge sortmethod.
#include <stdio.h>

int arr[] = {66, 34, 89, 12, 45, 23, 78, 90, 11, 56};
int SIZE = sizeof(arr) / sizeof(arr[0]);

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2]; // temporary arrays

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    // Merge the temp arrays back into arr[]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);        // Sort first half
        mergeSort(arr, mid + 1, right);   // Sort second half
        merge(arr, left, mid, right);     // Merge both halves
    }
}

void main(){
    printf("\nUnsorted array (Merge Sort):\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);

    mergeSort(arr, 0, SIZE - 1);

    printf("\nSorted array (Merge Sort):\n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);

    printf("\n");
}

/*OUTPUT:-
Unsorted array (Merge Sort):
66 34 89 12 45 23 78 90 11 56 
Sorted array (Merge Sort):
11 12 23 34 45 56 66 78 89 90 
*/