
#include <iostream>
#include <cctype>
#include <cstring>

#define ALPHABET_SIZE 26

void monoalphabetic_substitution(char *plaintext, char *ciphertext, char *key) {
    while (*plaintext != '\0') {
        if (std::isalpha(*plaintext)) {
            char original = std::isupper(*plaintext) ? 'A' : 'a';
            *ciphertext = key[*plaintext - original];
        } else {
            *ciphertext = *plaintext;
        }

        plaintext++;
        ciphertext++;
    }

    *ciphertext = '\0'; // Null-terminate the ciphertext string
}

int main() {
    char plaintext[1000];
    char ciphertext[1000];
    char KEY[ALPHABET_SIZE] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};

    std::cout << "Enter the plaintext: ";
    std::cin.getline(plaintext, sizeof(plaintext));

    // Perform monoalphabetic substitution
    monoalphabetic_substitution(plaintext, ciphertext, KEY);

    // Display the results
    std::cout << "Plaintext: " << plaintext << std::endl;
    std::cout << "Ciphertext: " << ciphertext << std::endl;

    return 0;
}

