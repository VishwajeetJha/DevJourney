//Data Structure and Algorithms Practical 3: Linear Search
#include <stdio.h>

int main(){
    int N;
    printf("Enter size of array: ");
    scanf("%d", &N);
    int a[N];
    int x,i;
    printf("Enter elements of array:-\n");
    for(i=0;i<N; i++){
        printf("Enter element %d: ",i);
        scanf("%d", &a[i]);
    }
    printf("Enter element to find: ");
    scanf("%d", &x);
    for(i=0;i<N;i++){
        if(a[i]==x){
            printf("\nFound element at index: %d\n", i);
            return 0;
        }
        else{
            continue;
        }
    }
    printf("\nUnsuccessful search..!\n");
    return 0;        
}

//Time Complexity=O(n)