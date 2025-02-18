//Data Structure and Algorithms Practical: String Compare
#include <stdio.h>
int main() {
    int len=0, len2=0, i=0;
    char str[100],str2[100];//,str3[100];
    printf("Enter a string 1: ");
    gets(str);
    printf("Enter a string 2: ");
    gets(str2);
    while (str[len] != '\0'){
        len++;
    }
    while (str2[len2] != '\0'){
        len2++;
    }
    if(len != len2){
        printf("\nStrings are NOT equal!\n");
        return 0;
    }
    while(i<len){
        if(str[i] != str2[i]){
            printf("\nStrings are NOT equal\n");
            return 0;
        }
        i++;
    }
    printf("\nStrings are equal!\n");
    return 0;
}