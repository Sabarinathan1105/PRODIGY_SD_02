#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    int secretNumber, userGuess, attempts = 0;
    char response[10];

    srand(time(NULL));
    secretNumber = rand() % 100 + 1;

    do {
        printf("Guess the Secret number between 1 and 1000: ");
        scanf("%d", &userGuess);
        attempts++;

        if (userGuess > secretNumber) {
            printf("Too high! Try again.\n");
        } else if (userGuess < secretNumber) {
            printf("Too low! Try again.\n");
        }

        if (userGuess != secretNumber) {
            printf("Would you like to try again? (Yes/No) ");
            scanf("%s", response);
        }

    } while ((strcasecmp(response, "yes") == 0 || strcasecmp(response, "y") == 0) && userGuess != secretNumber);

    if (userGuess == secretNumber) {
        printf("Congratulations! You guessed the secret number %d in %d attempts.\n", secretNumber, attempts);
    }

    return 0;
}
