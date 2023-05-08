#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_palindrome(char *string) {
  int length = strlen(string);

  for (int i = 0; i < length / 2; i++) {
    if (string[i] != string[length - i - 1]) {
      return false;
    }
  }

  return true;
}

int main() {
  char string[100];

  printf("Enter a word: ");
  fgets(string, 100, stdin);

  // Remove newline character from input string
  string[strcspn(string, "\n")] = '\0';

  if (is_palindrome(string)) {
    printf("\"%s\" is a palindrome.\n", string);
  } else {
    printf("\"%s\" is not a palindrome.\n", string);
  }

  return 0;
}
