//Practical 3(B): Develop a program that allows the user to insert 3 numbers, it should display all numbers in increasing order. (Nested if else concept).
#include <stdio.h>

void main(){
    int a, b, c;
    printf("Enter 3 numbers: \na b c\n");
    scanf("%d %d %d", &a, &b, &c);

    printf("\nNumbers in increasing order: \n");

    if (a <= b && a <= c) {       // a is smallest
        printf("%d ", a);
        if (b <= c)
            printf("%d %d", b, c);
        else
            printf("%d %d", c, b);
    }
    else if (b <= a && b <= c) {  // b is smallest
        printf("%d ", b);
        if (a <= c)
            printf("%d %d", a, c);
        else
            printf("%d %d", c, a);
    }
    else {                        // c is smallest
        printf("%d ", c);
        if (a <= b)
            printf("%d %d", a, b);
        else
            printf("%d %d", b, a);
    }
    printf("\n");
}