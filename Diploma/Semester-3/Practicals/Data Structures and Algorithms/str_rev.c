//Data Structure and Algorithms Practical: String Reverse
#include <stdio.h>
int main() {
    int len=0, cnt=0;
    char str[100],str2[100];
    printf("Enter a string: ");
    gets(str);
    while (str[len] != '\0'){
        len++;
    }
    printf("\nThe lenght of string is: %d\n",len);
    len--;
    while(len>=0){
        str2[cnt]=str[len];
        cnt++;
        len--;
    }
    str2[cnt] = '\0' ;
    printf("\n%s",str2);
    return 0;
}