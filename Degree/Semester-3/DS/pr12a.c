/*Practical 12: A. Write a program in C to find string length using the above algorithm.
                B. Write a program in C to concat two strings
                C. Write a program in C to copy one string into another string.
                D. Write a program in C to compare the two given strings*/
#include <stdio.h>

//D. Function to compare two strings
void stringCmp(char s1[], char s2[]) {
    int i = 0, res;
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            res = s1[i] - s2[i];  // difference
        i++;
    }
    res = s1[i] - s2[i];  // handles unequal lengths

    if (res == 0) {
        printf("The strings \"%s\" and \"%s\" are equal.\n", s1, s2);
    } else if (res < 0) {
        printf("The string \"%s\" is less than \"%s\".\n", s1, s2);
    } else {
        printf("The string \"%s\" is greater than \"%s\".\n", s1, s2);
    }
}

void main(){
    //A. Find string length
    char str[] = "Hello, World!";
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    printf("A. The length of the string \"%s\" is: %d\n", str, length);

    //B. Concatenate two strings
    char str1[50] = "Hello, ";
    char str2[] = "World!";
    int i = 0, j = 0;

    printf("First string: \"%s\"\n", str1);
    printf("Second string: \"%s\"\n", str2);

    while (str1[i] != '\0') {
        i++;
    }

    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0'; //terminating
    printf("B. Concatenated string: \"%s\"\n", str1);

    //C. Copy one string into another
    char s1[] = "Hello, World!";
    char s2[50];
    i = 0;
    while (s1[i] != '\0') {
        s2[i] = s1[i];
        i++;
    }
    s2[i] = '\0'; // terminating
    printf("C. Copied string: \"%s\"\n", s2);

    //D. Compare two strings
    printf("D. ");
    stringCmp(str1, str);
}

/*OUTPUT:-
A. The length of the string "Hello, World!" is: 13
First string: "Hello, "
Second string: "World!"
B. Concatenated string: "Hello, World!"
C. Copied string: "Hello, World!"
D. The strings "Hello, World!" and "Hello, World!" are equal.*/