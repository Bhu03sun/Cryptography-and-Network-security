#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate the greatest common divisor (GCD) using Euclid's algorithm
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to calculate the multiplicative inverse using the extended Euclidean algorithm
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;

        t = m;
        m = a % m;
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to calculate modular exponentiation (to handle large numbers)
int modExp(int base, int exponent, int modulus) {
    int result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;

        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }

    return result;
}

int main() {
    // Assume Bob's public key (e, n)
    int e = 65537;  // Commonly used value for e
    int n = 309485009;  // A large modulus (product of two large primes)

    // Message to be encrypted (each character represented as an integer between 0 and 25)
    int plaintext[] = {3, 2, 11, 18, 4};

    // Encrypt each character separately
    int ciphertext[5];
    for (int i = 0; i < 5; ++i) {
        ciphertext[i] = modExp(plaintext[i], e, n);
    }

    // Display the encrypted message
    printf("Encrypted Message: ");
    for (int i = 0; i < 5; ++i) {
        printf("%d ", ciphertext[i]);
    }
    printf("\n");

    return 0;
}

