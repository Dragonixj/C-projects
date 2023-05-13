#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));                // seed random number generator
  int number = rand() % 100 + 1; // generate random number between 1 and 100
  int guess;
  int attempts = 0;

  printf("Welcome to the guessing game!\n");
  printf("Can you guess the number I'm thinking of between 1->100\n");
  printf("You have 10 attempts\n");

  do {
    printf("Enter your guess: ");
    scanf("%d", &guess);
    attempts++;

    if (guess < number) {
      printf("Too low! Try again.\n");
    } else if (guess > number) {
      printf("Too high! Try again.\n");
    } else {
      printf("Congratulations! You guessed the number in %d attempts.\n",
             attempts);
      break;
    }

    if (attempts == 10) {
      printf("Sorry, you've used up all your attempts. The number was %d.\n",
             number);
      break;
    }

    if (attempts % 3 == 0) {
      printf("Here's a hint: The number is divisible by %d.\n", attempts);
    }

  } while (guess != number);

  return 0;
}
