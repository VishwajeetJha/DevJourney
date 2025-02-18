#include <stdio.h>

int fact(int n);

int main(){
    int f,n;
    printf("Enter a value to find factorial: ");
    scanf("%d", &n);
    f = fact(n);
    printf("Factorial of %d is: %d",n,f);
}

int fact(int n){
    while(n!=0){
        return n*fact(n-1);
    }
    if(n==0){
        return 1;
    }
}