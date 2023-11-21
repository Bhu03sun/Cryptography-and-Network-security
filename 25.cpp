#include <stdio.h>

// Function to calculate the greatest common divisor (GCD) using Euclid's algorithm
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to factorize n given a non-trivial factor
void factorize(int n, int factor) {
    int p = factor;
    int q = n / factor;

    printf("Factorization of n: p = %d, q = %d\n", p, q);
}

int main() {
    // Assume n = pq, where p and q are large prime numbers
    int p = 60;
    int q = 53;
    int n = p * q;

    // Assume e is the public key
    int e = 17;

    // Assume we have a ciphertext block that has a common factor with n
    int ciphertext = 123;

    // Check if the gcd(ciphertext, n) is not 1
    if (gcd(ciphertext, n) != 1) {
        printf("The ciphertext has a common factor with n.\n");

        // Factorize n using the non-trivial factor
        factorize(n, gcd(ciphertext, n));
    } else {
        printf("The ciphertext does not have a common factor with n.\n");
    }

    return 0;
}

