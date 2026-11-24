#include <stdio.h>

int main(void){
    char name[20];\
    int age;

    printf("Enter your name: ");
    scanf("%19s", name); /*Read up to 19 characters to leave space for null terminator*/
    printf("Enter your age: ");
    scanf("%d", &age);

    FILE *file = fopen("user_data.txt", "a"); /*Open file in append mode*/
    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    fprintf(file, "Name: %s, Age: %d\n", name, age); /*Write to file*/
    fclose(file); /*Close file*/

    printf("Data saved to user_data.txt\n");

    file = fopen("user_data.txt", "r"); /*Open file in read mode*/
    if (file == NULL) {
        printf("Error opening file for lecture!\n");
        return 0;
    }

    char line[64];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line); /*Print each line*/
    }
    fclose(file); /*Close file*/
    printf("Done!\n");
    return 0;
}