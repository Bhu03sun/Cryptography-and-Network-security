#include <stdio.h>
#include <string.h>

typedef unsigned char byte;

// Function to perform 3DES encryption in CBC mode
void encrypt3DES_CBC(const byte *plaintext, const byte *key, const byte *iv, byte *ciphertext) {
    // Encrypt the plaintext using 3DES in CBC mode
    // You need to implement the 3DES algorithm here

    // For simplicity, let's just copy plaintext to ciphertext (replace this with actual 3DES encryption)
    memcpy(ciphertext, plaintext, 8);
}

int main() {
    const byte plaintext[] = "Hello123"; // Replace with your plaintext
    const byte key[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF, 0x01, 0x23, 0x45, 0x67, 0x89, 0xAB, 0xCD, 0xEF}; // 3DES key (24 bytes)
    const byte iv[] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xAB, 0xCD, 0xEF}; // Initialization Vector (IV) (8 bytes)

    byte ciphertext[64]; // Output buffer

    // Encrypt in CBC mode using 3DES
    encrypt3DES_CBC(plaintext, key, iv, ciphertext);

    // Display the ciphertext
    printf("Ciphertext: ");
    for (int i = 0; i < 64; ++i) {
        printf("%02X", (unsigned char)ciphertext[i]);
    }
    printf("\n");

    return 0;
}

