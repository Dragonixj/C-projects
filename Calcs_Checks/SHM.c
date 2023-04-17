#include <math.h>
#include <stdio.h>

int main() {

  // declaring our variables
  float amplitude, frequency, time, displacement;

  printf("Enter amplitude: ");
  scanf("%f", &amplitude);

  printf("Enter frequency: ");
  scanf("%f", &frequency);

  printf("Enter time: ");
  scanf("%f", &time);

  displacement = amplitude * sin(2 * M_PI * frequency * time);

  printf("Displacement at time %.2f seconds = %.2f meters\n", time,
         displacement);

  return 0;
}
