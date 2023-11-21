#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

void decryptSubstitution(char* ciphertext, char* substitutions) {
    for (int i = 0; ciphertext[i] != '\0'; ++i) {
        char current = ciphertext[i];

        // Check if the character is in the substitutions list
        char* replaced = strchr(substitutions, current);

        // If found, print the replacement; otherwise, print the original character
        if (replaced != NULL) {
            printf("%c", *replaced);
        } else {
            printf("%c", current);
        }
    }
}

int main() {
    char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 (88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8* ;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?";

    char substitutions[MAX_LENGTH] = "";

    while (1) {
        printf("Decrypted Message: ");
        decryptSubstitution(ciphertext, substitutions);
        printf("\nEnter a substitution (format: original=new) or 'exit' to finish:\n");
        
        char substitutionInput[MAX_LENGTH];
        fgets(substitutionInput, sizeof(substitutionInput), stdin);

        // Remove newline character from input
        substitutionInput[strcspn(substitutionInput, "\n")] = '\0';

        if (strcmp(substitutionInput, "exit") == 0) {
            break;
        }

        // Validate input format
        char *token = strtok(substitutionInput, "=");
        if (token == NULL) {
            printf("Invalid input. Please use the format 'original=new'.\n");
            continue;
        }

        // Update substitutions list
        char original = token[0];
        char newChar = token[2];
        substitutions[strcspn(substitutions, &original)] = newChar;
    }

    printf("Final Decrypted Message: ");
    decryptSubstitution(ciphertext, substitutions);

    return 0;
}

