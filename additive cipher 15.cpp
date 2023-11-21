#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to calculate letter frequencies in a string
void calculateFrequencies(const char *text, int frequencies[ALPHABET_SIZE]) {
    for (size_t i = 0; i < strlen(text); ++i) {
        if (isalpha(text[i])) {
            char ch = tolower(text[i]);
            frequencies[ch - 'a']++;
        }
    }
}

// Function to decrypt a message using a given shift value
void decryptWithShift(const char *ciphertext, int shift, char *plaintext) {
    size_t length = strlen(ciphertext);
    for (size_t i = 0; i < length; ++i) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            plaintext[i] = (ciphertext[i] - shift - base + 26) % 26 + base;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[length] = '\0';
}

// Function to perform a letter frequency attack
void letterFrequencyAttack(const char *ciphertext, int topN) {
    int frequencies[ALPHABET_SIZE] = {0};
    calculateFrequencies(ciphertext, frequencies);

    printf("Letter Frequencies in Ciphertext:\n");
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        printf("%c: %d\n", 'a' + i, frequencies[i]);
    }

    // Find the most likely shift values
    int mostLikelyShifts[topN];
    for (int n = 0; n < topN; ++n) {
        int maxIndex = 0;
        for (int i = 1; i < ALPHABET_SIZE; ++i) {
            if (frequencies[i] > frequencies[maxIndex]) {
                maxIndex = i;
            }
        }
        mostLikelyShifts[n] = (maxIndex + 'a' - 'e' + ALPHABET_SIZE) % ALPHABET_SIZE;
        frequencies[maxIndex] = 0; // Mark the maximum frequency as processed
    }

    printf("\nTop %d Possible Plaintexts:\n", topN);
    for (int n = 0; n < topN; ++n) {
        char plaintext[1000];
        decryptWithShift(ciphertext, mostLikelyShifts[n], plaintext);
        printf("Shift %d: %s\n", mostLikelyShifts[n], plaintext);
    }
}

int main() {
    // Example ciphertext
    const char *ciphertext = "LXFOPVEFRNHR";

    // Perform letter frequency attack and print top 5 possible plaintexts
    letterFrequencyAttack(ciphertext, 5);

    return 0;
}

