#include <stdio.h>
#include "mat_lib.h"

int main() {
    int x = 10;
    int y = 5;

    int sum = add(x, y);
    int difference = substract(x, y);

    printf("Version: %s\n", MAT_LIB_VERSION);
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);
    printf("Multiplication: %d\n", multiply(x, y));

    return 0;
}