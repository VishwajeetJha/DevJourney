//Data Structure and Algorithms Practical 2: Row major and column major of a 2d array

#include <stdio.h>

int main()
{
    int i,j,a[3][3];

    printf("Enter values: ");

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }

    printf("\n");
    printf("Row Major: \n");
    
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("A[%d][%d] : %d \n" ,i,j,a[i][j]);
        }
    }
    
    printf("\n");
    printf("Column Major: \n");

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("A[%d][%d] : %d \n" ,j,i,a[j][i]);
        }
    }

    return 0;
}

//Time Complexity=O(n)