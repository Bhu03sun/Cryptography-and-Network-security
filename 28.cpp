#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate modular exponentiation
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

// Diffie-Hellman key exchange function
int diffieHellman(int a, int q, int x) {
    return modExp(a, x, q);
}

int main() {
    // Public parameters (can be chosen publicly)
    int a = 5;   // Generator
    int q = 21;  // Prime modulus

    // Alice's secret key
    int aliceSecret = 6;

    // Bob's secret key
    int bobSecret = 8;

    // Calculate public values
    int alicePublic = diffieHellman(a, q, aliceSecret);
    int bobPublic = diffieHellman(a, q, bobSecret);

    // Exchange public values
    // In a real scenario, these values would be exchanged securely
    int sharedSecretAlice = diffieHellman(bobPublic, q, aliceSecret);
    int sharedSecretBob = diffieHellman(alicePublic, q, bobSecret);

    // Display shared secrets
    printf("Shared Secret (Alice): %d\n", sharedSecretAlice);
    printf("Shared Secret (Bob): %d\n", sharedSecretBob);

    return 0;
}

