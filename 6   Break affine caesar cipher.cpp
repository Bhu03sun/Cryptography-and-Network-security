#include <stdio.h>


void analyze_frequency(char *ciphertext, int *frequency) {
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        char letter = ciphertext[i];
        if (letter >= 'A' && letter <= 'Z') {
            frequency[letter - 'A']++;
        }
    }
}


void break_code(int *frequency) {
    
    int max_frequency = 0;
    int max_index = 0;
    for (int i = 0; i < 26; i++) {
        if (frequency[i] > max_frequency) {
            max_frequency = frequency[i];
            max_index = i;
        }
    }

   
    int a = (max_index - ('E' - 'A') + 26) % 26;

    
    int b = ('U' - 'A' - a + 26) % 26;

    printf("The key values a and b are: %d, %d\n", a, b);
}

int main() {
    char ciphertext[1000];
    int frequency[26] = {0};

    
    printf("Enter the ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    
    analyze_frequency(ciphertext, frequency);

    
    break_code(frequency);

    return 0;
}
