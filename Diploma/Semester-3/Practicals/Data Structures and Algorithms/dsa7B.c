#include <stdio.h>

int hcf(int x,int y);

int main(){
    int a,b,h;
    printf("Enter values to find HCF:-\nA: ");
    scanf("%d", &a);
    printf("B: ");
    scanf("%d", &b);
    h = hcf(a,b);
    printf("Highest Common Factor of %d and %d is: %d",a,b,h);
}

int hcf(int x,int y){
    while(x!=y){
        if(x>y){
            return hcf(x-y,y);
        }
        else{
            return hcf(x,y-x);
        }
    }
    return x;
}