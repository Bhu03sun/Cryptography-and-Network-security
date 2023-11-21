#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MATRIX_SIZE 5

// Function to find the coordinates of a character in the Playfair matrix
void findCoordinates(char playfairMatrix[MATRIX_SIZE][MATRIX_SIZE], char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I'; // Replace 'J' with 'I' for simplicity

    for (*row = 0; *row < MATRIX_SIZE; ++(*row)) {
        for (*col = 0; *col < MATRIX_SIZE; ++(*col)) {
            if (playfairMatrix[*row][*col] == ch) {
                return;
            }
        }
    }
}

// Function to encrypt a message using the Playfair matrix
void playfairEncrypt(char playfairMatrix[MATRIX_SIZE][MATRIX_SIZE], const char *plaintext, char *ciphertext) {
    int len = strlen(plaintext);
    int row1, col1, row2, col2;

    for (int i = 0; i < len; i += 2) {
        // Find coordinates of the current pair of characters
        findCoordinates(playfairMatrix, plaintext[i], &row1, &col1);
        findCoordinates(playfairMatrix, plaintext[i + 1], &row2, &col2);

        // Same row, replace with characters to the right (circular)
        if (row1 == row2) {
            ciphertext[i] = playfairMatrix[row1][(col1 + 1) % MATRIX_SIZE];
            ciphertext[i + 1] = playfairMatrix[row2][(col2 + 1) % MATRIX_SIZE];
        }
        // Same column, replace with characters below (circular)
        else if (col1 == col2) {
            ciphertext[i] = playfairMatrix[(row1 + 1) % MATRIX_SIZE][col1];
            ciphertext[i + 1] = playfairMatrix[(row2 + 1) % MATRIX_SIZE][col2];
        }
        // Different rows and columns, form a rectangle and replace
        else {
            ciphertext[i] = playfairMatrix[row1][col2];
            ciphertext[i + 1] = playfairMatrix[row2][col1];
        }
    }

    // Null-terminate the ciphertext
    ciphertext[len] = '\0';
}

int main() {
    char playfairMatrix[MATRIX_SIZE][MATRIX_SIZE] = {
        {'M', 'F', 'H', 'I', 'K'},
        {'U', 'N', 'O', 'P', 'Q'},
        {'Z', 'V', 'W', 'X', 'Y'},
        {'E', 'L', 'A', 'R', 'G'},
        {'D', 'S', 'T', 'B', 'C'}
    };

    char plaintext[] = "Must.";
    char ciphertext[1000];

    playfairEncrypt(playfairMatrix, plaintext, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}


