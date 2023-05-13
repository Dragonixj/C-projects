#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// declaring my operator functions
// addition part
int add(int a, int b) { return a + b; }
// subtraction part
int subtract(int a, int b) { return a - b; }
// multiplication part
int multiply(int a, int b) { return a * b; }
// division part
int divide(int a, int b) {
  if (b == 0) {
    printf("ERROR!!!\n Cant devide by zero");
    exit(EXIT_FAILURE);
  }
  return a / b;
}
// power part
int power(int a, int b) { return pow(a, b); }
// Modulo part
int modulo(int a, int b) { return a % b; }

// main part
int main() {
  int a, b, choice, result;

  // initialization stage
  printf("Enter two numbers: a b\n");
  scanf("%d %d", &a, &b);
  sleep(2);

  // choosing your operators
  printf("Enter an operator:\n");
  printf("Choose for 1-6\n");
  printf("1. Addition\t");
  printf("2. Subtraction\t");
  printf("3. Multiplication\n");
  printf("4. Division\t");
  printf("5. Power\t");
  printf("6. Modulo\n");
  scanf("%d", &choice);

  // operation stage

  switch (choice) {
  case 1:
    result = add(a, b);
    printf("%d + %d = %d\n", a, b, result);
    break;
  case 2:
    result = subtract(a, b);
    printf("%d - %d = %d\n", a, b, result);
    break;
  case 3:
    result = multiply(a, b);
    printf("%d * %d = %d\n", a, b, result);
    break;
  case 4:
    result = divide(a, b);
    printf("%d / %d = %d\n", a, b, result);
    break;
  case 5:
    result = power(a, b);
    printf("%d ^ %d = %d\n", a, b, result);
    break;
  case 6:
    result = modulo(a, b);
    printf("%d mod %d = %d\n", a, b, result);
    break;
  default:
    printf("ERROR: invalid choice\n");
    return 1;
  }

  return 0;
}
