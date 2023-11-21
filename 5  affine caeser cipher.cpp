#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int isAllowed(int a) {
    return gcd(a, 26) == 1 ? 1 : 0;
}

int main() {
    printf("Values of a that are not allowed in the affine Caesar cipher:\n");

    for (int a = 1; a <= 25; a++) {
        if (!isAllowed(a))
            printf("%d ", a);
    }

    printf("\n");

    return 0;
} 
 

