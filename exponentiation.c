#include <stdio.h>

int exponentiationIterative(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int exponentiationRecursive(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        return base * exponentiationRecursive(base, exponent - 1);
    }
}

int main (void) {
    int base, exponent, result;
    printf("Enter base: ");
    scanf("%d", &base);
    printf("Enter exponent: ");
    scanf("%d", &exponent);
    
    result = exponentiationIterative(base, exponent);
    printf("Result (Iterative): %d\n", result);
    
    result = exponentiationRecursive(base, exponent);
    printf("Result (Recursive): %d\n", result);
    
    return 0;
}