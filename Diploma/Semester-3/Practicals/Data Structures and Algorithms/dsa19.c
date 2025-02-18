#include <stdio.h>

int a[50];

void sortBubble(int a[50], int N){
    int i,j,temp;

    for(i=0; i<N; i++){
        for(j=i+1; j<N; j++){
            if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    if(a[0]<a[1] && a[N-1]>a[N-2]){
        return ; 
    }
    else{
        sortBubble(a, N);
    }
}

// Main function
int main() {
    int i,N;

    printf("Enter size of array: ");
    scanf("%d", &N);

    printf("Enter elements of array: \n");
    for(i=0; i<N; i++){
        printf("--->");
        scanf("%d", &a[i]);
    }
    
    printf("Before sorting: ");
    for(i=0; i<N; i++){
        printf("%d ", a[i]);
    }

    sortBubble(a, N);

    printf("\nAfter sorting: ");
    for(i=0; i<N; i++){
        printf("%d ", a[i]);
    }
    
    return 0;
}