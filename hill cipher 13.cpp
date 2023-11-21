#include <stdio.h>

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

void encrypt(int key[2][2], int plaintext[2], int ciphertext[2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ciphertext[i] += key[i][j] * plaintext[j];
        }
        ciphertext[i] = ciphertext[i] % 26;
    }
}

void decrypt(int key[2][2], int ciphertext[2], int plaintext[2]) {
    int inverse = modInverse(key[0][0] * key[1][1] - key[0][1] * key[1][0], 26);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            plaintext[i] += inverse * (key[(i + 1) % 2][(j + 1) % 2] * ciphertext[j]);
        }
        plaintext[i] = (plaintext[i] % 26 + 26) % 26;
    }
}

int main() {
    int key[2][2] = {{6, 9}, {4, 17}};
    int plaintext[2] = {1, 3};
    int ciphertext[2] = {0, 0};
    int decrypted[2] = {0, 0};

    encrypt(key, plaintext, ciphertext);
    printf("Ciphertext: %c%c\n", 'A' + ciphertext[0], 'A' + ciphertext[1]);

    decrypt(key, ciphertext, decrypted);
    printf("Decrypted: %c%c\n", 'A' + decrypted[0], 'A' + decrypted[1]);

    return 0;
}
