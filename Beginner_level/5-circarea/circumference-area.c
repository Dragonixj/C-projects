#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// define a value for PIE

int calculation();

int main(void) {
  // initialize variable
  float radius; // radius
  float C;      // for the circumference of a circle
  float area;   // for the area of the circle
  int ans;
  const float PI = 3.142;

  printf("\t\t\t\t*******************************************\n");
  printf("\t\t\t\tThis is a simple calculator\n");
  printf("\t\t\t\tthat solves for the\n");
  printf("\t\t\t\tcircumference and area of a circle\n");
  printf("\t\t\t\t*******************************************\n");

  printf("\n\n"); // new line

  sleep(1); // delays for 1 second

  // Startup stage
  printf("\t\t\t\tWhat will you like to calculate\n");
  printf("\t\t\t\t1.The area 2.The circumference\n");
  printf("\t\t\t\t->>");
  scanf("%d", &ans);

  sleep(1);

  printf("\n\t\t\t\tWhat is the radius of the circle\n");
  printf("\t\t\t\t->>");
  scanf("%f", &radius);

  // standard formula
  area = (PI * (radius * radius));
  C = (2 * (PI * radius));

  switch (ans) {
  case 1:
    printf("\n");
    sleep(1);
    printf("\n\t\t\t\tThe area of the circe is -> %f", area);
    break;
  case 2:
    printf("\n");
    printf("\n\t\t\t\tThe circumference of the circle -> %f", C);
    break;
  default:
    printf("\n");
    printf("\t\t\t\tInvalid response!!!");
  }
}
