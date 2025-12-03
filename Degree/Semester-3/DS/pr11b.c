//Practical 11(B): Write a program in C for sorting the elements by Radix sortmethod.
#include <stdio.h>

// Function to get the maximum element in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Counting Sort used by Radix Sort for each digit
void countingSort(int arr[], int n, int place) {
    int output[n];
    int count[10] = {0};

    // Count occurrences of digits
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / place) % 10;
        count[digit]++;
    }

    // Convert count[] to cumulative count (for stable sort)
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array from end → start (to remain stable)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / place) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy output[] back into arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Main Radix Sort function
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Apply counting sort for each digit (1s, 10s, 100s...)
    for (int place = 1; max / place > 0; place *= 10)
        countingSort(arr, n, place);
}

void main(){
    int arr[] = {329, 457, 657, 839, 436, 720, 355};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\nUnsorted array (Merge Sort):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    radixSort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
}
/*OUTPUT:-
Unsorted array (Merge Sort):
329 457 657 839 436 720 355 
Sorted array:
329 355 436 457 657 720 839 */