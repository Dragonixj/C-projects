#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int choice, i, a, b;
  float x, y, result;
  printf("This is a Scientific Calculator\n");
  do {
    printf("\nSelect your operation(0 to exit):\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    printf("5. Square root\n6. X ^ Y\n7. X ^ 2\n8. X ^ 3\n");
    printf("9. 1 / X\n10. X ^ (1 / Y)\n11. X ^ (1 / 3)\n");
    printf("12. 10 ^ X\n13. X!\n14. Modulo\n15. log10(x)\n16. Modulus\n");
    printf("17. Sin(X)\n18. Cos(X)\n19. Tan(X)\n20. Cosec(X)\n");
    printf("21. Cot(X)\n22. Sec(X)\n");
    printf("Choice: ");
    scanf("%d", &choice);
    if (choice == 0) {
      exit(0);
    }
    switch (choice) {
    case 1:
      printf("Enter X: ");
      scanf("%f", &x);
      printf("\nEnter Y: ");
      scanf("%f", &y);
      result = x + y;
      printf("\nResult: %f", result);
      break;
    case 2:
      printf("Enter X: ");
      scanf("%f", &x);
      printf("\nEnter Y: ");
      scanf("%f", &y);
      result = x - y;
      printf("\nResult: %f", result);
      break;
    case 3:
      printf("Enter X: ");
      scanf("%f", &x);
      printf("\nEnter Y: ");
      scanf("%f", &y);
      result = x * y;
      printf("\nResult: %f", result);
      break;
    case 4:
      printf("Enter X: ");
      scanf("%f", &x);
      printf("\nEnter Y: ");
      scanf("%f", &y);
      if (y == 0) {
        printf("\nError: Division by zero!");
      } else {
        result = x / y;
        printf("\nResult: %f", result);
      }
      break;
    case 5:
      printf("Enter X: ");
      scanf("%f", &x);
      if (x < 0) {
        printf("\nError: Square root of negative number!");
      } else {
        result = sqrt(x);
        printf("\nResult: %f", result);
      }
      break;
    case 6:
      printf("Enter X: ");
      scanf("%f", &x);
      printf("\nEnter Y: ");
      scanf("%f", &y);
      result = pow(x, y);
      printf("\nResult:%f", result);
    }
  } while (choice);
}
