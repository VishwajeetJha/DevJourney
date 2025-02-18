//Data Structure and Algorithms Practical: String Copy
#include <stdio.h>
int main() {
    int len=0, cnt=0;
    char str[100],str2[100];
    printf("Enter a string: ");
    gets(str);
    while (str[len] != '\0'){
        str2[len]=str[len];
        len++;
    }
    str2[len]='\0';
    printf("\nCopied String: %s",str2);
    return 0;
}