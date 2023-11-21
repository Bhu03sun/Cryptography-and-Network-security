#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MATRIX_SIZE 2

// Function to perform matrix multiplication for Hill cipher
void matrixMultiply(int key[MATRIX_SIZE][MATRIX_SIZE], int input[MATRIX_SIZE], int output[MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        output[i] = 0;
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            output[i] += key[i][j] * input[j];
        }
        output[i] %= 26; // Apply modular arithmetic (mod 26)
    }
}

// Function to encrypt a message using the Hill cipher
void hillEncrypt(int key[MATRIX_SIZE][MATRIX_SIZE], const char *plaintext, char *ciphertext) {
    int len = strlen(plaintext);

    // Adjust the length to be a multiple of MATRIX_SIZE
    int adjustedLen = len + (MATRIX_SIZE - len % MATRIX_SIZE) % MATRIX_SIZE;

    // Create a separate array for padded plaintext
    char paddedPlaintext[adjustedLen + 1];
    strcpy(paddedPlaintext, plaintext);

    for (int i = len; i < adjustedLen; ++i) {
        paddedPlaintext[i] = 'X'; // Padding with 'X'
    }

    for (int i = 0; i < adjustedLen; i += MATRIX_SIZE) {
        int input[MATRIX_SIZE];
        int output[MATRIX_SIZE];

        // Convert characters to numerical values (A=0, B=1, ..., Z=25)
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            input[j] = paddedPlaintext[i + j] - 'A';
        }

        // Perform matrix multiplication
        matrixMultiply(key, input, output);

        // Convert numerical values back to characters
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            ciphertext[i + j] = output[j] + 'A';
        }
    }

    // Null-terminate the ciphertext
    ciphertext[adjustedLen] = '\0';
}

int main() {
    int key[MATRIX_SIZE][MATRIX_SIZE] = {
        {9, 4},
        {5, 7}
    };

    char plaintext[] = "meet me at the usual place at ten rather than eight oclock";
    char ciphertext[1000];

    // Encryption
    hillEncrypt(key, plaintext, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}



