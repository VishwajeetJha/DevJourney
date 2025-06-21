//Practical 4: Implement Playfair Cipher
#include <stdio.h>
#include <string.h>

#define SIZE 5

void createPlayfairMatrix(char key[], char matrix[SIZE][SIZE]) {
    int used[26] = {0};
    char keyMatrix[26] = "";
    int i, j, k = 0, index = 0;

    for (i = 0; key[i] != '\0'; i++) {
        if (key[i] == 'J') key[i] = 'I';
        if (!used[key[i] - 'A']) {
            keyMatrix[index++] = key[i];
            used[key[i] - 'A'] = 1;
        }
    }

    for (i = 0; i < 26; i++) {
        if (i + 'A' == 'J') continue;
        if (!used[i]) {
            keyMatrix[index++] = i + 'A';
        }
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            matrix[i][j] = keyMatrix[k++];
        }
    }
}

void formatPlaintext(char text[], char formattedText[]) {
    int i, fIndex = 0, len = strlen(text);
    for (i = 0; i < len; i++) {
        if (text[i] == 'J') text[i] = 'I';
        formattedText[fIndex++] = text[i];

        if (i < len - 1 && text[i] == text[i + 1]) {
            formattedText[fIndex++] = 'X';
        } 
        if (fIndex % 2 == 1 && i == len - 1) {
            formattedText[fIndex++] = 'X';
        }
    }
    formattedText[fIndex] = '\0';
}

void findPosition(char matrix[SIZE][SIZE], char letter, int *row, int *col) {
    int i, j;
    if (letter == 'J') letter = 'I';

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (matrix[i][j] == letter) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encryptText(char formattedText[], char encryptedText[], char matrix[SIZE][SIZE]) {
    int i, row1, col1, row2, col2;

    for (i = 0; i < strlen(formattedText); i += 2) {
        findPosition(matrix, formattedText[i], &row1, &col1);
        findPosition(matrix, formattedText[i + 1], &row2, &col2);

        if (row1 == row2) {
            encryptedText[i] = matrix[row1][(col1 + 1) % SIZE];
            encryptedText[i + 1] = matrix[row2][(col2 + 1) % SIZE];
        } else if (col1 == col2) {
            encryptedText[i] = matrix[(row1 + 1) % SIZE][col1];
            encryptedText[i + 1] = matrix[(row2 + 1) % SIZE][col2];
        } else {
            encryptedText[i] = matrix[row1][col2];
            encryptedText[i + 1] = matrix[row2][col1];
        }
    }
    encryptedText[i] = '\0';
}

void decryptText(char encryptedText[], char decryptedText[], char matrix[SIZE][SIZE]) {
    int i, row1, col1, row2, col2;

    for (i = 0; i < strlen(encryptedText); i += 2) {
        findPosition(matrix, encryptedText[i], &row1, &col1);
        findPosition(matrix, encryptedText[i + 1], &row2, &col2);

        if (row1 == row2) {
            decryptedText[i] = matrix[row1][(col1 - 1 + SIZE) % SIZE];
            decryptedText[i + 1] = matrix[row2][(col2 - 1 + SIZE) % SIZE];
        } else if (col1 == col2) {
            decryptedText[i] = matrix[(row1 - 1 + SIZE) % SIZE][col1];
            decryptedText[i + 1] = matrix[(row2 - 1 + SIZE) % SIZE][col2];
        } else {
            decryptedText[i] = matrix[row1][col2];
            decryptedText[i + 1] = matrix[row2][col1];
        }
    }
    decryptedText[i] = '\0';
}

void removePadding(char decryptedText[], char cleanedText[]) {
    int i, j = 0;
    int len = strlen(decryptedText);

    for (i = 0; i < len; i++) {
        if (decryptedText[i] == 'X' && (i == len - 1 || decryptedText[i - 1] == decryptedText[i + 1])) {
            continue;
        }
        cleanedText[j++] = decryptedText[i];
    }
    cleanedText[j] = '\0';
}

int main() {
    char key[SIZE * SIZE] = "KEYWORD";
    char text[20] = "HELLOWORLD";
    char matrix[SIZE][SIZE];
    char formattedText[20], encryptedText[20], decryptedText[20], cleanedText[20];

    createPlayfairMatrix(key, matrix);
    formatPlaintext(text, formattedText);
    encryptText(formattedText, encryptedText, matrix);
    decryptText(encryptedText, decryptedText, matrix);
    removePadding(decryptedText, cleanedText);

    printf("Formatted Text: %s\n", formattedText);
    printf("Encrypted Text: %s\n", encryptedText);
    printf("Decrypted Text (with padding): %s\n", decryptedText);
    printf("Final Decrypted Text: %s\n", cleanedText);

    return 0;
}
