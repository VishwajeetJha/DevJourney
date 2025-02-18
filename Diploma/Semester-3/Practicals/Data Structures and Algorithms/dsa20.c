#include<stdio.h>
int main() {
    int a[10] = {32,213,5,32,78,2,34,35,77,92};
    int i, j, minIndex, x;
    printf("Enter elements of the array:\n");
    printf("Array before sorting:\n");
    for (i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        printf("%d ", a[i]);
    }
    for (i = 0; i < sizeof(a)/sizeof(a[0]) - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < sizeof(a)/sizeof(a[0]); j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        x = a[i];
        a[i] = a[minIndex];
        a[minIndex] = x;
    }
    printf("\nArray after sorting:\n");
    for (i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        printf("%d ", a[i]);
    }
    return 0;
}