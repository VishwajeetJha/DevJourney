//Practical 2: Write a program to print numbers using arrays by using MALLOC, CALLOC and free.
#include <stdio.h>
#include <stdlib.h>

void main(){
    int *arr, *arr2;
    int n = 5;

    arr = (int *) calloc(5, sizeof(int)); // allocating memory for an array using calloc
    arr2 = (int *) malloc(sizeof(int)); // allocating memory for one variable using malloc

    for(int i=0; i<n; i++){
        arr[i] = i+1;
    }

    for(int i=0; i<n; i++){
        arr2[i] = i*2;
    }

    printf("Array elements using calloc:\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    printf("\nArray elements using malloc:\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr2[i]);
    }

    //freeing the memory after usage of these chaklis
    free(arr);
    free(arr2);
}

/*OUTPUT:
    Array elements using calloc:
    1 2 3 4 5 
    Array elements using malloc:
    0 2 4 6 8 
*/