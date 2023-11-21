#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define ALPHABET_SIZE 26

// Function to generate the cipher sequence from a keyword
void generateCipherSequence(const char *keyword, char *cipherSequence) {
    int keywordLength = strlen(keyword);

    // Copy the keyword to the beginning of the cipher sequence
    strcpy(cipherSequence, keyword);

    // Mark used letters in the keyword
    int used[ALPHABET_SIZE] = {0};
    for (int i = 0; i < keywordLength; ++i) {
        char ch = toupper(keyword[i]);
        if (isalpha(ch)) {
            used[ch - 'A'] = 1;
        }
    }

    // Fill in the unused letters in normal order
    for (int i = 0, j = 'A'; i < ALPHABET_SIZE; ++i, ++j) {
        if (!used[i]) {
            cipherSequence[keywordLength++] = j;
        }
    }

    // Null-terminate the cipher sequence
    cipherSequence[keywordLength] = '\0';
}

// Function to perform monoalphabetic substitution
void monoalphabeticEncrypt(const char *plaintext, const char *cipherSequence, char *ciphertext) {
    for (size_t i = 0; i < strlen(plaintext); ++i) {
        if (isalpha(plaintext[i])) {
            char ch = toupper(plaintext[i]);
            ciphertext[i] = isupper(plaintext[i]) ? cipherSequence[ch - 'A'] : tolower(cipherSequence[ch - 'A']);
        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    // Null-terminate the ciphertext
    ciphertext[strlen(plaintext)] = '\0';
}

int main() {
    const char *keyword = "CIPHER";
    char cipherSequence[ALPHABET_SIZE + 1];
    char plaintext[1000];
    char ciphertext[1000];

    generateCipherSequence(keyword, cipherSequence);

    printf("Keyword: %s\n", keyword);
    printf("Cipher Sequence: %s\n", cipherSequence);

    printf("Enter plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // Remove the newline character from the input
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n') {
        plaintext[len - 1] = '\0';
    }

    monoalphabeticEncrypt(plaintext, cipherSequence, ciphertext);

    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}

