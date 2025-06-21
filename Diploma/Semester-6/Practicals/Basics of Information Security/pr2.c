//Practical 2: Implement Caeser Cipher
#include <stdio.h>

int main(){
    int i = 0; //Loop pherwa mate
    char org[] = "helloworld"; //Our Original String :D
    int key=3; //Shift value

    printf("Original String: %s\n", org);

    //Ciphering
    while(org[i] != '\0'){
        org[i]+=key;
        i++;
    }
    printf("Ciphered String: %s\n", org);

    //Deciphering
    i=0;
    while(org[i] != '\0'){
        org[i]-=key;
        i++;
    }
    printf("Deciphered String: %s\n", org);
}

/*
Original String: Hello
Ciphered String: Khoor
Deciphered String: Hello
*/