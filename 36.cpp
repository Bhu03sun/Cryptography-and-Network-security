#include <stdio.h>
#include <ctype.h>

// Function to calculate the modular multiplicative inverse
int modInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // Inverse does not exist
}

// Function to encrypt a single character using the affine Caesar cipher
char encryptChar(int a, int b, char plaintext) {
    if (isalpha(plaintext)) {
        char base = isupper(plaintext) ? 'A' : 'a';
        return (a * (plaintext - base) + b) % 26 + base;
    }
    return plaintext; // Non-alphabetic characters remain unchanged
}

// Function to encrypt a string using the affine Caesar cipher
void encryptAffineCaesar(int a, int b, const char *plaintext, char *ciphertext) {
    for (size_t i = 0; plaintext[i] != '\0'; ++i) {
        ciphertext[i] = encryptChar(a, b, plaintext[i]);
    }
}

int main() {
    int a = 5; // Choose an appropriate value for a (must be coprime with 26)
    int b = 8; // Choose any value for b

    const char *plaintext = "Hello, World!";
    char ciphertext[256];

    // Encrypt the plaintext
    encryptAffineCaesar(a, b, plaintext, ciphertext);

    // Display the results
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

