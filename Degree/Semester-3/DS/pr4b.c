//Pratical 4(B): Write a program to print even numbers from 75 to 50 in decreasing order.
#include <stdio.h>

void main(){
    printf("Even numbers from 75 to 50 in decreasing order:\n");
    for(int i=75; i>=50; i--){
        if(i%2 == 0){
            printf("%d ", i);
        }
    }
    printf("\n");
}

/*OUTPUT:-
Even numbers from 75 to 50 in decreasing order:
74 72 70 68 66 64 62 60 58 56 54 52 50 
*/