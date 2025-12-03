//Practical 13: Develop a program for selection sort.
#include <stdio.h>

int main() {
    int a[50], n, i, j, min, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Selection Sort
    for(i = 0; i < n - 1; i++) {
        min = i;  // assume current index has minimum value

        // find index of the minimum element in remaining part
        for(j = i + 1; j < n; j++) {
            if(a[j] < a[min]) {
                min = j;
            }
        }

        // swap the found minimum with element at index i
        if(min != i) {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }

    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
/*OUTPUT:-
Enter number of elements: 5
Enter 5 elements:
3
11
292
1
39 
Sorted array:
1 3 11 39 292*/