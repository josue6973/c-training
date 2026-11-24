#include <stdio.h>

int main(void) {
    float subtotal, tax, tip, num_people, bill;

    printf("Enter subtotal: ");
    scanf("%f", &subtotal);

    printf("Enter percentage of tax amount: ");
    scanf("%f", &tax);

    printf("Enter percentage of tip amount: ");
    scanf("%f", &tip);

    printf("Enter number of people: ");
    scanf("%f", &num_people);

    bill = subtotal + (subtotal * tax / 100) + (subtotal * tip / 100);
    printf("Total bill: %.2f\n", bill);
    printf("Amount per person: %.2f\n", bill / num_people);
    printf("Tax amount: %.2f\n", subtotal * tax / 100);
    printf("Tip amount: %.2f\n", subtotal * tip / 100);
    return 0;
}