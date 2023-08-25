#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretNumber, guess, attempts = 0;
    int lowerBound = 1, upperBound = 100;  // Set your desired number range

    // Seed the random number generator
    srand(time(NULL));

    // Generate a random number between lowerBound and upperBound
    secretNumber = (rand() % (upperBound - lowerBound + 1)) + lowerBound;

    printf("Welcome to the Guess the Number Game!\n");
    printf("I have selected a number between %d and %d. Try to guess it!\n", lowerBound, upperBound);

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess < secretNumber) {
            printf("Too low! Try again.\n");
        } else if (guess > secretNumber) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You guessed the number %d in %d attempts!\n", secretNumber, attempts);
        }
    } while (guess != secretNumber);

    return 0;
}
