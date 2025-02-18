//Data Structure and Algorithms Practical 4: Binary Search

#include <stdio.h>
int main() {
    int N;
    printf("Enter size of sorted array: ");
    scanf("%d", &N);
    int a[N];
    int x, i;
    printf("Enter elements of sorted array: \n");
    for (i = 0; i < N; i++) {
        printf("Element at Index No %d: ", i);
        scanf("%d", &a[i]);
    }
    printf("Enter Number to find its Index in your given Array: ");
    scanf("%d", &x);
    int left = 0;
    int right = N - 1;
    int found = 0;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (a[mid] == x) {
            printf("\nFound element at Index No: %d Number you Searched for: %d \n", mid, x);
            found = 1;
            break;
        }
        if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        // If not found in ascending order, reset variables and search in descending order
        left = 0;
        right = N - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (a[mid] == x) {
                printf("\nFound element at Index No: %d Number you Searched for: %d \n", mid, x);
                found = 1;
                break;
            }
            if (a[mid] > x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (!found) {
            printf("\nUnsuccessful search..! Number Not Found.\n");
        }
    }
    return 0;
}