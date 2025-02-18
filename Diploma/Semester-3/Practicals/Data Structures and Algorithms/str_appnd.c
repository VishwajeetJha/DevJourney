//Data Structure and Algorithms Practical: String Append
#include <stdio.h>
int main() {
    int len=0, cnt=0;
    char str[100],str2[100],str3[100];
    printf("Enter a string 1: ");
    gets(str);
    printf("Your original string: %s\n", str);
    printf("Enter a string to append: ");
    gets(str2);
    while (str[len] != '\0'){
        len++;
    }
    while(cnt<len){
        str3[cnt]=str[cnt];
        cnt++;
    }
    len=0;
    while(str2[len] != '\0'){
        str3[cnt] = str2[len];
        cnt++;
        len++;
    }
    str3[cnt]='\0';
    printf("\nString 1 + String 2: %s",str3);
    return 0;
}