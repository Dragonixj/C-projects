#include <stdio.h>
#include <unistd.h>

int main(void) {
  // initialize our variables variable
  float seconds;
  float hours;
  float mins;
  float remaining_seconds;

  // get user input of seconds
  printf("Enter the amount of seconds: ");
  scanf("%f", &seconds);
  sleep(1);

  //  conversion for hour portion
  hours = (int)(seconds / 3600);

  // conversion for minutes
  mins = (int)((seconds - (hours * 3600)) / 60);

  // remaining seconds->refer to the tiny amount left
  remaining_seconds = (seconds - (hours * 3600) - (mins * 60));

  // output of final answer
  printf("%0.0f seconds is the same as %0.0f hours, %0.0f minutes, and %0.0f "
         "seconds.",
         seconds, hours, mins, remaining_seconds);

  return 0;
}
