#include <stdio.h>

#define BLOCK_SIZE 64

// Function to perform left shift on a block
void leftShift(unsigned char *block, int size) {
    int i, carry = 0;

    for (i = 0; i < size; i++) {
        int nextCarry = (block[i] & 0x80) ? 1 : 0; // Check if the leftmost bit is 1
        block[i] = (block[i] << 1) | carry;
        carry = nextCarry;
    }
}

// Function to perform XOR with a constant
void xorWithConstant(unsigned char *block, int size, unsigned char constant) {
    block[size - 1] ^= constant;
}

// Function to generate CMAC subkeys
void generateCMACSubkeys(unsigned char *subkey1, unsigned char *subkey2) {
    // Step 1: Apply the block cipher to a block of 0 bits
    unsigned char zeroBlock[BLOCK_SIZE / 8] = {0}; // Initialize a block of 0 bits

    // Assuming you have a function named 'blockCipher' to apply the block cipher
    // blockCipher(zeroBlock, key, encryptedBlock);

    // Step 2: Left shift and XOR with constant for subkey1
    leftShift(zeroBlock, BLOCK_SIZE / 8);
    xorWithConstant(zeroBlock, BLOCK_SIZE / 8, 0x87); // Constant for a block size of 64 bits

    // Copy the result to subkey1
    for (int i = 0; i < BLOCK_SIZE / 8; i++) {
        subkey1[i] = zeroBlock[i];
    }

    // Step 3: Left shift and XOR with constant for subkey2
    leftShift(subkey1, BLOCK_SIZE / 8);
    if (subkey1[0] & 0x80) {
        xorWithConstant(subkey1, BLOCK_SIZE / 8, 0x1B); // Constant for a block size of 64 bits
    }

    // Copy the result to subkey2
    for (int i = 0; i < BLOCK_SIZE / 8; i++) {
        subkey2[i] = subkey1[i];
    }
}

int main() {
    unsigned char subkey1[BLOCK_SIZE / 8];
    unsigned char subkey2[BLOCK_SIZE / 8];

    generateCMACSubkeys(subkey1, subkey2);

    // Print the generated subkeys
    printf("Subkey 1: ");
    for (int i = 1; i < BLOCK_SIZE / 8; i++) {
        printf("%02x ", subkey1[i]);
    }
    printf("\n");

    printf("Subkey 2: ");
    for (int i = 1; i < BLOCK_SIZE / 8; i++) {
        printf("%02x ", subkey2[i]);
    }
    printf("\n");

    return 0;
}

