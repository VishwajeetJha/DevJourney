//Practical 14: Develop a program for merge sort.
#include <stdio.h>

void merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    int temp[100];

    // Merge two sorted halves into temp[]
    while (i <= mid && j <= high) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    // Copy remaining elements of left half
    while (i <= mid)
        temp[k++] = a[i++];

    // Copy remaining elements of right half
    while (j <= high)
        temp[k++] = a[j++];

    // Copy temp[] back into a[]
    for (i = low, k = 0; i <= high; i++, k++)
        a[i] = temp[k];
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);      // sort left half
        mergeSort(a, mid + 1, high); // sort right half
        merge(a, low, mid, high);    // merge both halves
    }
}

int main() {
    int n, i;
    int a[50];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergeSort(a, 0, n - 1);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
/*OUTPUT:-
Enter number of elements: 7
Enter 7 elements:
22 13 9 193 1 5 75
Sorted array:
1 5 9 13 22 75 193*/