//Practical 7: Write a program in C to implement the above Sequential SearchAlgorithms.
#include <stdio.h>

int ARR[] = {34, 7, 23, 32, 5, 62};
int SIZE = sizeof(ARR)/sizeof(ARR[0]); //finding the count of the array the smart way, total size/size of int

void main(){
    int key, found = 0;
    printf("Array elements are:\n");
    for(int i=0; i<SIZE; i++){
        printf("%d ", ARR[i]);
    }
    printf("\nEnter the element to search: ");
    scanf("%d", &key);

    for(int i=0; i<SIZE; i++){
        if(ARR[i] == key){
            printf("Element %d found at index %d\n", key, i);
            found = 1;
            break;
        }
    }

    if(!found){
        printf("Element %d not found in the array.\n", key);
    }
}

/*OUTPUT:-
Array elements are:
34 7 23 32 5 62 
Enter the element to search: 5
Element 5 found at index 4
vish@Dora:~/Documents/DevJourney/Degree/Semester-3/DS$ ./pr7
Array elements are:
34 7 23 32 5 62 
Enter the element to search: 9
Element 9 not found in the array.
vish@Dora:~/Documents/DevJourney/Degree/Semester-3/DS$ ./pr7
Array elements are:
34 7 23 32 5 62 
Enter the element to search: 32
Element 32 found at index 3
*/