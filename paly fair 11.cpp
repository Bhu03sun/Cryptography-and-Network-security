#include <stdio.h>

unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int n = 25; // Number of unique letters in the Playfair cipher (excluding 'J' or 'Q')
    unsigned long long totalKeys = factorial(n);

    printf("Total number of possible keys: %llu\n", totalKeys);

    return 0;
}

