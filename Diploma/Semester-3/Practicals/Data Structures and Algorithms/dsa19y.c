#include<stdio.h>
int main() {
    int n;
    printf("Enter Size of Array: \n");
    scanf("%d", &n);
    int a[n], i, j, x;
    printf("Enter Elements of Array: \n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Elements of Array (Unsorted): \n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    for(i=0; i<n; i++){
        for(j=0; j<n-1; j++){
            if(a[j]>a[j+1]){
                x = a[j];
                a[j] = a[j+1];
                a[j+1] = x;
            }
        }
    }
    printf("\nElements of Array (Sorted): \n");
    for (i = 0; i < n; i++) {
    printf("%d ", a[i]);
    }
    return 0;
}