#include <stdio.h>

int main() {
  int range, num;

  printf("Enter the multiplication table number set  you want");
  scanf("%d", &num);

  printf("Enter the range of the multiplication table");
  scanf("%d", &range);

  // initiating the file name and writing content into it
  FILE *fptr;
  char *s = "table.txt";
  fptr = fopen(s, "w");

  for (int i = 1; i <= range; i++) {
    fprintf(fptr, "%d X %d = %d\n", num, i, num * i);
  }
  printf("\nMultiplication Table of %d generated successfully.\n", num);
  fclose(fptr);

  // printing out the content of the table.txt-> the multiplication table
  char line[1000];

  fopen(s, "r");

  if (fptr == NULL) {
    printf("Error occurred opening the file");
    return 1;
  }
  while (fgets(line, sizeof(line), fptr)) {
    printf("%s", line);
  }

  return 0;
}
