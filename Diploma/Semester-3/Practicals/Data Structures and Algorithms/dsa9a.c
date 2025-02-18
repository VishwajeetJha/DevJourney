#include <stdio.h>
int main() {
    int i, j, *p1, *p2;
    printf("Enter Value of I and J: \n");
    scanf("%d", &i);
    scanf("%d", &j);
    p1 = &i;
    p2 = &j;
    printf("Addition of %d + %d = %d\n", *p1, *p2, *p1 + *p2);
    printf("Multiplication of %d * %d = %d\n", *p1, *p2, *p1 * *p2);
    printf("Subtraction of %d - %d = %d\n", *p1, *p2, *p1 - 
    *p2);
    if (*p2 != 0) {
        printf("Division of %d / %d = %.2f\n", *p1, *p2, (double)*p1 / *p2);
    } else {
        printf("Division by zero is not allowed.\n");
    }
    return 0;
}