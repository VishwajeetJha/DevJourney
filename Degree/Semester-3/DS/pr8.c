//Practical 8: Write a program in C to implement the above Binary Search Algorithms.
#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (key < arr[mid])
        return binarySearch(arr, low, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, high, key);
}


void main(){
    int ARR[] = {5, 12, 23, 34, 45, 56, 67, 78, 89, 90};
    int SIZE = sizeof(ARR)/sizeof(ARR[0]); // there are 26 alphabets in English

    int key, result;
    printf("Array elements are:\n");
    for(int i=0; i<SIZE; i++){
        printf("%d ", ARR[i]);
    }
    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    result = binarySearch(ARR, 0, SIZE - 1, key);

    if(result != -1){
        printf("Element %d found at index %d\n", key, result);
    } else {
        printf("Element %d not found in the array.\n", key);
    }
}

/*OUTPUT:-
Array elements are:
5 12 23 34 45 56 67 78 89 90 
Enter the element to search: 78
Element 78 found at index 7
vish@Dora:~/Documents/DevJourney/Degree/Semester-3/DS$ ./pr8
Array elements are:
5 12 23 34 45 56 67 78 89 90 
Enter the element to search: 5
Element 5 found at index 0
vish@Dora:~/Documents/DevJourney/Degree/Semester-3/DS$ ./pr8
Array elements are:
5 12 23 34 45 56 67 78 89 90 
Enter the element to search: 29
Element 29 not found in the array.
*/