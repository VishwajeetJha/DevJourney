//ITERATIVE METHOD: Binary Search
// #include <stdio.h>
// #include <time.h>

// void binarySearch(int array[], int n, int key) {
//     int low = 0, high = n - 1, mid;
//     while (low <= high) {
//         mid = (low + high) / 2;
//         if (array[mid] == key) {
//             printf("%d found at location %d\n", key, mid + 1);
//             return;
//         } else if (array[mid] < key) {
//             low = mid + 1;
//         } else {
//             high = mid - 1;
//         }
//     }
//     printf("%d not found\n", key);
// }

// int main() {
//     int array[100], n, key, i;
//     clock_t start, end;
//     double time_taken;

//     printf("Binary Search O(log n)\n");
//     printf("Enter n: ");
//     scanf("%d", &n);

//     printf("Enter %d sorted elements:\n", n);
//     for (i = 0; i < n; i++) scanf("%d", &array[i]);

//     printf("Search element: ");
//     scanf("%d", &key);

//     start = clock();
//     binarySearch(array, n, key);
//     end = clock();

//     time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
//     printf("Time: %f s\n", time_taken);

//     return 0;
// }

//RECURSIVE METHOD: Binary Search
#include <stdio.h>
#include <time.h>

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;

    if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, high, key);
}

int main() {
    int arr[100], n, key;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    start = clock();
    int result = binarySearch(arr, 0, n - 1, key);
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
