#include <stdio.h>

// Function prototypes
void encrypt_sdes_cbc(char *plaintext, char *key, char *iv, int length);
void decrypt_sdes_cbc(char *ciphertext, char *key, char *iv, int length);

void sdes_encrypt(char *block, char *key);
void sdes_decrypt(char *block, char *key);

int main() {
    char plaintext[] = "0000000100100011";  // Binary plaintext
    char key[] = "0111111101";               // Binary key
    char iv[] = "10101010";                  // Binary initialization vector

    int length = 16;  // Manually set the length

    // S-DES CBC Mode Encryption
    encrypt_sdes_cbc(plaintext, key, iv, length);
    
    // S-DES CBC Mode Decryption
    decrypt_sdes_cbc(plaintext, key, iv, length);

    return 0;
}

// S-DES Encryption
void sdes_encrypt(char *block, char *key) {
    // Implement S-DES encryption logic here
    // This function should modify the 'block' in-place
    // based on the provided 'key'
    // Replace the following comment with your S-DES encryption implementation
    // Example (not actual S-DES): block = block XOR key;
}

// S-DES Decryption
void sdes_decrypt(char *block, char *key) {
    // Implement S-DES decryption logic here
    // This function should modify the 'block' in-place
    // based on the provided 'key'
    // Replace the following comment with your S-DES decryption implementation
    // Example (not actual S-DES): block = block XOR key;
}

// CBC Mode Encryption
void encrypt_sdes_cbc(char *plaintext, char *key, char *iv, int length) {
    printf("\nS-DES CBC Encryption:\n");

    // Convert IV and plaintext to integers or use bitwise XOR directly
    // Perform encryption block by block using CBC mode
    for (int i = 0; i < length; i += 8) {
        for (int j = 0; j < 8; j++) {
            plaintext[i + j] = plaintext[i + j] ^ iv[j]; // XOR with IV
        }
        sdes_encrypt(plaintext + i, key);
        // IV for the next block becomes the ciphertext of the current block
        for (int j = 0; j < 8; j++) {
            iv[j] = plaintext[i + j];
        }
    }

    printf("Ciphertext: %s\n", plaintext);
}

// CBC Mode Decryption
void decrypt_sdes_cbc(char *ciphertext, char *key, char *iv, int length) {
    printf("\nS-DES CBC Decryption:\n");

    char prev_ciphertext[9];  // Store the ciphertext of the previous block

    // Convert IV and ciphertext to integers or use bitwise XOR directly
    // Perform decryption block by block using CBC mode
    for (int i = 0; i < length; i += 8) {
        for (int j = 0; j < 8; j++) {
            prev_ciphertext[j] = ciphertext[i + j];  // Store current ciphertext
        }
        sdes_decrypt(ciphertext + i, key);
        for (int j = 0; j < 8; j++) {
            ciphertext[i + j] = ciphertext[i + j] ^ iv[j]; // XOR with IV
        }
        // IV for the next block becomes the ciphertext of the current block
        for (int j = 0; j < 8; j++) {
            iv[j] = prev_ciphertext[j];
        }
    }

    printf("Decrypted Text: %s\n", ciphertext);
}



