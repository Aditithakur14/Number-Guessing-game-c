#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secretNumber, guess, attempts = 0;

    // Generate random number
    srand(time(0));
    secretNumber = rand() % 100 + 1;

    printf("🎯 NUMBER GUESSING GAME\n");
    printf("Guess a number between 1 and 100\n\n");

    do {
        printf("Enter your guess: ");

        // Input validation
        if (scanf("%d", &guess) != 1) {
            printf("❌ Invalid input! Please enter a number.\n");

            // Clear input buffer
            while (getchar() != '\n');
            continue;
        }

        // Range check
        if (guess < 1 || guess > 100) {
            printf("⚠ Please enter a number between 1 and 100.\n");
            continue;
        }

        attempts++;

        if (guess > secretNumber) {
            printf("Too high! 🔽 Try again.\n");
        } 
        else if (guess < secretNumber) {
            printf("Too low! 🔼 Try again.\n");
        } 
        else {
            printf("\n🎉 Correct! You guessed the number.\n");
            printf("🔢 Number: %d\n", secretNumber);
            printf("📊 Attempts: %d\n", attempts);
        }

    } while (guess != secretNumber);

    return 0;
}
