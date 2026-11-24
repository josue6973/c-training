#include <stdio.h>

int main(void) {
    char subject[20];
    int scores[10];
    int n_scores = 0;

    printf("Enter subject name: ");
    scanf("%s", subject);

    printf("Enter number of scores (max 10): ");
    scanf("%d", &n_scores);

    if(n_scores < 1 || n_scores > 10) {
        printf("Invalid number of scores. Please enter a number between 1 and 10.\n");
        return 0;
    }

    for(int i = 0; i < n_scores; i++) {
        printf("Enter score %d: ", i + 1);
        scanf("%d", &scores[i]);
    }

    int sum = 0;
    int max_score = scores[0];
    int min_score = scores[0];

    for(int i = 0; i < n_scores; i++) {
        sum += scores[i];
        if(scores[i] > max_score) {
            max_score = scores[i];
        }
        if(scores[i] < min_score) {
            min_score = scores[i];
        }
    }

    double average = (double)sum / n_scores;

    printf("Subject: %s\n", subject);
    printf("Average Score: %.2f\n", average);
    printf("Highest Score: %d\n", max_score);
    printf("Lowest Score: %d\n", min_score);

    int not_passed_count = 0, passed_count = 0;
    for(int i = 0; i < n_scores; i++) {
        if(scores[i] < 70) {
            not_passed_count++;
        } else {
            passed_count++;
        }
    }

    printf("Number of scores below 70: %d\n", not_passed_count);
    printf("Number of scores 70 or above: %d\n", passed_count);

    return 0;
}