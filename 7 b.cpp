#include <stdio.h>

void decryptSubstitution(char* ciphertext) {
    for (int i = 0; ciphertext[i] != '\0'; ++i) {
        // Perform substitution based on the assumption for 't' and 'h'
        if (ciphertext[i] == '3') {
            printf("t");
        } else if (ciphertext[i] == '4') {
            printf("h");
        } else {
            printf("%c", ciphertext[i]);
        }
    }
}

int main() {
    char ciphertext[] = "53‡‡†305))6*;4826)4‡.)4‡);806*;48†8¶60))85;;]8*;:‡*8†83 (88)5*†;46(;88*96*?;8)*‡(;485);5*†2:*‡(;4956*2(5*—4)8¶8* ;4069285);)6†8)4‡‡;1(‡9;48081;8:8‡1;48†85;4)485†528806*81 (‡9;48;(88;4(‡?34;48)4‡;161;:188;‡?";

    printf("Decrypted Message (assuming '3' corresponds to 't' and '4' corresponds to 'h'):\n");
    decryptSubstitution(ciphertext);

    return 0;
}

