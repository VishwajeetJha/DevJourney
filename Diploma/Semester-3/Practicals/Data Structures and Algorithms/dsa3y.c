//Data Structure and Algorithms Practical 3: Linear Search

#include <stdio.h>

int main(){
    int N;

    printf("Enter size of array: ");
    scanf("%d", &N);

    int a[N];
    int x,i;

    printf("Enter elements of array: ");
    for(i=0;i<N; i++){
        scanf("%d", &a[i]);
    }

    printf("Enter Number to find its Index in your given Array: ");
    scanf("%d", &x);

    i=0;
    while(i<N){
        if(a[i]==x){
            printf("\nFound element at Index: %d\n", i);
            return 0;
        }
        i++;
    }
    printf("\nUnsuccessful search..!\n");
    return 0;
}

//Time Complexity=O(n)