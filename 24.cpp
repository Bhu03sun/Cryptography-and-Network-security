#include <stdio.h>

// Function to find the greatest common divisor (GCD)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find the multiplicative inverse using the extended Euclidean algorithm
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

int main() {
    int e = 31;
    int n = 3599;

    // Trial-and-error to find p and q (you might want a more sophisticated method in practice)
    int p = 61;
    int q = 59;

    int phi_n = (p - 1) * (q - 1);

    // Check if e and phi_n are coprime
    if (gcd(e, phi_n) != 1) {
        printf("Invalid choice of e. Choose a different value.\n");
        return 1;
    }

    // Calculate the private key d using the extended Euclidean algorithm
    int d = modInverse(e, phi_n);

    printf("Public key: (e=%d, n=%d)\n", e, n);
    printf("Private key: (d=%d, n=%d)\n", d, n);

    return 0;
}

