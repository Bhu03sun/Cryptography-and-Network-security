#include <stdio.h>
#include <string.h>

// Function prototypes
void encrypt_ecb(char *plaintext, char *key, int length);
void decrypt_ecb(char *ciphertext, char *key, int length);

int main() {
    char plaintext[] = "HELLOWOR";
    char key[] = "KEY12345";
    int length = strlen(plaintext);

    // ECB Mode
    encrypt_ecb(plaintext, key, length);
    decrypt_ecb(plaintext, key, length);

    return 0;
}

// ECB Mode Encryption
void encrypt_ecb(char *plaintext, char *key, int length) {
    printf("\nECB Encryption:\n");

    for (int i = 0; i < length; i++) {
        plaintext[i] = plaintext[i] ^ key[i % strlen(key)];
    }

    printf("Ciphertext: ");
    for (int i = 0; i < length; i++) {
        printf("%02x", plaintext[i]);
    }
    printf("\n");
}

// ECB Mode Decryption
void decrypt_ecb(char *ciphertext, char *key, int length) {
    printf("\nECB Decryption:\n");

    for (int i = 0; i < length; i++) {
        ciphertext[i] = ciphertext[i] ^ key[i % strlen(key)];
    }

    printf("Decrypted Text: %s\n", ciphertext);
}

