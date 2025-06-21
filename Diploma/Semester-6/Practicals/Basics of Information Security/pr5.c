//Practical 5: Implement Railfence cipher
#include <stdio.h>
#include <string.h>

void encryptRailFence(char msg[], int key, char encrMsg[]) {
    int col = strlen(msg);
    char rail[key][col];

    memset(rail, '\n', sizeof(rail));

    int row = 0, direction = 1;

    for (int i = 0; i < col; i++) {
        rail[row][i] = msg[i];

        row += direction;

        if (row == key - 1) direction = -1;
        else if (row == 0) direction = 1;
    }

    int k = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < col; j++) {
            if (rail[i][j] != '\n') {
                encrMsg[k++] = rail[i][j];
            }
        }
    }
    encrMsg[k] = '\0';
}

void decryptRailFence(char encrMsg[], int key, char decrMsg[]) {
    int col = strlen(encrMsg);
    char rail[key][col];

    memset(rail, '\n', sizeof(rail));

    int row = 0, direction = 1;
    for (int i = 0; i < col; i++) {
        rail[row][i] = '*';

        row += direction;

        if (row == key - 1) direction = -1;
        else if (row == 0) direction = 1;
    }

    int k = 0;
    for (int i = 0; i < key; i++) {
        for (int j = 0; j < col; j++) {
            if (rail[i][j] == '*' && k < col) {
                rail[i][j] = encrMsg[k++];
            }
        }
    }

    row = 0, direction = 1;
    for (int i = 0; i < col; i++) {
        decrMsg[i] = rail[row][i];

        row += direction;

        if (row == key - 1) direction = -1;
        else if (row == 0) direction = 1;
        
    }
    decrMsg[col] = '\0';
}

int main() {
    char msg[] = "INFORMATIONSECURITY";
    int key = 3;

    char encrMsg[100], decrMsg[100];

    encryptRailFence(msg, key, encrMsg);
    decryptRailFence(encrMsg, key, decrMsg);

    printf("Original Message: %s\n", msg);
    printf("Encrypted Message: %s\n", encrMsg);
    printf("Decrypted Message: %s\n", decrMsg);

    return 0;
}