#include <stdio.h>

void orderAsc(int *a, int *b) {
    if (a == NULL || b == NULL) {
        printf("Error: Null pointer provided.\n");
        return;
    }

    if(*a > *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

void stadistics(int x, int y, int *sumOut, int *productOut) {
    if (sumOut == NULL || productOut == NULL) {
        printf("Error: Null pointer provided.\n");
        return;
    }
    *sumOut = x + y;
    *productOut = x * y;
}

void minMax(int x, int y, int *minOut, int *maxOut) {
    if (minOut == NULL || maxOut == NULL) {
        printf("Error: Null pointer provided.\n");
        return;
    }
    if(x < y) {
        *minOut = x;
        *maxOut = y;
    } else {
        *minOut = y;
        *maxOut = x;
    }
}

int main(void) {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    printf("Original values: %d, %d\n", a, b);
    orderAsc(&a, &b);
    printf("Ordered values: %d, %d\n", a, b);

    int sum, product;
    stadistics(a, b, &sum, &product);
    printf("Sum: %d, Product: %d\n", sum, product);

    int min, max;
    minMax(a, b, &min, &max);
    printf("Min: %d, Max: %d\n", min, max);

    return 0;
}