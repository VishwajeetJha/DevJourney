//Practical 4(C): Perform given pattern programs. (Nested for loop)
#include <stdio.h>

void main(){
    //Pattern 1
    int i, j, k, n = 5;
    printf("\nRight Triangle Pattern:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }
    //Pattern 2
    printf("\nInverted Triangle Pattern:\n");
    for(i = n; i >= 1; i--) {
        for(j = 1; j <= i; j++)
            printf("* ");
        printf("\n");
    }
    //Pattern 3
    printf("\nPyramid Pattern:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n - i; j++)
            printf("  ");
        for(k = 1; k <= (2*i - 1); k++)
            printf("* ");
        printf("\n");
    }
    //Pattern 4
    printf("\nNumber Triangle Pattern:\n");
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= i; j++)
            printf("%d ", j);
        printf("\n");
    }
}

/*OUTPUT:-
Right Triangle Pattern:
* 
* * 
* * * 
* * * * 
* * * * * 

Inverted Triangle Pattern:
* * * * * 
* * * * 
* * * 
* * 
* 

Pyramid Pattern:
        * 
      * * * 
    * * * * * 
  * * * * * * * 
* * * * * * * * * 

Number Triangle Pattern:
1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5 
*/