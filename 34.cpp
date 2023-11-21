#include <stdio.h>
#include <stdint.h>

// AES constants
#define AES_BLOCK_SIZE 16

// AES S-box
static const uint8_t sbox[256] = {
    // ... (omitted for brevity)
};

// AES encryption round keys
static const uint8_t roundKeys[11][4][4] = {
    // ... (omitted for brevity)
};

// AES encryption function
void aes_encrypt_block(const uint8_t *input, const uint8_t *key, uint8_t *output) {
    // Initial round key addition
    // ... (omitted for brevity)

    // Main rounds
    // ... (omitted for brevity)

    // Final round (no MixColumns)
    // ... (omitted for brevity)
}

// ECB mode encryption
void ecb_encrypt(const uint8_t *plaintext, size_t size, const uint8_t *key, uint8_t *ciphertext) {
    for (size_t i = 0; i < size; i += AES_BLOCK_SIZE) {
        aes_encrypt_block(plaintext + i, key, ciphertext + i);
    }
}

int main() {
    const uint8_t plaintext[] = "This is a sample message";
    const uint8_t key[] = "0123456789abcdef";
    uint8_t ciphertext[128];

    // ECB Mode Encryption
    ecb_encrypt(plaintext, sizeof(plaintext) - 1, key, ciphertext);

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for (size_t i = 0; i < sizeof(plaintext) - 1; ++i) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    return 0;
}

