#include <stdio.h>

int main(void) {
    int option, number;
    _Bool exit = 0;
    do{
        printf("Menu: \nSelect an option: \n");
        printf("1: Positive or Negative\n");
        printf("2: Series to N\n");
        printf("3: Exit\n");
        scanf("%d", &option);

        switch(option){
            case 1:
                printf("You selected Positive or Negative\n");
                printf("Enter a number: ");
                scanf("%d", &number);
                
                if (number > 0) {
                    printf("The number is positive.\n");
                } else if (number < 0) {
                    printf("The number is negative.\n");
                } else {
                    printf("The number is zero.\n");
                }
                break;
            case 2:
                printf("You selected Series to N\n");
                printf("Enter a number: ");
                scanf("%d", &number);
                printf("Series from 1 to %d:\n", number);
                for (int i = 1; i <= number; i++) {
                    printf("%d ", i);
                }
                printf("\n");
                break;
            case 3:
                printf("Exiting the program.\n");
                exit = 1;
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

    }while(exit == 0);

    return 0;
}
