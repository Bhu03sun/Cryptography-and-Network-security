#include <stdio.h>
#include <string.h>

void encrypt(char *plaintext, char *key) {
    int plaintextLen = strlen(plaintext);
    int keyLen = strlen(key);

    char ciphertext[plaintextLen + 1];
    ciphertext[plaintextLen] = '\0';

    for (int i = 0; i < plaintextLen; i++) {
        int shift = key[i % keyLen] - 'A';

        ciphertext[i] = (plaintext[i] - 'A' + shift) % 26 + 'A';
    }

    printf("Encrypted message: %s\n", ciphertext);
}

void decrypt(char *ciphertext, char *key) {
    int ciphertextLen = strlen(ciphertext);
    int keyLen = strlen(key);

    char plaintext[ciphertextLen + 1];
    plaintext[ciphertextLen] = '\0';

    for (int i = 0; i < ciphertextLen; i++) {
        int shift = key[i % keyLen] - 'A';

        plaintext[i] = (ciphertext[i] - 'A' - shift + 26) % 26 + 'A';
    }

    printf("Decrypted message: %s\n", plaintext);
}

int main() {
    char plaintext[100];
    char key[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    plaintext[strcspn(plaintext, "\n")] = 0;

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    key[strcspn(key, "\n")] = 0;

    encrypt(plaintext, key);

    decrypt(plaintext, key);

    return 0;
}
