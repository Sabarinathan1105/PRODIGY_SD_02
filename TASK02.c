#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int secretNumber, userGuess, attempts = 0;
    char response[10];

    srand(time(NULL));
    secretNumber = rand() % 100 + 1;

    while (1) {  // infinite loop — we'll break manually
        printf("Guess the Secret number between 1 and 100: ");
        scanf("%d", &userGuess);

        if (userGuess < 1 || userGuess > 100) {
            printf("Invalid input! Please enter a number between 1 and 100.\n");
            continue;
        }

        attempts++;

        if (userGuess > secretNumber) {
            printf("Too high! Try again.\n");
        } else if (userGuess < secretNumber) {
            printf("Too low! Try again.\n");
        } else {
            // Correct guess
            printf("Congratulations! You guessed the secret number %d in %d attempts.\n", secretNumber, attempts);
            break;
        }

        printf("Would you like to try again? (Yes/No) ");
        scanf("%s", response);

        if (strcasecmp(response, "no") == 0 || strcasecmp(response, "n") == 0) {
            printf("The secret number was: %d\n", secretNumber);
            break;
        }
    }

    return 0;
}
