#include <stdio.h>
// #include <conio.h> //uncomment for turbo c
#include <time.h>

// Function for Selection Sort
void selectionSort(int a[], int n) {
    int i, j, min, temp;

    for (i = 0; i < n - 1; i++) {
        min = i;  // assume the first element is minimum

        // Find the minimum element in unsorted array
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;  // update index of minimum element
            }
        }

        // Swap the found minimum element with the first element
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

// Function for Bubble Sort
void bubbleSort(int a[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        // Last i elements are already sorted
        for (j = 0; j < n - i - 1; j++) {
            // If the element found is greater than the next element
            if (a[j] > a[j + 1]) {
                // Swap them
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Function for Insertion Sort
void insertionSort(int a[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = a[i];     // element to be inserted
        j = i - 1;

        // Move elements of a[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key; // place key at correct position
    }
}

int main() {
    int n, i;
    int arr[100], temp[100];  // fixed size arrays for Turbo C++

    time_t start, end;  // variables to store start and end time
    double time_taken;  // variable to store time difference

 //   clrscr();  // clear screen - uncomment for turbo c

    // Input number of elements
    printf("Enter number of elements (max 100): ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    // ------------------- Selection Sort -------------------
    // Copy original array into temp array
    for (i = 0; i < n; i++)
        temp[i] = arr[i];

    start = clock();;           // start time
    selectionSort(temp, n);       // call selection sort
    end = clock();;             // end time

    // Calculate execution time
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nSelection Sort Time: %f seconds\n", time_taken);

    // ------------------- Bubble Sort -------------------
    // Copy original array into temp array
    for (i = 0; i < n; i++)
        temp[i] = arr[i];

    start = clock();;           // start time
    bubbleSort(temp, n);          // call bubble sort
    end = clock();;             // end time

    // Calculate execution time
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort Time: %f seconds\n", time_taken);

    // ------------------- Insertion Sort -------------------
    // Copy original array into temp array
    for (i = 0; i < n; i++)
        temp[i] = arr[i];

    start = clock();;           // start time
    insertionSort(temp, n);       // call insertion sort
    end = clock();;             // end time

    // Calculate execution time
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Insertion Sort Time: %f seconds\n", time_taken);

 //   getch();  // wait for user input before closing - uncomment for turbo c
    return 0;
}