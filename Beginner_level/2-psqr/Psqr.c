#include <stdio.h>

int main() {
  int num;
  printf("Enter a number: ");
  scanf("%d", &num);

  int i;
  for (i = 1; i * i <= num; i++) {
    if (num % i == 0 && num / i == i) {
      printf("%d is a perfect square.\n", num);
      return 0;
    }
  }

  printf("%d is not a perfect square.\n", num);
  return 0;
}
