//Data Structure and Algorithms Practical 5A: Program to Find length of String.
#include <stdio.h>
//#include <string.h>
int main() {
    int i=0;
    char str[100];
    printf("Enter a string: ");
    gets(str);
    while (str[i] != '\0'){
        
        i=i+1;
    }
    printf("Length of the string: %d\n", i);
    return 0;
}