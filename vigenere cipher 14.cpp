#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt a message using the one-time pad Vigenère cipher
void encryptVigenereOneTimePad(const char *plaintext, const int *keyStream, char *ciphertext) {
    int len = strlen(plaintext);
    for (int i = 0; i < len; ++i) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = (plaintext[i] - base + keyStream[i]) % 26 + base;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[len] = '\0';
}

// Function to decrypt a message using the one-time pad Vigenère cipher
void decryptVigenereOneTimePad(const char *ciphertext, const int *keyStream, char *plaintext) {
    int len = strlen(ciphertext);
    for (int i = 0; i < len; ++i) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            plaintext[i] = (ciphertext[i] - base - keyStream[i] + 26) % 26 + base;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[len] = '\0';
}

int main() {
    // Part (a): Encrypt the plaintext "sendmoremoney" with the given key stream
    const char *plaintextA = "sendmoremoney";
    int keyStreamA[] = {9, 0, 1, 7, 23, 15, 21, 14, 11, 11, 2, 8, 9};
    char ciphertextA[100];

    encryptVigenereOneTimePad(plaintextA, keyStreamA, ciphertextA);

    printf("Part (a):\n");
    printf("Plaintext: %s\n", plaintextA);
    printf("Key Stream: ");
    for (int i = 0; i < strlen(plaintextA); ++i) {
        printf("%d ", keyStreamA[i]);
    }
    printf("\n");
    printf("Ciphertext: %s\n\n", ciphertextA);

    // Part (b): Decrypt the ciphertext from part (a) to the plaintext "cashnotneeded"
    const char *ciphertextB = "vjyjbvcbiymqqjjhr";
    char plaintextB[100];

    // Find the key stream for decryption
    int keyStreamB[100];
    for (int i = 0; i < strlen(ciphertextB); ++i) {
        keyStreamB[i] = (ciphertextB[i] - ciphertextA[i] + 26) % 26;
    }

    decryptVigenereOneTimePad(ciphertextB, keyStreamB, plaintextB);

    printf("Part (b):\n");
    printf("Ciphertext: %s\n", ciphertextB);
    printf("Key Stream for Decryption: ");
    for (int i = 0; i < strlen(ciphertextB); ++i) {
        printf("%d ", keyStreamB[i]);
    }
    printf("\n");
    printf("Decrypted Plaintext: %s\n", plaintextB);

    return 0;
}




