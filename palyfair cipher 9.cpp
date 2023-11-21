#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define KEY_SIZE 5
#define ALPHABET_SIZE 26

// Function to find the coordinates of a character in the key square
void findCoordinates(char keySquare[KEY_SIZE][KEY_SIZE], char ch, int *row, int *col) {
    if (ch == 'J') ch = 'I'; // Replace 'J' with 'I' for simplicity

    for (*row = 0; *row < KEY_SIZE; ++(*row)) {
        for (*col = 0; *col < KEY_SIZE; ++(*col)) {
            if (keySquare[*row][*col] == ch) {
                return;
            }
        }
    }
}

// Function to decrypt a Playfair-encoded message
void playfairDecrypt(char keySquare[KEY_SIZE][KEY_SIZE], const char *ciphertext, char *plaintext) {
    int len = strlen(ciphertext);
    int row1, col1, row2, col2;

    for (int i = 0; i < len; i += 2) {
        // Find coordinates of the current pair of characters
        findCoordinates(keySquare, ciphertext[i], &row1, &col1);
        findCoordinates(keySquare, ciphertext[i + 1], &row2, &col2);

        // Same row, replace with characters to the left
        if (row1 == row2) {
            plaintext[i] = keySquare[row1][(col1 - 1 + KEY_SIZE) % KEY_SIZE];
            plaintext[i + 1] = keySquare[row2][(col2 - 1 + KEY_SIZE) % KEY_SIZE];
        }
        // Same column, replace with characters above
        else if (col1 == col2) {
            plaintext[i] = keySquare[(row1 - 1 + KEY_SIZE) % KEY_SIZE][col1];
            plaintext[i + 1] = keySquare[(row2 - 1 + KEY_SIZE) % KEY_SIZE][col2];
        }
        // Different rows and columns, form a rectangle and replace
        else {
            plaintext[i] = keySquare[row1][col2];
            plaintext[i + 1] = keySquare[row2][col1];
        }
    }

    // Null-terminate the plaintext
    plaintext[len] = '\0';
}

int main() {
    char keySquare[KEY_SIZE][KEY_SIZE] = {
        {'K', 'E', 'Y', 'W', 'O'},
        {'R', 'D', 'A', 'B', 'C'},
        {'F', 'G', 'H', 'I', 'L'},
        {'M', 'N', 'P', 'Q', 'S'},
        {'T', 'U', 'V', 'X', 'Z'}
    };

    char ciphertext[] = "KXJEYUREBEZWEHEWRYTUHEYFSKREHEGOYFIWTTTUOLKSYCAJPOBOTEIZONTXBYBNTGONEYCUZWRGDSONSXBOUYWRHEBAAHYUSEDQ";
    char plaintext[1000];

    playfairDecrypt(keySquare, ciphertext, plaintext);

    printf("Ciphertext: %s\n", ciphertext);
    printf("Plaintext: %s\n", plaintext);

    return 0;
}

