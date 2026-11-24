#include <stdio.h>
#include <stdlib.h>

int main(void){
    int capacity = 2;
    int size = 0;

    int *nums = malloc(capacity * sizeof(int));
    if (nums == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 0;
    }

    printf("Enter integers (enter -1 to stop):\n");
    while (1) {
        int value;
        printf("Enter an integer: ");
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        if (size >= capacity) {
            capacity *= 2;
            int *temp = (int *)realloc(nums, capacity * sizeof(int));
            if (temp == NULL) {
                printf("Memory reallocation failed\n");
                return 0;
            }
            nums = temp;
            printf("Resized array to capacity %d\n", capacity);
        }
        nums[size] = value;
        size++;
    }
    printf("You saved %d integers:\n", size);
    for (int i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += nums[i]; // This will cause undefined behavior since nums is freed
    }
    printf("Sum of integers: %.2f\n", sum);

    float average = (size > 0) ? (sum / size) : 0;
    printf("Average of integers: %.2f\n", average);

    free(nums);
    nums = NULL; // Avoid dangling pointer

    return 0;
}