//Practical 1: Write a program Using Pointer for call by value and call by reference.
#include <stdio.h>

void swap(int *x, int *y) //call by reference
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swap2(int x, int y) //call by value
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void main()
{
    int a = 10, b = 20;
    printf("Before swap a=%d b=%d\n", a, b);
    swap(&a, &b); //call by reference
    printf("After swap a=%d b=%d\n", a, b);

    int c = 30, d = 40;
    printf("Before swap2 c=%d d=%d\n", c, d);
    swap2(c, d); //call by value
    printf("After swap2 c=%d d=%d\n", c, d);
}

/*OUTPUT:
    Before swap a=10 b=20
    After swap a=20 b=10
    Before swap2 c=30 d=40
    After swap2 c=30 d=40
*/