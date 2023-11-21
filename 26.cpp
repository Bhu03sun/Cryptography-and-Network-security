#include <stdio.h>

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

// Function to generate a new public key (e, n) and private key (d, n)
void generateNewKeys(int *e, int *d, int *n) {
    // Choose new prime numbers p and q (in practice, use a secure random number generator)
    int p = 60;
    int q = 53;

    // Calculate n and phi(n)
    *n = p * q;
    int phi_n = (p - 1) * (q - 1);

    // Choose a new public exponent e (in practice, choose a suitable value)
    *e = 17;

    // Calculate the private key d
    *d = modInverse(*e, phi_n);
}

int main() {
    int original_e = 17;
    int original_d = 2853; // Example leaked private key
    int original_n = 3233; // Example modulus

    // Output original public and private keys
    printf("Original Public Key: (e=%d, n=%d)\n", original_e, original_n);
    printf("Original Private Key: (d=%d, n=%d)\n", original_d, original_n);

    // Generate new public and private keys after a private key leak
    int new_e, new_d, new_n;
    generateNewKeys(&new_e, &new_d, &new_n);

    // Output new public and private keys
    printf("\nNew Public Key: (e=%d, n=%d)\n", new_e, new_n);
    printf("New Private Key: (d=%d, n=%d)\n", new_d, new_n);

    return 0;
}

