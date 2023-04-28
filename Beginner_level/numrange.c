#include <stdio.h>

int main() {
  int input;
  char choice;

  do {
    printf("Enter a number between 1 and 500\n");
    printf("\n");
    printf("->>");
    scanf("%d", &input);

    if (input >= 1 && input <= 100) {
      printf("Your number is between 1 and 100.\n");
    } else if (input >= 101 && input <= 200) {
      printf("Your number is between 101 and 200.\n");
    } else if (input >= 201 && input <= 300) {
      printf("Your number is between 201 and 300.\n");
    } else if (input >= 301 && input <= 400) {
      printf("Your number is between 301 and 400.\n");
    } else if (input >= 401 && input <= 500) {
      printf("Your number is between 401 and 500.\n");
    } else {
      printf("The number is out of stipulated Range\n");
    }

    printf("Do you want to continue (Y/N)?\n");
    printf("\n");
    printf("->>");
    scanf(" %c", &choice);
  } while (choice == 'Y' || choice == 'y');

  return 0;
}
