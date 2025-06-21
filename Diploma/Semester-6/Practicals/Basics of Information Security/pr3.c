//Practical 3: Implement Hill Cipher
#include <stdio.h>

int main(){
    char msg[] = "ACT";
    int msgMat[3];

    //Making matrix of the message; subtracting ascii value of 'A' to ensure enumeration begins from 0 for A and vice versa
    for(int i=0; i<3; i++){
        msgMat[i] = msg[i] - 'A';
    }
    
    char c;
    int key[3][3] = {{6,24, 1}, 
                    {13,16, 10},
                    {20, 17, 15}};

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", key[i][j]);
        }
        printf("\n");
    }

    int product[3] = {0, 0, 0};

    //Encrypting; Multiplying 3x3 Mat(Key) to 1x3 Mat(Message Vector) and then Moduling with 26 to get enumerated values; A=0 etc
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            product[i] +=  key[i][j] * msgMat[j];
        }
        product[i] %= 26;
    }

    //To print, we simply have to add ascii value of 'A' again :)
    printf("Encrypted Message: \n");
    for(int i=0; i<3; i++){
        printf("%c", product[i] + 'A');
    }

    return 0;
}