#include <stdio.h>
int main() {
    char str1[100], str2[100], str3[200];
    int i, j;
    printf("Enter the First string: ");
    gets(str1);
    printf("Enter the Second string: ");
    gets(str2);
    for (i = 0; str1[i] != '\0'; i++) {
        str3[i] = str1[i];
    }
    for (j = 0; str2[j] != '\0'; j++) {
        str3[i + j] = str2[j];
    }
    str3[i + j] = '\0';
    printf("Concatenated String: %s\n", str3);
    return 0;
}