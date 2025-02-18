//Data Structure and Algorithms Practical 5B: Program to Covert String in Lowercase.
#include <stdio.h>
//#include <string.h>
int main() {
    int i;
    char str[100], strup[100],strlwr[100];
    printf("Enter a string(will be converted to lower): ");
    gets(str);
    for(i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            strlwr[i] = str[i] + 32;
        }
        else{
            strlwr[i] = str[i];
        }
    }
    strlwr[i] = '\0';
    for(i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            strup[i] = str[i] - 32;
        }
        else{
            strup[i] = str[i];
        }
    }
    strup[i] = '\0';
    printf("Original String: %s\n", str);
    printf("String in Uppercase: %s\n", strup);
    printf("String in Lowercase: %s\n", strlwr);
    return 0;
}