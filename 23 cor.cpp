#include <iostream>

// S-DES Functions
unsigned char permute(unsigned char value, const int* permutation, int size) {
    unsigned char result = 0;
    for (int i = 0; i < size; i++) {
        result <<= 1;
        result |= (value >> (permutation[i] - 1)) & 1;
    }
    return result;
}

unsigned char sbox(unsigned char value, int sboxIndex) {
    static const unsigned char sboxData[4][4] = {
        {0x1, 0x0, 0x3, 0x2},
        {0x3, 0x2, 0x1, 0x0},
        {0x0, 0x2, 0x1, 0x3},
        {0x3, 0x1, 0x3, 0x2}
    };
    unsigned char row = ((value & 0x1) << 1) | ((value & 0x8) >> 3);
    unsigned char col = (value & 0x6) >> 1;

    return sboxData[sboxIndex][row * 2 + col];
}

unsigned char feistel(unsigned char value, unsigned char subkey) {
    static const int expansionPermutation[] = { 4, 1, 2, 3, 2, 3, 4, 1 };
    static const int sboxPermutation[] = { 2, 4, 3, 1 };
    unsigned char expanded = permute(value, expansionPermutation, sizeof(expansionPermutation) / sizeof(int));
    unsigned char xored = expanded ^ subkey;
    unsigned char sboxResult = sbox(xored >> 4, 0) << 2 | sbox(xored & 0xF, 1);
    return permute(sboxResult, sboxPermutation, sizeof(sboxPermutation) / sizeof(int));
}

unsigned char generateSubkey(unsigned char key, int round) {
    static const int keyPermutation[] = { 9, 7, 3, 8, 0, 2, 6, 5 };
    unsigned char permutedKey = permute(key, keyPermutation, sizeof(keyPermutation) / sizeof(int));
    for (int i = 0; i < round; i++) {
        unsigned char msb = (permutedKey & 0x80) >> 7;
        permutedKey <<= 1;
        permutedKey |= msb;
    }
    return permutedKey;
}

// Counter Mode Functions
void encrypt(const unsigned char* plaintext, int plaintextLength, const unsigned char* key, unsigned char* ciphertext) {
    unsigned char counter = 0x0;
    unsigned char subkey;
    for (int i = 0; i < plaintextLength; i++) {
        subkey = generateSubkey(key[i], counter);
        ciphertext[i] = plaintext[i] ^ feistel(counter, subkey);
        counter++;
    }
}

void decrypt(const unsigned char* ciphertext, int ciphertextLength, const unsigned char* key, unsigned char* decryptedtext) {
    unsigned char counter = 0x0;
    unsigned char subkey;
    for (int i = 0; i < ciphertextLength; i++) {
        subkey = generateSubkey(key[i], counter);
        decryptedtext[i] = ciphertext[i] ^ feistel(counter, subkey);
        counter++;
    }
}

int main() {
    unsigned char plaintext[] = { 0x01, 0x02, 0x04 };
    unsigned char key[] = { 0x1F, 0x3D };
    unsigned char ciphertext[sizeof(plaintext)];
    unsigned char decryptedtext[sizeof(plaintext)];

    encrypt(plaintext, sizeof(plaintext), key, ciphertext);
    decrypt(ciphertext, sizeof(ciphertext), key, decryptedtext);

    std::cout << "Plaintext: ";
    for (int i = 0; i < sizeof(plaintext); i++) {
        std::cout << std::hex << (int)plaintext[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Ciphertext: ";
    for (int i = 0; i < sizeof(ciphertext); i++) {
        std::cout << std::hex << (int)ciphertext[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Decryptedtext: ";
    for (int i = 0; i < sizeof(decryptedtext); i++) {
        std::cout << std::hex << (int)decryptedtext[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
