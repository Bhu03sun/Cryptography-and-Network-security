#include <stdio.h>
#include <stdint.h>

// Key permutation table
int keyPermutationTable[] = {
    57, 49, 41, 33, 25, 17, 9, 1,
    58, 50, 42, 34, 26, 18, 10, 2,
    59, 51, 43, 35, 27, 19, 11, 3,
    60, 52, 44, 36, 63, 55, 47, 39,
    31, 23, 15, 7, 62, 54, 46, 38,
    30, 22, 14, 6, 61, 53, 45, 37,
    29, 21, 13, 5, 28, 20, 12, 4
};

// Circular left shift schedule
int shiftSchedule[] = {
    1, 1, 2, 2, 2, 2, 2, 2,
    1, 2, 2, 2, 2, 2, 2, 1
};

// Key generation function
void generateSubkeys(uint64_t initialKey, uint64_t subkeys[16]) {
    // Perform initial permutation on the key
    uint64_t permutedKey = 0;
    for (int i = 0; i < 56; ++i) {
        permutedKey |= ((initialKey >> (64 - keyPermutationTable[i])) & 0x01) << (55 - i);
    }

    // Split the 56-bit key into two 28-bit halves
    uint32_t leftHalf = (uint32_t)(permutedKey >> 28) & 0x0FFFFFFF;
    uint32_t rightHalf = (uint32_t)(permutedKey & 0x0FFFFFFF);

    // Generate 16 subkeys
    for (int round = 0; round < 16; ++round) {
        // Perform circular left shifts based on the schedule
        leftHalf = ((leftHalf << shiftSchedule[round]) | (leftHalf >> (28 - shiftSchedule[round]))) & 0x0FFFFFFF;
        rightHalf = ((rightHalf << shiftSchedule[round]) | (rightHalf >> (28 - shiftSchedule[round]))) & 0x0FFFFFFF;

        // Combine the two halves and perform the subkey permutation
        uint64_t combinedHalf = ((uint64_t)leftHalf << 28) | rightHalf;
        subkeys[round] = 0;
        for (int i = 0; i < 48; ++i) {
            subkeys[round] |= ((combinedHalf >> (56 - keyPermutationTable[i])) & 0x01) << (47 - i);
        }
    }
}

int main() {
    // Example initial key
    uint64_t initialKey = 0x133457799BBCDFF1;

    // Array to store the 16 subkeys
    uint64_t subkeys[16];

    // Generate subkeys
    generateSubkeys(initialKey, subkeys);

    // Display the subkeys
    for (int i = 0; i < 16; ++i) {
        printf("Subkey %2d: %012llx\n", i + 1, subkeys[i]);
    }

    return 0;
}

